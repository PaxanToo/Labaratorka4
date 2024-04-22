#include "MyForm.h"


using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	Laba4::MyForm form;
	Application::Run(% form);
}

System::Void Laba4::MyForm::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
	//к бдшке подключаемся
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//запрос к бд
	dbConnection->Open();
	String^ query = "SELECT * FROM [Театры]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка при считывание данных" "Ошибка");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["Название"], dbReader["Расположение"], dbReader["Телефон"], dbReader["Веб-сайт"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();


	return System::Void();
}

System::Void Laba4::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строкчку для добавления", "Кавабанга");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr){
		MessageBox::Show("Не все данные введены!", "Ошибка!");
	return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//к бдшке подключаемся
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//запрос к бд
	dbConnection->Open();
	String^ query = "INSERT INTO [Театры] VALUES ('" + id + "','" + name + "', '" + street + "', '" + phone + "', '" + sait + "')";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
	else
		MessageBox::Show("Данные добавлены!", "Успешно");

	dbConnection->Close();

	return System::Void();
}

System::Void Laba4::MyForm::button_update_Click(System::Object^ sender, System::EventArgs^ e)//!
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строкчку для добавления", "Кавабанга");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Не все данные введены!", "Ошибка!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//к бдшке подключаемся
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//запрос к бд
	dbConnection->Open();
	String^ query = "UPDATE [Театры] SET Name='" + name + "', Street = '" + street + "', Phone ='" + phone + "',sait ='" + sait + "' WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
	else
		MessageBox::Show("Данные изменены!", "Успешно");

	dbConnection->Close();

	return System::Void();
}

System::Void Laba4::MyForm::button_delet_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите строку для удаления", "Ошибка");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	if (MessageBox::Show("Вы уверены, что хотите удалить запись?", "Удаление записи", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		// Подключаемся к БД
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		// Запрос к БД
		dbConnection->Open();
		String^ query = "DELETE FROM [Театры] WHERE id = " + id;
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1)
			MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
		else {
			MessageBox::Show("Запись удалена!", "Успешно");
			dataGridView1->Rows->RemoveAt(index);
		}

		dbConnection->Close();
	}
}

System::Void Laba4::MyForm::button_search_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Создание и настройка TextBox
	TextBox^ searchTextBox = gcnew TextBox();
	searchTextBox->Location = Point(button_search->Location.X, button_search->Location.Y + button_search->Height + 25);
	searchTextBox->Size = System::Drawing::Size(150, 20);

	// Добавление TextBox на форму
	this->Controls->Add(searchTextBox);

	// Установка фокуса на TextBox
	searchTextBox->Focus();

	// Обработка события нажатия клавиши Enter для запуска поиска
	searchTextBox->KeyDown += gcnew KeyEventHandler(this, &MyForm::searchTextBox_KeyDown);
}

System::Void Laba4::MyForm::searchTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	// Проверка нажатия клавиши Enter
	if (e->KeyCode == Keys::Enter)
	{
		String^ searchQuery = ((TextBox^)sender)->Text; // Получение текста из TextBox

		// Установка строки подключения к базе данных
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		// Открытие соединения с базой данных
		dbConnection->Open();

		// Формирование SQL-запроса для поиска записей
		String^ query = "SELECT * FROM [Театры] WHERE Название LIKE '%" + searchQuery + "%' OR Расположение LIKE '%" + searchQuery + "%'";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

		// Очистка DataGridView перед добавлением результатов поиска
		dataGridView1->Rows->Clear();

		// Добавление результатов поиска в DataGridView
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["Название"], dbReader["Расположение"], dbReader["Телефон"], dbReader["Веб-сайт"]);
		}

		// Закрытие соединения с базой данных
		dbReader->Close();
		dbConnection->Close();
	}
}


System::Void Laba4::MyForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Laba4::MyForm::button_info_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Данная программа предназначена для того, чтобы пользователь мог ознакомиться с базой данных мероприятий, которые 'проходили' в театрах", "Информацмя для пользователя");
}
