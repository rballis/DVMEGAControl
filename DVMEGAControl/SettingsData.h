#pragma once

#include <string>
#include <cstdint>

// Forward declaration
class CkCrypt2;

/// <summary>
/// Manages application settings with encrypted password storage.
/// Settings are persisted to DVMEGAControl.ini file using AES-256-CBC encryption.
/// </summary>
class SettingsData
{
public:
    // Constructors
    SettingsData();
    SettingsData(const std::string& host, const std::string& user, 
                 const std::string& password, std::int32_t port);

    // Destructor
    ~SettingsData() = default;

    // Delete copy operations (safer for C++/CLI interop)
    SettingsData(const SettingsData&) = delete;
    SettingsData& operator=(const SettingsData&) = delete;

    // Default move operations
    SettingsData(SettingsData&&) noexcept = default;
    SettingsData& operator=(SettingsData&&) noexcept = default;

    // File I/O operations
    void read();
    void write() const;

    // Public data members (required for C++/CLI Forms direct access)
    std::string ProtokollHost;
    std::string Host;
    std::string WEBAdr;
    std::int32_t Interval;
    std::string User;
    std::string Password;
    std::int32_t Port;

private:
    // Helper methods
    void setFactory();
    static void configureCrypto(CkCrypt2& crypt);

    // INI file configuration
    static constexpr const char* FILENAME_INI = ".\\DVMEGAControl.ini";
    
    // INI file keys
    static constexpr const char* KEY_PROTOKOLL_HOST = "ProtokollHost:";
    static constexpr const char* KEY_HOST = "Host:";
    static constexpr const char* KEY_WEB_ADR = "WEBAdr:";
    static constexpr const char* KEY_INTERVAL = "Interval:";
    static constexpr const char* KEY_USER = "User:";
    static constexpr const char* KEY_PASSWORD = "Password:";
    static constexpr const char* KEY_PORT = "Port:";
    
    // Factory default values
    static constexpr const char* FACTORY_PROTOKOLL_HOST = "http://";
    static constexpr const char* FACTORY_HOST = "pi-star";
    static constexpr const char* FACTORY_WEB_ADR = "/mmdvmhost/lh.php#";
    static constexpr std::int32_t FACTORY_INTERVAL = 1;
    static constexpr const char* FACTORY_USER = "pi-star";
    static constexpr const char* FACTORY_PASSWORD = "raspberry";
    static constexpr std::int32_t FACTORY_PORT = 22;

    // AES-256-CBC cryptography configuration
    static constexpr const char* CRYPT_ALGORITHM = "aes";
    static constexpr const char* CRYPT_CIPHER = "cbc";
    static constexpr std::int32_t CRYPT_KEY_LENGTH = 256;
    static constexpr std::int32_t CRYPT_PADDING = 0;
    static constexpr const char* CRYPT_ENCODING = "hex";
};

