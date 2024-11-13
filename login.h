#pragma once

namespace ICPFinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();

		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ emailTextBox;
		System::Windows::Forms::TextBox^ passwordTextBox;
		System::Windows::Forms::Button^ loginButton;
		System::Windows::Forms::LinkLabel^ forgotPasswordLink;

	public:
		LoginForm(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));

			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->forgotPasswordLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();

			// Panel
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(300, 450);
			this->panel1->TabIndex = 0;

			// PictureBox
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(50, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;

			// Label1
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(350, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Login";

			// EmailTextBox
			this->emailTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailTextBox->Location = System::Drawing::Point(350, 120);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(300, 32);
			this->emailTextBox->TabIndex = 2;
			this->emailTextBox->Text = L"Enter your email";

			// Label2
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(350, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 27);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Email";

			// PasswordTextBox
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->Location = System::Drawing::Point(350, 190);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(300, 32);
			this->passwordTextBox->TabIndex = 4;
			this->passwordTextBox->Text = L"Enter your password";
			this->passwordTextBox->UseSystemPasswordChar = true;

			// Label3
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(350, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 27);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";

			// LoginButton
			this->loginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginButton->ForeColor = System::Drawing::Color::White;
			this->loginButton->Location = System::Drawing::Point(350, 250);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(120, 40);
			this->loginButton->TabIndex = 6;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = false;

			// ForgotPasswordLink
			this->forgotPasswordLink->AutoSize = true;
			this->forgotPasswordLink->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->forgotPasswordLink->Location = System::Drawing::Point(480, 260);
			this->forgotPasswordLink->Name = L"forgotPasswordLink";
			this->forgotPasswordLink->Size = System::Drawing::Size(137, 21);
			this->forgotPasswordLink->TabIndex = 7;
			this->forgotPasswordLink->TabStop = true;
			this->forgotPasswordLink->Text = L"Forgot password?";

			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 450);
			this->Controls->Add(this->forgotPasswordLink);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"LoginForm";
			this->Text = L"Login";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	};
}