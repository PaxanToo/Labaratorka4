#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;
using namespace System::Security::Cryptography;
using namespace System::Text;

// ������� ��� ��������� SHA256 ���� ������
/*String^ GetSHA256Hash(String^ input) {
    array<Byte>^ hashBytes = SHA256Managed::Create()->ComputeHash(Encoding::UTF8->GetBytes(input));
    StringBuilder^ hashString = gcnew StringBuilder();
    for each (Byte b in hashBytes) {
        hashString->Append(b.ToString("x2"));
    }
    return hashString->ToString();
}

*/

System::Void Laba4::MyForm2::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ username = textBoxUsername->Text;
    String^ password = textBoxPassword->Text;

    // � ����� ������������
    String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    //String^ hashedPassword = GetSHA256Hash(password);

    try {
        dbConnection->Open();
        
        String^ query = "SELECT PasswordHash FROM ������������ WHERE Username = ?";
        OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
        dbCommand->Parameters->AddWithValue("?", username); 

        OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

        if (dbReader->Read()) {
            String^ storedPassword = dbReader["PasswordHash"]->ToString();

            if (storedPassword->Equals(password)) {
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






