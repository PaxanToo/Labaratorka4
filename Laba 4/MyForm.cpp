
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"

using namespace std;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;



[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    // ������� � ���������� ����� �����������
    Laba4::MyForm2^ loginForm = gcnew Laba4::MyForm2();
    Application::Run(loginForm);

    // ���� �������������� ������ �������, ���������� ������� �����
    if (loginForm->authenticated) {
        Laba4::MyForm form;
        Application::Run(% form);
    }

    return 0;
}

System::Void Laba4::MyForm::button_delet_Click(System::Object^ sender, System::EventArgs^ e)//!
{
    return System::Void();
}

System::Void Laba4::MyForm::button_search_Click(System::Object^ sender, System::EventArgs^ e)//!
{
    return System::Void();
}

System::Void Laba4::MyForm::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
System::Void Laba4::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ������� ��������� ����� ����� MyForm1
    MyForm1^ newForm = gcnew MyForm1();

    // ������������� ����� ��������� ��� ����� �����
    newForm->Text = "����� ����";

    // ���������� ����� ����� ��� ���������� ���� (��������)
    newForm->ShowDialog();
}

System::Void Laba4::MyForm::ToolTip_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e)
{
    return System::Void();
}

System::Void Laba4::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    // ������� ��������� ����� ����� MyForm1
    MyForm3^ newForm = gcnew MyForm3();

    // ������������� ����� ��������� ��� ����� �����
    newForm->Text = "����� ����";

    // ���������� ����� ����� ��� ���������� ���� (��������)
    newForm->ShowDialog();
}

System::Void Laba4::MyForm::button_info_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("������ ��������� ������������� ��� ����, ����� ������������ ��� ������������ � ����� ������ �����������, ������� '���������' � �������", "���������� ��� ������������");
}
