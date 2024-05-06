
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"

using namespace std;

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

System::Void Laba4::MyForm2::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username = textBoxUsername->Text; 
	String^ password = textBoxPassword->Text;

	if (username == "123" && password == "123")
	{ 
		authenticated = true;
		this->Close();
	}	
		
else {
	MessageBox::Show("Неверный логин или пароль", "Ошибка авторизации");
}
}


