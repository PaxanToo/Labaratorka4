
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;


//загрузка
System::Void Laba4::MyForm1::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Подключение к БД
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
            if (!dbReader->IsDBNull(dbReader->GetOrdinal("id")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("Название")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("Расположение")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("Телефон")) &&
                !dbReader->IsDBNull(dbReader->GetOrdinal("Веб-сайт"))) {
                dataGridView1->Rows->Add(dbReader["id"], dbReader["Название"], dbReader["Расположение"], dbReader["Телефон"], dbReader["Веб-сайт"]);
            }
        }
    }

    dbReader->Close();
    dbConnection->Close();


    return System::Void();
}


//добавление
System::Void Laba4::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // проверяем, что ток одну строку трогаем 
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите строку для добавления", "Кавабанга");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;

    // проверка индекса на диапозон
    if (index < 0 || index >= dataGridView1->Rows->Count) {
        MessageBox::Show("Неверный индекс строки", "Ошибка");
        return;
    }

    // Проверяем, что все ячейки в выбранной строке заполнены
/*Кароче ваще лафа оказывается, нужно было просто через цикл проверку заебенитб, начинаме с 1 так как 0 у нас это id он сам там вертиться как хочет поэтому его не проверяем 
* вот такие пироги
*/
    for (int i = 1; i <= 4; i++) {
        if (dataGridView1->Rows[index]->Cells[i]->Value == nullptr ||
            dataGridView1->Rows[index]->Cells[i]->Value->ToString() == "") {
            MessageBox::Show("Не все данные введены!", "Ошибка!");
            return;
        }
    }

    // данные из ввыбраной строки лутаем 
    String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ street = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
    String^ phone = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
    String^ sait = dataGridView1->Rows[index]->Cells[4]->Value->ToString();

    // подключаемся к бдшке
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();

    // без id просим внести данные типо
    String^ query = "INSERT INTO [Театры] (Название, Расположение, Телефон, [Веб-сайт]) VALUES (?, ?, ?, ?)";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

    dbComand->Parameters->AddWithValue("?", name);
    dbComand->Parameters->AddWithValue("?", street);
    dbComand->Parameters->AddWithValue("?", phone);
    dbComand->Parameters->AddWithValue("?", sait);

    if (dbComand->ExecuteNonQuery() != 1)
        MessageBox::Show("Ошибка выполнения запроса!", "Ошибка");
    else
        MessageBox::Show("Данные добавлены!", "Успешно");

    dbConnection->Close();
}

//удаляшка
System::Void Laba4::MyForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите строку для удаления", "Ошибка");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[1]->Value != nullptr) {
        
    }
    else {
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


//поиск
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

System::Void Laba4::MyForm1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close(); // Закрываем текущее окно
}
