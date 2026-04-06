#include "pch.h"
#include "Form1.h"
#include "CkSsh.h"
#include "Settings.h"
#include <stdexcept>

using namespace System::Windows::Forms;

void CppCLRWinFormsProject::Form1::send2device(char* command, char* charset)
{
    try
    {
        CkSsh ssh;

        if (!ssh.Connect(Sd->Host.c_str(), Sd->Port))
            throw std::runtime_error(ssh.lastErrorText());

        if (!ssh.AuthenticatePw(Sd->User.c_str(), Sd->Password.c_str()))
            throw std::runtime_error(ssh.lastErrorText());

        const char* strOutput = ssh.quickCommand(command, charset);

        if (!ssh.get_LastMethodSuccess())
            throw std::runtime_error(ssh.lastErrorText());

        MessageBox::Show("Command sent successfully to the device", 
                       "Command send", 
                       MessageBoxButtons::OK, 
                       MessageBoxIcon::Information);
    }
    catch (const std::exception& e)
    {
        MessageBox::Show(gcnew String(e.what()), 
                       "Command send", 
                       MessageBoxButtons::OK, 
                       MessageBoxIcon::Error);
    }
}

void CppCLRWinFormsProject::Form1::btnReboot_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Are you sure you want to reboot this device?", 
                        "Reboot", 
                        MessageBoxButtons::YesNo, 
                        MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
        send2device("sudo reboot", "ansi");
    }
}

void CppCLRWinFormsProject::Form1::btnShutdown_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Are you sure you want to shut down this device?\nNote: only disconnecting power can restart this device!", 
                        "Shutdown", 
                        MessageBoxButtons::YesNo, 
                        MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
        send2device("sudo shutdown -h now", "ansi");
    }
}

void CppCLRWinFormsProject::Form1::btnBrowser_Click(System::Object^ sender, System::EventArgs^ e)
{
    const std::string url = Sd->ProtokollHost + Sd->Host + "/";
    System::Diagnostics::Process::Start(gcnew String(url.c_str()));
}

void CppCLRWinFormsProject::Form1::btnSettings_Click(System::Object^ sender, System::EventArgs^ e)
{
    DVMEGAControl::Settings^ settings = gcnew DVMEGAControl::Settings();

    tiGatewayActivity->Enabled = false;

    settings->SetSettings(Sd);
    
    if (settings->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        wbGatewayActivity->Navigate("about:blank");
    }

    if (Sd->Interval > 0 && !Sd->WEBAdr.empty())
    {
        tiGatewayActivity->Enabled = true;
        tiGatewayActivity->Interval = Sd->Interval * 1000;
    }
}

void CppCLRWinFormsProject::Form1::tiGatewayActivity_Tick(System::Object^ sender, System::EventArgs^ e)
{
    if (Sd->Interval == 0)
    {
        tiGatewayActivity->Enabled = false;
        return;
    }

    try
    {
        const std::string url = Sd->ProtokollHost + Sd->Host + Sd->WEBAdr;
        tiGatewayActivity->Interval = Sd->Interval * 1000;

        wbGatewayActivity->Refresh();
        wbGatewayActivity->Url = gcnew System::Uri(gcnew String(url.c_str()), System::UriKind::Absolute);
    }
    catch (System::UriFormatException^ uex)
    {
        tiGatewayActivity->Enabled = false;
        MessageBox::Show(uex->Message, 
                       "WEB Browser", 
                       MessageBoxButtons::OK, 
                       MessageBoxIcon::Error);
    }
    catch (System::Exception^ ex)
    {
        tiGatewayActivity->Enabled = false;
        MessageBox::Show(ex->Message, 
                       "WEB Browser", 
                       MessageBoxButtons::OK, 
                       MessageBoxIcon::Error);
    }
}