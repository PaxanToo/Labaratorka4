#pragma once


namespace Laba4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_info;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	private: System::Windows::Forms::ToolTip^ ToolTip;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_info = (gcnew System::Windows::Forms::Button());
			this->ToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(824, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(13, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(798, 81);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Дейсвия";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(210, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 54);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Представления";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Информация о театрах";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(19, 525);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(127, 31);
			this->button_exit->TabIndex = 5;
			this->button_exit->Text = L"Выйти из программы";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button_exit_Click);
			// 
			// button_info
			// 
			this->button_info->Location = System::Drawing::Point(152, 525);
			this->button_info->Name = L"button_info";
			this->button_info->Size = System::Drawing::Size(176, 31);
			this->button_info->TabIndex = 6;
			this->button_info->Text = L"Информация о программе";
			this->button_info->UseVisualStyleBackColor = true;
			this->button_info->Click += gcnew System::EventHandler(this, &MyForm::button_info_Click);
			// 
			// ToolTip
			// 
			this->ToolTip->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::ToolTip_Popup);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(53, 126);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 250);
			this->panel1->TabIndex = 7;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(271, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(265, 300);
			this->panel2->TabIndex = 8;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Location = System::Drawing::Point(268, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(265, 300);
			this->panel3->TabIndex = 9;
			// 
			// panel4
			// 
			this->panel4->Location = System::Drawing::Point(271, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(265, 300);
			this->panel4->TabIndex = 8;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->panel8);
			this->panel5->Location = System::Drawing::Point(300, 126);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(250, 250);
			this->panel5->TabIndex = 10;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Location = System::Drawing::Point(268, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(265, 300);
			this->panel6->TabIndex = 9;
			// 
			// panel7
			// 
			this->panel7->Location = System::Drawing::Point(271, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(265, 300);
			this->panel7->TabIndex = 8;
			// 
			// panel8
			// 
			this->panel8->Location = System::Drawing::Point(271, 0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(265, 300);
			this->panel8->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 91);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Здесь должна была \r\n\r\nбыть картинка либо текст \r\n\r\nРазработчик мал и глуп,\r\n\r\n не"
				L" видал большших фреймворков ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 562);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button_info);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(840, 601);
			this->MinimumSize = System::Drawing::Size(840, 601);
			this->Name = L"MyForm";
			this->Text = L"Театры города Сыктывкар (информация о представлениях)";
			this->groupBox1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_delet_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button_info_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void ToolTip_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e);

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
