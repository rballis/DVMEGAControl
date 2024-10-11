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
            tbWEBAdr->Text = gcnew String(sd->WEBAdr.c_str());
            tbInterval->Text = gcnew String(std::to_string(sd->Interval).c_str());
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
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbWEBAdr;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbInterval;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbWEBAdr = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbInterval = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(147, 72);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(95, 23);
			this->btnTest->TabIndex = 17;
			this->btnTest->Text = L"Test connection";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Settings::btnTest_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(186, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Port:";
			// 
			// tbPort
			// 
			this->tbPort->Location = System::Drawing::Point(221, 20);
			this->tbPort->MaxLength = 2;
			this->tbPort->Name = L"tbPort";
			this->tbPort->Size = System::Drawing::Size(21, 20);
			this->tbPort->TabIndex = 12;
			// 
			// btnWrite
			// 
			this->btnWrite->Location = System::Drawing::Point(186, 192);
			this->btnWrite->Name = L"btnWrite";
			this->btnWrite->Size = System::Drawing::Size(75, 23);
			this->btnWrite->TabIndex = 19;
			this->btnWrite->Text = L"Write";
			this->btnWrite->UseVisualStyleBackColor = true;
			this->btnWrite->Click += gcnew System::EventHandler(this, &Settings::btnWrite_Click);
			// 
			// btnCanscel
			// 
			this->btnCanscel->Location = System::Drawing::Point(9, 192);
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
			this->label3->Location = System::Drawing::Point(6, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Password:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Host:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"User:";
			// 
			// tbHost
			// 
			this->tbHost->Location = System::Drawing::Point(53, 6);
			this->tbHost->Name = L"tbHost";
			this->tbHost->Size = System::Drawing::Size(208, 20);
			this->tbHost->TabIndex = 11;
			// 
			// tbUser
			// 
			this->tbUser->Location = System::Drawing::Point(68, 20);
			this->tbUser->Name = L"tbUser";
			this->tbUser->Size = System::Drawing::Size(112, 20);
			this->tbUser->TabIndex = 13;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(68, 46);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(174, 20);
			this->tbPassword->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"URL:";
			// 
			// tbWEBAdr
			// 
			this->tbWEBAdr->Location = System::Drawing::Point(44, 19);
			this->tbWEBAdr->Name = L"tbWEBAdr";
			this->tbWEBAdr->Size = System::Drawing::Size(136, 20);
			this->tbWEBAdr->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(186, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Inter:";
			// 
			// tbInterval
			// 
			this->tbInterval->Location = System::Drawing::Point(221, 19);
			this->tbInterval->MaxLength = 2;
			this->tbInterval->Name = L"tbInterval";
			this->tbInterval->Size = System::Drawing::Size(21, 20);
			this->tbInterval->TabIndex = 24;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbWEBAdr);
			this->groupBox1->Controls->Add(this->tbInterval);
			this->groupBox1->Location = System::Drawing::Point(9, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(252, 45);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"WEB Browser";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->tbPassword);
			this->groupBox2->Controls->Add(this->btnTest);
			this->groupBox2->Controls->Add(this->tbUser);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->tbPort);
			this->groupBox2->Location = System::Drawing::Point(9, 83);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(252, 103);
			this->groupBox2->TabIndex = 27;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Send commands";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(271, 221);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnWrite);
			this->Controls->Add(this->btnCanscel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbHost);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
