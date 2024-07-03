#include "pch.h"
#include "SettingsData.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void SettingsData::setFactory()
{
    Host = "pi-star";
    User = "pi-star";
    Password = "raspberry";
    Port = 22;
}

void SettingsData::read()
{
    ifstream input(Filename);

    if (input.is_open())
    {
        while (!input.eof())
        {
            std::string line;
            getline(input, line);

            if (line.substr(0, ProWHost.length()) == ProWHost)
                Host = line.substr(ProWHost.length(), line.length() - ProWHost.length());
            else if (line.substr(0, ProWUser.length()) == ProWUser)
                User = line.substr(ProWUser.length(), line.length() - ProWUser.length());
            else if (line.substr(0, ProWPassword.length()) == ProWPassword)
                Password = line.substr(ProWPassword.length(), line.length() - ProWPassword.length());
            else if (line.substr(0, ProWPort.length()) == ProWPort)
                Port = std::stoi(line.substr(ProWPort.length(), line.length() - ProWPort.length()));
        }
    }
    else
    {
        setFactory();
        write();
    }
}

void SettingsData::write()
{
    ofstream output(Filename);

    output << ProWHost + Host + "\n";
    output << ProWUser + User + "\n";
    output << ProWPassword + Password + "\n";
    output << ProWPort + std::to_string(Port);

    output.close();
}