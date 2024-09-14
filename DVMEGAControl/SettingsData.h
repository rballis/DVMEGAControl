#include <string>

#pragma once
class SettingsData
{
public:
    SettingsData()
    {
        read();
    }

    SettingsData(std::string host, std::string user, std::string password, std::int32_t port)
    {
        Host = host;
        User = user;
        Password = password;
        Port = port;
    }

    void read(void);
    void write(void);
    std::string ProtokollHost = "";
    std::string Host = "";
    std::string WEBAdr = "";
    std::int32_t Interval = 0;
    std::string User = "";
    std::string Password = "";
    std::int32_t Port = 0;

private:
    void setFactory(void);
    const std::string FilenameINI = ".\\DVMEGAControl.ini";
    const std::string ProWProtokollHost = "ProtokollHost:";
    const std::string ProWHost = "Host:";
    const std::string ProWWEBAdr = "WEBAdr:";
    const std::string ProwInterval = "Interval:";
    const std::string ProWUser = "User:";
    const std::string ProWPassword = "Password:";
    const std::string ProWPort = "Port:";
    const std::string FactoryProtokollHost = "http://";
    const std::string FactoryHost = "pi-star";
    const std::string FactoryWEBAdr = "/mmdvmhost/lh.php#";
    const std::int32_t FactroryIntrval = 1;
    const std::string FactoryUser = "pi-star";
    const std::string FactoryPassword = "raspberry";
    const std::int32_t FactoryPort = 22;

    // AES is also known as Rijndael.		
    const char* CryptAlgorithm = "aes";

    // CipherMode may be "ecb", "cbc", "ofb", "cfb", "gcm", etc.
    // Note: Check the online reference documentation to see the Chilkat versions
    // when certain cipher modes were introduced.
    const char* CryptCipher = "cbc";

    // KeyLength may be 128, 192, 256
    const int CryptKeyLength = 256;

    // The padding scheme determines the contents of the bytes
    // that are added to pad the result to a multiple of the
    // encryption algorithm's block size.  AES has a block
    // size of 16 bytes, so encrypted output is always
    // a multiple of 16.
    const int CryptPadding = 0;

    // EncodingMode specifies the encoding of the output for
    // encryption, and the input for decryption.
    // It may be "hex", "url", "base64", or "quoted-printable".
    const char* CryptEncod = "hex";

    // An initialization vector is required if using CBC mode.
    // ECB mode does not use an IV.
    // The length of the IV is equal to the algorithm's block size.
    // It is NOT equal to the length of the key.
    const char* CryptIvHex = "000102030405069581413A0B0C0D0E0F";

    // The secret key must equal the size of the key.  For
    // 256-bit encryption, the binary secret key is 32 bytes.
    // For 128-bit encryption, the binary secret key is 16 bytes.
    const char* CryptKeyHex = "000102030405060708090A0B9581413F101112131415161718191A1B1C1D1E1F";
};

