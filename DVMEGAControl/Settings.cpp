#include "pch.h"
#include "Settings.h"
#include <msclr/marshal_cppstd.h>

System::Void DVMEGAControl::Settings::btTest_Click(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void DVMEGAControl::Settings::btWrite_Click(System::Object^ sender, System::EventArgs^ e)
{
    Sd->Host = msclr::interop::marshal_as< std::string >(tbHost->Text);
    Sd->User = msclr::interop::marshal_as< std::string >(tbUser->Text);
    Sd->Password = msclr::interop::marshal_as< std::string >(tbPassword->Text);
    Sd->Port = std::stoi(msclr::interop::marshal_as< std::string >(tbPort->Text));

    Sd->write();
    DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Close();
}