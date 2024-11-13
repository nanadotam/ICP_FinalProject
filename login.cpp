#include "login.h"
#include "Signup.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ICPFinalProject:: Signup form;
    //ICPFinalProject::login form;

    Application::Run(% form);
}
