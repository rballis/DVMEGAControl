#include "pch.h"
#include <Windows.h>
#include "ChilkatUnlock.h"
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
    const LPCWSTR mutexName = L"DVMEGAControl";
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, mutexName);

    if ((!hMutex) &&
        ((gcnew ChilkatUnlock())->Unlock()))
    {
        // Mutex doesn’t exist. This is
        // the first instance so create
        // the mutex.
        hMutex = CreateMutex(0, 0, mutexName);
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        Application::Run(gcnew CppCLRWinFormsProject::Form1());
        ReleaseMutex(hMutex);
    }
  
    return 0;
}