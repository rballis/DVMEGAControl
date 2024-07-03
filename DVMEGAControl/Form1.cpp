#include "pch.h"
#include "Form1.h"
#include "Settings.h"

void CppCLRWinFormsProject::Form1::btnReboot_Click(System::Object^ sender, System::EventArgs^ e)
{

}

void CppCLRWinFormsProject::Form1::btnShutdown_Click(System::Object^ sender, System::EventArgs^ e)
{

}

void CppCLRWinFormsProject::Form1::btnBrowser_Click(System::Object^ sender, System::EventArgs^ e)
{
    const std::string scheme("http://");
    const std::string hostname = Sd->Host;
    const std::string adress("/");

    System::Diagnostics::Process::Start(gcnew String((scheme + hostname + adress).c_str()));
}

void CppCLRWinFormsProject::Form1::btnSettings_Click(System::Object^ sender, System::EventArgs^ e)
{
    DVMEGAControl::Settings^ settings = gcnew(DVMEGAControl::Settings);

    tiGatewayActivity->Enabled = false;

    settings->SetSettings(Sd);
    if (settings->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        wbGatewayActivity->Navigate("about:blank");

    tiGatewayActivity->Enabled = true;
}

void CppCLRWinFormsProject::Form1::tiGatewayActivity_Tick(System::Object^ sender, System::EventArgs^ e)
{
    const std::string scheme("http://");
    const std::string hostname = Sd->Host;
    const std::string adress("/mmdvmhost/lh.php#");

    wbGatewayActivity->Refresh();
    wbGatewayActivity->Url = gcnew System::Uri(gcnew String((scheme + hostname + adress).c_str()), System::UriKind::Absolute);
}