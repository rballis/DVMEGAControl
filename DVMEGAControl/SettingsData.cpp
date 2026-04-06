#include "pch.h"
#include "SettingsData.h"
#include "CryptoConfig.h"
#include "CkCrypt2.h"
#include <fstream>
#include <stdexcept>
#include <cstring>

// Default constructor
SettingsData::SettingsData()
  : ProtokollHost()
  , Host()
  , WEBAdr()
  , Interval(0)
  , User()
  , Password()
  , Port(0)
{
    read();
}

// Parameterized constructor
SettingsData::SettingsData(const std::string& host, const std::string& user, 
                           const std::string& password, std::int32_t port)
  : ProtokollHost(FACTORY_PROTOKOLL_HOST)
  , Host(host)
  , WEBAdr(FACTORY_WEB_ADR)
  , Interval(FACTORY_INTERVAL)
  , User(user)
  , Password(password)
  , Port(port)
{
}

// Reset to factory defaults
void SettingsData::setFactory()
{
    ProtokollHost = FACTORY_PROTOKOLL_HOST;
    Host = FACTORY_HOST;
    WEBAdr = FACTORY_WEB_ADR;
    Interval = FACTORY_INTERVAL;
    User = FACTORY_USER;
    Password = FACTORY_PASSWORD;
    Port = FACTORY_PORT;
}

// Configure cryptography (DRY principle - eliminates duplication)
void SettingsData::configureCrypto(CkCrypt2& crypt)
{
    crypt.put_CryptAlgorithm(CRYPT_ALGORITHM);
    crypt.put_CipherMode(CRYPT_CIPHER);
    crypt.put_KeyLength(CRYPT_KEY_LENGTH);
    crypt.put_PaddingScheme(CRYPT_PADDING);
    crypt.put_EncodingMode(CRYPT_ENCODING);
    crypt.SetEncodedIV(CryptoConfig::CryptIvHex, CRYPT_ENCODING);
    crypt.SetEncodedKey(CryptoConfig::CryptKeyHex, CRYPT_ENCODING);
}

// Read settings from INI file
void SettingsData::read()
{
    std::ifstream input(FILENAME_INI);

    // Create INI with factory defaults if it doesn't exist
    if (!input.is_open())
    {
        setFactory();
        write();
        return;
    }

    // Setup encryption
    CkCrypt2 crypt;
    configureCrypto(crypt);

    // Parse INI file line by line
    std::string line;
    while (std::getline(input, line))  // FIX: Use getline() as condition, not eof()
    {
        // Skip empty lines
        if (line.empty()) 
            continue;

        // Helper lambda to extract value after key prefix
        auto extractValue = [&line](const char* key) -> std::string {
            const std::size_t keyLen = std::strlen(key);
            if (line.compare(0, keyLen, key) == 0)
                return line.substr(keyLen);
            return {};
        };

        // Parse each setting
        if (line.compare(0, std::strlen(KEY_PROTOKOLL_HOST), KEY_PROTOKOLL_HOST) == 0)
        {
            ProtokollHost = extractValue(KEY_PROTOKOLL_HOST);
        }
        else if (line.compare(0, std::strlen(KEY_HOST), KEY_HOST) == 0)
        {
            Host = extractValue(KEY_HOST);
        }
        else if (line.compare(0, std::strlen(KEY_WEB_ADR), KEY_WEB_ADR) == 0)
        {
            WEBAdr = extractValue(KEY_WEB_ADR);
        }
        else if (line.compare(0, std::strlen(KEY_INTERVAL), KEY_INTERVAL) == 0)
        {
            const std::string value = extractValue(KEY_INTERVAL);
            if (!value.empty())
            {
                try
                {
                    Interval = std::stoi(value);
                }
                catch (const std::exception&)
                {
                    // Fallback to factory default on parse error
                    Interval = FACTORY_INTERVAL;
                }
            }
        }
        else if (line.compare(0, std::strlen(KEY_USER), KEY_USER) == 0)
        {
            User = extractValue(KEY_USER);
        }
        else if (line.compare(0, std::strlen(KEY_PASSWORD), KEY_PASSWORD) == 0)
        {
            const std::string encryptedPwd = extractValue(KEY_PASSWORD);
            if (!encryptedPwd.empty())
            {
                try
                {
                    Password = crypt.decryptStringENC(encryptedPwd.c_str());
                }
                catch (...)
                {
                    // Fallback to factory default if decryption fails
                    Password = FACTORY_PASSWORD;
                }
            }
        }
        else if (line.compare(0, std::strlen(KEY_PORT), KEY_PORT) == 0)
        {
            const std::string value = extractValue(KEY_PORT);
            if (!value.empty())
            {
                try
                {
                    Port = std::stoi(value);
                }
                catch (const std::exception&)
                {
                    // Fallback to factory default on parse error
                    Port = FACTORY_PORT;
                }
            }
        }
    }

    input.close();
}

// Write settings to INI file
void SettingsData::write() const
{
    std::ofstream output(FILENAME_INI);
    
    if (!output.is_open())
    {
        throw std::runtime_error("Cannot open INI file for writing: " + std::string(FILENAME_INI));
    }

    // Setup encryption
    CkCrypt2 crypt;
    configureCrypto(crypt);

    // Write all settings (using << operator chaining for efficiency)
    output << KEY_PROTOKOLL_HOST << ProtokollHost << '\n'
           << KEY_HOST << Host << '\n'
           << KEY_WEB_ADR << WEBAdr << '\n'
           << KEY_INTERVAL << Interval << '\n'
           << KEY_USER << User << '\n'
           << KEY_PASSWORD << crypt.encryptStringENC(Password.c_str()) << '\n'
           << KEY_PORT << Port;

    // Verify write succeeded
    if (!output.good())
    {
        throw std::runtime_error("Failed to write to INI file: " + std::string(FILENAME_INI));
    }

    output.close();
}