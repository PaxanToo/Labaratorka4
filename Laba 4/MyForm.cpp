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
	//� ����� ������������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open();
	String^ query = "SELECT * FROM [������]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("������ ��� ���������� ������" "������");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["��������"], dbReader["������������"], dbReader["�������"], dbReader["���-����"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();


	return System::Void();
}

System::Void Laba4::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� �������� ��� ����������", "���������");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr){
		MessageBox::Show("�� ��� ������ �������!", "������!");
	return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//� ����� ������������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open();
	String^ query = "INSERT INTO [������] VALUES ('" + id + "','" + name + "', '" + street + "', '" + phone + "', '" + sait + "')";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������");
	else
		MessageBox::Show("������ ���������!", "�������");

	dbConnection->Close();

	return System::Void();
}

System::Void Laba4::MyForm::button_update_Click(System::Object^ sender, System::EventArgs^ e)//!
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� �������� ��� ����������", "���������");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("�� ��� ������ �������!", "������!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

	//� ����� ������������
	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open();
	String^ query = "UPDATE [������] SET Name='" + name + "', Street = '" + street + "', Phone ='" + phone + "',sait ='" + sait + "' WHERE id = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("������ ���������� �������!", "������");
	else
		MessageBox::Show("������ ��������!", "�������");

	dbConnection->Close();

	return System::Void();
}

System::Void Laba4::MyForm::button_delet_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ������ ��� ��������", "������");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	if (MessageBox::Show("�� �������, ��� ������ ������� ������?", "�������� ������", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		// ������������ � ��
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		// ������ � ��
		dbConnection->Open();
		String^ query = "DELETE FROM [������] WHERE id = " + id;
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

		if (dbCommand->ExecuteNonQuery() != 1)
			MessageBox::Show("������ ���������� �������!", "������");
		else {
			MessageBox::Show("������ �������!", "�������");
			dataGridView1->Rows->RemoveAt(index);
		}

		dbConnection->Close();
	}
}

System::Void Laba4::MyForm::button_search_Click(System::Object^ sender, System::EventArgs^ e)
{
	// �������� � ��������� TextBox
	TextBox^ searchTextBox = gcnew TextBox();
	searchTextBox->Location = Point(button_search->Location.X, button_search->Location.Y + button_search->Height + 25);
	searchTextBox->Size = System::Drawing::Size(150, 20);

	// ���������� TextBox �� �����
	this->Controls->Add(searchTextBox);

	// ��������� ������ �� TextBox
	searchTextBox->Focus();

	// ��������� ������� ������� ������� Enter ��� ������� ������
	searchTextBox->KeyDown += gcnew KeyEventHandler(this, &MyForm::searchTextBox_KeyDown);
}

System::Void Laba4::MyForm::searchTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	// �������� ������� ������� Enter
	if (e->KeyCode == Keys::Enter)
	{
		String^ searchQuery = ((TextBox^)sender)->Text; // ��������� ������ �� TextBox

		// ��������� ������ ����������� � ���� ������
		String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		// �������� ���������� � ����� ������
		dbConnection->Open();

		// ������������ SQL-������� ��� ������ �������
		String^ query = "SELECT * FROM [������] WHERE �������� LIKE '%" + searchQuery + "%' OR ������������ LIKE '%" + searchQuery + "%'";
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

		// ������� DataGridView ����� ����������� ����������� ������
		dataGridView1->Rows->Clear();

		// ���������� ����������� ������ � DataGridView
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["��������"], dbReader["������������"], dbReader["�������"], dbReader["���-����"]);
		}

		// �������� ���������� � ����� ������
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
	MessageBox::Show("������ ��������� ������������� ��� ����, ����� ������������ ��� ������������ � ����� ������ �����������, ������� '���������' � �������", "���������� ��� ������������");
}
