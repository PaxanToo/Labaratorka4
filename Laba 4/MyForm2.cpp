#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;
using namespace System::Security::Cryptography;
using namespace System::Text;




// ������� ��� ����������� ������ � �������������� SHA-256
String^ GenerateHash(String^ password)
{
    array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);

    SHA256^ sha256 = SHA256::Create();
    array<Byte>^ hashBytes = sha256->ComputeHash(passwordBytes);

    StringBuilder^ stringBuilder = gcnew StringBuilder();
    for each (Byte b in hashBytes) {
        stringBuilder->Append(b.ToString("x2"));
    }

    return stringBuilder->ToString();
}

System::Void Laba4::MyForm2::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ username = textBoxUsername->Text;
    String^ password = textBoxPassword->Text;

    // � ����� ������������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try {
        dbConnection->Open();

        String^ query = "SELECT PasswordHash FROM ������������ WHERE Username = ?";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->Parameters->AddWithValue("?", username);

        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        if (dbReader->Read()) {
            // �������� ��� ������ �� ���� ������
            String^ storedPasswordHash = dbReader["PasswordHash"]->ToString();

            // �������� storedPasswordHash � ������� ��������
            storedPasswordHash = storedPasswordHash->ToLower();

            // �������� ��� ���������� ������������� ������
            String^ inputPasswordHash = GenerateHash(password);

            // ��������� ���������� �����
            if (storedPasswordHash->Equals(inputPasswordHash)) {
                authenticated = true;
                this->Close();
            }
            else {
                MessageBox::Show("�������� ����� ��� ������", "������ �����������");
            }
        }
        else {
            MessageBox::Show("������������ � ����� ������� �� ������", "������ �����������");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message, "������");
    }
    finally {
        dbConnection->Close();
    }
}






