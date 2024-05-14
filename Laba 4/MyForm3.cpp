#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"

using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

System::Void Laba4::MyForm3::Download_Click(System::Object^ sender, System::EventArgs^ e)
{
    //к бдшке подключаемся
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //запрос к бд
    dbConnection->Open();
    String^ query = "SELECT * FROM [Представления]";
    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader();

    if (dbReader->HasRows == false) {
        MessageBox::Show("Ошибка при считывание данных" "Ошибка");
    }
    else {
        while (dbReader->Read()) {
            dataGridView1->Rows->Add(dbReader["id"], dbReader["Название_представления"], dbReader["Жанр_представления"], dbReader["Режиссёр"], dbReader["Звёздный_исполнитель(актёр)"]);
        }
    }

    dbReader->Close();
    dbConnection->Close();


    return System::Void();
}

//добавление
System::Void Laba4::MyForm3::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
    String^ query = "INSERT INTO [Представления] ([Название_представления], [Жанр_представления], Режиссёр, [Звёздный_исполнитель(актёр)]) VALUES (?, ?, ?, ?)";
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

System::Void Laba4::MyForm3::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите строку для удаления", "Ошибка");
        return;
    }

    int index = dataGridView1->SelectedRows[0]->Index;

    if (dataGridView1->Rows[index]->Cells[1]->Value == nullptr)
    {
        MessageBox::Show("Что-то пошло не так!", "Ошибка");
        return;
    }

    String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString(); // Предполагаем, что ID находится в 5-м столбце (индекс 4).

    // К бдшке подключаемся
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    // Запрос к бд
    dbConnection->Open();
    String^ query = "DELETE FROM [Представления] WHERE id = " + id; // Используем правильное имя столбца
    OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);

    try
    {
        int rowsAffected = dbCommand->ExecuteNonQuery();
        if (rowsAffected > 0)
        {
            MessageBox::Show("Данные успешно удалены!", "Успешно");

            dataGridView1->Rows->RemoveAt(index);
        }
        else
        {
            MessageBox::Show("Данные не удалены. Проверьте правильность выбранной строки.", "Ошибка");
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка выполнения запроса: " + ex->Message, "Ошибка");
    }

    dbConnection->Close();
}


System::Void Laba4::MyForm3::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ searchString = textBox1->Text; // текст типо тут вводит и его просматриваем, будет искать SQL по похожиму

    //к бдшке подключаемся
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //запрос к бд
    dbConnection->Open();
    //ну тут поиск, команда выбора и всё плюсуем чтоб по каждому столбцу искало, то есть все свопадения 
    String^ query = "SELECT * FROM [Представления] WHERE id LIKE '%" + searchString + "%' OR [Название_представления] LIKE '%" + searchString + "%' OR [Жанр_представления] LIKE '%" + searchString + "%' OR [Режиссёр] LIKE '%" + searchString + "%' OR [Звёздный_исполнитель(актёр)] LIKE '%" + searchString + "%'";

    OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbComand->ExecuteReader();

    dataGridView1->Rows->Clear();

    //то шо  нашли отображаем 
    while (dbReader->Read()) {
        dataGridView1->Rows->Add(dbReader["id"], dbReader["[Название_представления]"], dbReader["[Жанр_представления]"], dbReader["Режиссёр"], dbReader["[Звёздный_исполнитель(актёр)]"]);
    }

    dbReader->Close();
    dbConnection->Close();
}

System::Void Laba4::MyForm3::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close(); // закрывает окно
}
