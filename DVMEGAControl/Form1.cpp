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
            throw std::invalid_argument(ssh.lastErrorText());

        // Authenticate using login/password:
        if (!ssh.AuthenticatePw(Sd->User.c_str(), Sd->Password.c_str()))
        {
            throw std::invalid_argument(ssh.lastErrorText());
        }
        else
        {
            const char* strOutput = ssh.quickCommand(command, charset);

            if (!ssh.get_LastMethodSuccess())
                throw std::invalid_argument(ssh.lastErrorText());

            MessageBox::Show("Command send successfully to the device", "Command send", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (const std::exception& e)
    {
        MessageBox::Show(gcnew String(e.what()), "Command send", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void CppCLRWinFormsProject::Form1::btnReboot_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Are your sure you want to reboot this device?", "Reboot", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
        send2device("sudo reboot", "ansi");
    }
}

void CppCLRWinFormsProject::Form1::btnShutdown_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Are your sure you want to shut down this device?\nNote: only a disconnected power can restart this device!", "Shutdown", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
    {
        send2device("sudo shutdown -h now", "ansi");
    }
}

void CppCLRWinFormsProject::Form1::btnBrowser_Click(System::Object^ sender, System::EventArgs^ e)
{
    const std::string scheme(Sd->ProtokollHost);
    const std::string hostname = Sd->Host;
    const std::string adress("/");

    System::Diagnostics::Process::Start(gcnew String((scheme + hostname + adress).c_str()));
}

void CppCLRWinFormsProject::Form1::btnSettings_Click(System::Object^ sender, System::EventArgs^ e)
{
    DVMEGAControl::Settings^ settings = gcnew(DVMEGAControl::Settings);

    _ASSERT(settings);
    tiGatewayActivity->Enabled = false;

    settings->SetSettings(Sd);
    if (settings->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        wbGatewayActivity->Navigate("about:blank");

    if ((Sd->Interval > 0) &&
        (Sd->WEBAdr.length() > 0))
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
    }
    else
    {
        const std::string scheme(Sd->ProtokollHost);
        const std::string hostname = Sd->Host;
        const std::string adress(Sd->WEBAdr);

        tiGatewayActivity->Interval = Sd->Interval * 1000;

        try
        {
            wbGatewayActivity->Refresh();
            wbGatewayActivity->Url = gcnew System::Uri(gcnew String((scheme + hostname + adress).c_str()), System::UriKind::Absolute);
        }
        catch (UriFormatException^ uex)
        {
            tiGatewayActivity->Enabled = false;
            MessageBox::Show(gcnew String(uex->ToString()), "WEB Browser", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ e)
        {
            tiGatewayActivity->Enabled = false;
            MessageBox::Show(gcnew String(e->ToString()), "WEB Browser", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}