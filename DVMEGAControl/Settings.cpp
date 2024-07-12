#include "pch.h"
#include "Settings.h"
#include <msclr/marshal_cppstd.h>
#include "CkSsh.h"
#include <stdexcept>

using namespace msclr::interop;

System::Void DVMEGAControl::Settings::btnTest_Click(System::Object^ sender, System::EventArgs^ e)
{
    CkSsh ssh;

    try
    {
        if (!ssh.Connect(marshal_as<std::string>(tbHost->Text).c_str(), std::stoi(marshal_as<std::string>(tbPort->Text))))
            throw std::invalid_argument(ssh.lastErrorText());

        // Authenticate using login/password:
        if (!ssh.AuthenticatePw(marshal_as<std::string>(tbUser->Text).c_str(), marshal_as<std::string>(tbPassword->Text).c_str()))
            throw std::invalid_argument(ssh.lastErrorText());

        MessageBox::Show("Connection test successfully to the device", "Connection test", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);

    }
    catch (const std::exception& e)
    {
        MessageBox::Show(gcnew String(e.what()), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
    }
}

System::Void DVMEGAControl::Settings::btnWrite_Click(System::Object^ sender, System::EventArgs^ e)
{
    Sd->Host = marshal_as<std::string>(tbHost->Text);
    Sd->User = marshal_as<std::string>(tbUser->Text);
    Sd->Password = marshal_as<std::string>(tbPassword->Text);
    Sd->Port = std::stoi(marshal_as<std::string>(tbPort->Text));

    Sd->write();
    DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Close();
}