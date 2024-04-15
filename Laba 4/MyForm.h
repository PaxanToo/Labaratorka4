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




	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delet;
	private: System::Windows::Forms::Button^ button_update;



	private: System::Windows::Forms::Button^ button_add;



	private: System::Windows::Forms::Button^ button_download;
	private: System::Windows::Forms::Button^ button_search;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_info;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;









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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->button_delet = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_info = (gcnew System::Windows::Forms::Button());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
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
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id, this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 82);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(542, 437);
			this->dataGridView1->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_search);
			this->groupBox1->Controls->Add(this->button_delet);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(13, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(798, 81);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Дейсвия";
			// 
			// button_search
			// 
			this->button_search->Location = System::Drawing::Point(646, 18);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(137, 53);
			this->button_search->TabIndex = 4;
			this->button_search->Text = L"Поиск";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &MyForm::button_search_Click);
			// 
			// button_delet
			// 
			this->button_delet->Location = System::Drawing::Point(489, 18);
			this->button_delet->Name = L"button_delet";
			this->button_delet->Size = System::Drawing::Size(137, 53);
			this->button_delet->TabIndex = 3;
			this->button_delet->Text = L"Удалить";
			this->button_delet->UseVisualStyleBackColor = true;
			this->button_delet->Click += gcnew System::EventHandler(this, &MyForm::button_delet_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(333, 18);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(137, 53);
			this->button_update->TabIndex = 2;
			this->button_update->Text = L"Обновить";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &MyForm::button_update_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(178, 18);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(137, 53);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(23, 18);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(137, 53);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"Загрузить";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
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
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Расположение";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Телефон";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Веб-сайт";
			this->Column4->Name = L"Column4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 562);
			this->Controls->Add(this->button_info);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(840, 601);
			this->MinimumSize = System::Drawing::Size(840, 601);
			this->Name = L"MyForm";
			this->Text = L"Театры города Сыктывкар (информация о представлениях)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
	
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_delet_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_search_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_info_Click(System::Object ^ sender, System::EventArgs ^ e);

};
}
