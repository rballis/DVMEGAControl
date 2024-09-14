#include "pch.h"
#include "SettingsData.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "CkCrypt2.h"
using namespace std;

void SettingsData::setFactory()
{
    ProtokollHost = FactoryProtokollHost;
    Host = FactoryHost;
    WEBAdr = FactoryWEBAdr;
    Interval = FactroryIntrval;
    User = FactoryUser;
    Password = FactoryPassword;
    Port = FactoryPort;
}

void SettingsData::read()
{
    ifstream input(FilenameINI);

    if (input.is_open())
    {
        CkCrypt2 crypt;

        crypt.put_CryptAlgorithm(CryptAlgorithm);
        crypt.put_CipherMode(CryptCipher);
        crypt.put_KeyLength(CryptKeyLength);
        crypt.put_PaddingScheme(CryptPadding);
        crypt.put_EncodingMode(CryptEncod);
        crypt.SetEncodedIV(CryptIvHex, CryptEncod);
        crypt.SetEncodedKey(CryptKeyHex, CryptEncod);

        while (!input.eof())
        {
            string line;
            getline(input, line);

            if (line.substr(0, ProWProtokollHost.length()) == ProWProtokollHost)
                ProtokollHost = line.substr(ProWProtokollHost.length(), line.length() - ProWProtokollHost.length());
            else if (line.substr(0, ProWHost.length()) == ProWHost)
                Host = line.substr(ProWHost.length(), line.length() - ProWHost.length());
            else if (line.substr(0, ProWWEBAdr.length()) == ProWWEBAdr)
                WEBAdr = line.substr(ProWWEBAdr.length(), line.length() - ProWWEBAdr.length());
            else if (line.substr(0, ProwInterval.length()) == ProwInterval)
                Interval = stoi(line.substr(ProwInterval.length(), line.length() - ProwInterval.length()));
            else if (line.substr(0, ProWUser.length()) == ProWUser)
                User = line.substr(ProWUser.length(), line.length() - ProWUser.length());
            else if (line.substr(0, ProWPassword.length()) == ProWPassword)
                Password = crypt.decryptStringENC((line.substr(ProWPassword.length(), line.length() - ProWPassword.length()).c_str()));
            else if (line.substr(0, ProWPort.length()) == ProWPort)
                Port = stoi(line.substr(ProWPort.length(), line.length() - ProWPort.length()));
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
    ofstream output(FilenameINI);
    CkCrypt2 crypt;

    crypt.put_CryptAlgorithm(CryptAlgorithm);
    crypt.put_CipherMode(CryptCipher);
    crypt.put_KeyLength(CryptKeyLength);
    crypt.put_PaddingScheme(CryptPadding);
    crypt.put_EncodingMode(CryptEncod);
    crypt.SetEncodedIV(CryptIvHex, CryptEncod);
    crypt.SetEncodedKey(CryptKeyHex, CryptEncod);

    output << ProWProtokollHost + ProtokollHost + "\n";
    output << ProWHost + Host + "\n";
    output << ProWWEBAdr + WEBAdr + "\n";
    output << ProwInterval + to_string(Interval) + "\n";
    output << ProWUser + User + "\n";
    output << ProWPassword + crypt.encryptStringENC(Password.c_str()) + "\n";
    output << ProWPort + to_string(Port);

    output.close();
}