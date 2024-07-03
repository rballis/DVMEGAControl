#include "SettingsData.h"
#pragma once

namespace DVMEGAControl {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

        void SetSettings(SettingsData* sd)
        {
            Sd = sd;

            tbHost->Text = gcnew String(sd->Host.c_str());
            tbUser->Text = gcnew String(sd->User.c_str());
            tbPassword->Text = gcnew String(sd->Password.c_str());
            tbPort->Text = gcnew String(std::to_string(sd->Port).c_str());
        }

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnTest;
	protected:

    protected:

    protected:
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ tbPort;
	private: System::Windows::Forms::Button^ btnWrite;

	private: System::Windows::Forms::Button^ btnCanscel;

    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ tbHost;
    private: System::Windows::Forms::TextBox^ tbUser;
    private: System::Windows::Forms::TextBox^ tbPassword;

	private:
        SettingsData* Sd;
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
        System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnWrite_Click(System::Object^ sender, System::EventArgs^ e);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPort = (gcnew System::Windows::Forms::TextBox());
			this->btnWrite = (gcnew System::Windows::Forms::Button());
			this->btnCanscel = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbHost = (gcnew System::Windows::Forms::TextBox());
			this->tbUser = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(93, 84);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(75, 23);
			this->btnTest->TabIndex = 17;
			this->btnTest->Text = L"Test con.";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Settings::btnTest_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(192, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Port:";
			// 
			// tbPort
			// 
			this->tbPort->Location = System::Drawing::Point(227, 6);
			this->tbPort->Name = L"tbPort";
			this->tbPort->Size = System::Drawing::Size(21, 20);
			this->tbPort->TabIndex = 12;
			// 
			// btnWrite
			// 
			this->btnWrite->Location = System::Drawing::Point(174, 84);
			this->btnWrite->Name = L"btnWrite";
			this->btnWrite->Size = System::Drawing::Size(75, 23);
			this->btnWrite->TabIndex = 19;
			this->btnWrite->Text = L"Write";
			this->btnWrite->UseVisualStyleBackColor = true;
			this->btnWrite->Click += gcnew System::EventHandler(this, &Settings::btnWrite_Click);
			// 
			// btnCanscel
			// 
			this->btnCanscel->Location = System::Drawing::Point(12, 84);
			this->btnCanscel->Name = L"btnCanscel";
			this->btnCanscel->Size = System::Drawing::Size(75, 23);
			this->btnCanscel->TabIndex = 15;
			this->btnCanscel->Text = L"Cancel";
			this->btnCanscel->UseVisualStyleBackColor = true;
			this->btnCanscel->Click += gcnew System::EventHandler(this, &Settings::btnCanscel_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Password:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Host:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"User:";
			// 
			// tbHost
			// 
			this->tbHost->Location = System::Drawing::Point(74, 6);
			this->tbHost->Name = L"tbHost";
			this->tbHost->Size = System::Drawing::Size(112, 20);
			this->tbHost->TabIndex = 11;
			// 
			// tbUser
			// 
			this->tbUser->Location = System::Drawing::Point(74, 32);
			this->tbUser->Name = L"tbUser";
			this->tbUser->Size = System::Drawing::Size(174, 20);
			this->tbUser->TabIndex = 13;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(74, 58);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(174, 20);
			this->tbPassword->TabIndex = 14;
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 114);
			this->Controls->Add(this->btnTest);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbPort);
			this->Controls->Add(this->btnWrite);
			this->Controls->Add(this->btnCanscel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbHost);
			this->Controls->Add(this->tbUser);
			this->Controls->Add(this->tbPassword);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
        private: System::Void btnCanscel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}
