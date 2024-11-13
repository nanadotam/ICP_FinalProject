#include "Signup.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int you(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ICPFinalProject::Signup form;

    Application::Run(% form);
    return 0;
}


