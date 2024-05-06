
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;


System::Void Laba4::MyForm1::button_download_Click(System::Object^ sender, System::EventArgs^ e)
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



System::Void Laba4::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    //проверка строк
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите строкчку для добавления", "Кавабанга");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    //проверка данных
    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr &&
        dataGridView1->Rows[index]->Cells[1]->Value == nullptr &&
        dataGridView1->Rows[index]->Cells[2]->Value == nullptr &&
        dataGridView1->Rows[index]->Cells[3]->Value == nullptr &&
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
    String^ query = "INSERT INTO [Театры] VALUES ('" + id + "','" + name + "', '" + street + "', '" + phone + "', '" + sait + "')";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
    else
        MessageBox::Show("Данные добавлены!", "Успешно");

    dbConnection->Close();

    return System::Void();
}

System::Void Laba4::MyForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите строкчку для добавления", "Кавабанга");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
    {
        MessageBox::Show("Что-то пошло не так!", "Ошибка!");
        return;
    }

    String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();


    //к бдшке подключаемся
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //запрос к бд
    dbConnection->Open();
    String^ query = "DELETE FROM [Театры] WHERE id = " + id;
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);



    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
    else {
        MessageBox::Show("Данные успешно удалены!", "Успешно");

        dataGridView1->Rows->RemoveAt(index);
    }
    dbConnection->Close();

    return System::Void();
}

System::Void Laba4::MyForm1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ searchString = textBox1->Text; // текст типо тут вводит и его просматриваем, будет искать SQL по похожиму

    //к бдшке подключаемся
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //запрос к бд
    dbConnection->Open();
    //ну тут поиск, команда выбора и всё плюсуем чтоб по каждому столбцу искало, то есть все свопадения 
    String^ query = "SELECT * FROM [Театры] WHERE id LIKE '%" + searchString + "%' OR Название LIKE '%" + searchString + "%' OR Расположение LIKE '%" + searchString + "%' OR Телефон LIKE '%" + searchString + "%' OR [Веб-сайт] LIKE '%" + searchString + "%'";

    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader();

    dataGridView1->Rows->Clear();

    //то шо  нашли отображаем 
    while (dbReader->Read()) {
        dataGridView1->Rows->Add(dbReader["id"], dbReader["Название"], dbReader["Расположение"], dbReader["Телефон"], dbReader["Веб-сайт"]);
    }

    dbReader->Close();
    dbConnection->Close();
}
