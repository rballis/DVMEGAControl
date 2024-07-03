#include <string>

#pragma once
class SettingsData
{
public:
    SettingsData()
    {
        read();
    }

    SettingsData(std::string host, std::string user, std::string password, int port)
    {
        Host = host;
        User = user;
        Password = password;
        Port = port;
    }

    void setFactory(void);
    void read(void);
    void write(void);
    std::string Host = "";
    std::string User = "";
    std::string Password = "";
    int Port = 0;

private:
    const std::string Filename = ".\\DVMEGAControl.ini";
    const std::string ProWHost = "Host:";
    const std::string ProWUser = "User:";
    const std::string ProWPassword = "Password:";
    const std::string ProWPort = "Port:";
};

