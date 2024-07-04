#include "pch.h"
#include <Windows.h>
using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, L"DVMEGAControl");

    if (!hMutex)
    {
        // Mutex doesn’t exist. This is
        // the first instance so create
        // the mutex.
        hMutex = CreateMutex(0, 0, L"DVMEGAControl");
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        Application::Run(gcnew CppCLRWinFormsProject::Form1());
        ReleaseMutex(hMutex);
    }
  
    return 0;
}