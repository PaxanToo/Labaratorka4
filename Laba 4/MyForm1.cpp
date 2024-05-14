
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;


//��������
System::Void Laba4::MyForm1::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ����������� � ��
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
            if (!dbReader->IsDBNull(dbReader->GetOrdinal("id")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("��������")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("������������")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("�������")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("���-����"))) {
                dataGridView1->Rows->Add(dbReader["id"], dbReader["��������"], dbReader["������������"], dbReader["�������"], dbReader["���-����"]);
            }
        }
    }

    dbReader->Close();
    dbConnection->Close();


    return System::Void();
}


//����������
System::Void Laba4::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ���������, ��� ��� ���� ������ ������� 
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ������ ��� ����������", "���������");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    // �������� ������� �� ��������
    if (index < 0 || index >= dataGridView1->Rows->Count) {
        MessageBox::Show("�������� ������ ������", "������");
        return;
    }

    // ���������, ��� ��� ������ � ��������� ������ ���������
/*������ ���� ���� �����������, ����� ���� ������ ����� ���� �������� ���������, �������� � 1 ��� ��� 0 � ��� ��� id �� ��� ��� ��������� ��� ����� ������� ��� �� ��������� 
* ��� ����� ������
*/
    for (int i = 1; i <= 4; i++) {
        if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[i]->Value->ToString() == "") {
            MessageBox::Show("�� ��� ������ �������!", "������!");
            return;
        }
    }

    // ������ �� ��������� ������ ������ 
    String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

    // ������������ � �����
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    // ��� id ������ ������ ������ ����
    String^ query = "INSERT INTO [������] (��������, ������������, �������, [���-����]) VALUES (?, ?, ?, ?)";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

    dbComand->Parameters->AddWithValue("?", name);
    dbComand->Parameters->AddWithValue("?", street);
    dbComand->Parameters->AddWithValue("?", phone);
    dbComand->Parameters->AddWithValue("?", sait);

    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("������ ���������� �������!", "������");
    else
        MessageBox::Show("������ ���������!", "�������");

    dbConnection->Close();
}

//��������
System::Void Laba4::MyForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("�������� ������ ��� ��������", "������");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[1]->Value != nullptr) {
        
    }
    else {
        MessageBox::Show("���-�� ����� �� ���!", "������!");
        return;
    }


    String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();


    //� ����� ������������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //������ � ��
    dbConnection->Open();
    String^ query = "DELETE FROM [������] WHERE id = " + id;
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);



    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("������ ���������� �������!", "������");
    else {
        MessageBox::Show("������ ������� �������!", "�������");

        dataGridView1->Rows->RemoveAt(index);
    }
    dbConnection->Close();

    return System::Void();
}


//�����
System::Void Laba4::MyForm1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ searchString = textBox1->Text; // ����� ���� ��� ������ � ��� �������������, ����� ������ SQL �� ��������

    //� ����� ������������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //������ � ��
    dbConnection->Open();
    //�� ��� �����, ������� ������ � �� ������� ���� �� ������� ������� ������, �� ���� ��� ���������� 
    String^ query = "SELECT * FROM [������] WHERE id LIKE '%" + searchString + "%' OR �������� LIKE '%" + searchString + "%' OR ������������ LIKE '%" + searchString + "%' OR ������� LIKE '%" + searchString + "%' OR [���-����] LIKE '%" + searchString + "%'";

    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader();

    dataGridView1->Rows->Clear();

    //�� ��  ����� ���������� 
    while (dbReader->Read()) {
        dataGridView1->Rows->Add(dbReader["id"], dbReader["��������"], dbReader["������������"], dbReader["�������"], dbReader["���-����"]);
    }

    dbReader->Close();
    dbConnection->Close();
}

System::Void Laba4::MyForm1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close(); // ��������� ������� ����
}
