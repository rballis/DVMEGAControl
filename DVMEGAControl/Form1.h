#pragma once
#include "SettingsData.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnReboot;
	protected:
	private: System::Windows::Forms::Button^ btnShutdown;
	private: System::Windows::Forms::Button^ btnBrowser;
	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::WebBrowser^ wbGatewayActivity;
	private: System::Windows::Forms::Timer^ tiGatewayActivity;
	private: System::ComponentModel::IContainer^ components;
    private: SettingsData* Sd = new SettingsData();

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		void btnReboot_Click(System::Object^ sender, System::EventArgs^ e);
		void btnShutdown_Click(System::Object^ sender, System::EventArgs^ e);
		void btnBrowser_Click(System::Object^ sender, System::EventArgs^ e);
		void btnSettings_Click(System::Object^ sender, System::EventArgs^ e);
		void tiGatewayActivity_Tick(System::Object^ sender, System::EventArgs^ e);
        void send2device(char* cmd, char* charset);

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnReboot = (gcnew System::Windows::Forms::Button());
			this->btnShutdown = (gcnew System::Windows::Forms::Button());
			this->btnBrowser = (gcnew System::Windows::Forms::Button());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->wbGatewayActivity = (gcnew System::Windows::Forms::WebBrowser());
			this->tiGatewayActivity = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btnReboot
			// 
			this->btnReboot->BackColor = System::Drawing::Color::Lime;
			this->btnReboot->Location = System::Drawing::Point(12, 12);
			this->btnReboot->Name = L"btnReboot";
			this->btnReboot->Size = System::Drawing::Size(75, 23);
			this->btnReboot->TabIndex = 0;
			this->btnReboot->Text = L"Reboot";
			this->btnReboot->UseVisualStyleBackColor = false;
			this->btnReboot->Click += gcnew System::EventHandler(this, &Form1::btnReboot_Click);
			// 
			// btnShutdown
			// 
			this->btnShutdown->BackColor = System::Drawing::Color::Red;
			this->btnShutdown->Location = System::Drawing::Point(93, 12);
			this->btnShutdown->Name = L"btnShutdown";
			this->btnShutdown->Size = System::Drawing::Size(75, 23);
			this->btnShutdown->TabIndex = 1;
			this->btnShutdown->Text = L"Shutdown";
			this->btnShutdown->UseVisualStyleBackColor = false;
			this->btnShutdown->Click += gcnew System::EventHandler(this, &Form1::btnShutdown_Click);
			// 
			// btnBrowser
			// 
			this->btnBrowser->BackColor = System::Drawing::Color::Cyan;
			this->btnBrowser->Location = System::Drawing::Point(174, 12);
			this->btnBrowser->Name = L"btnBrowser";
			this->btnBrowser->Size = System::Drawing::Size(75, 23);
			this->btnBrowser->TabIndex = 2;
			this->btnBrowser->Text = L"Browser";
			this->btnBrowser->UseVisualStyleBackColor = false;
			this->btnBrowser->Click += gcnew System::EventHandler(this, &Form1::btnBrowser_Click);
			// 
			// btnSettings
			// 
			this->btnSettings->Location = System::Drawing::Point(1207, 12);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(75, 23);
			this->btnSettings->TabIndex = 3;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseVisualStyleBackColor = true;
			this->btnSettings->Click += gcnew System::EventHandler(this, &Form1::btnSettings_Click);
			// 
			// wbGatewayActivity
			// 
			this->wbGatewayActivity->Location = System::Drawing::Point(13, 41);
			this->wbGatewayActivity->MinimumSize = System::Drawing::Size(20, 20);
			this->wbGatewayActivity->Name = L"wbGatewayActivity";
			this->wbGatewayActivity->Size = System::Drawing::Size(1269, 576);
			this->wbGatewayActivity->TabIndex = 5;
			this->wbGatewayActivity->Url = (gcnew System::Uri(L"", System::UriKind::Relative));
			// 
			// tiGatewayActivity
			// 
			this->tiGatewayActivity->Enabled = true;
			this->tiGatewayActivity->Interval = 1000;
			this->tiGatewayActivity->Tick += gcnew System::EventHandler(this, &Form1::tiGatewayActivity_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1294, 629);
			this->Controls->Add(this->wbGatewayActivity);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnBrowser);
			this->Controls->Add(this->btnShutdown);
			this->Controls->Add(this->btnReboot);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->Text = L"DVMEGAControl";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
