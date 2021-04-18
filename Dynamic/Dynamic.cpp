// Dynamic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//#pragma comment(lib,"C:\\Users\\Артем\\source\\repos\\DllNik\\Debug\\DllNik.lib")
#include <iostream>
#include "windows.h"

typedef int(PGroup)();
typedef void(PName)(char*, int);

int main()
{
    HINSTANCE hDll = LoadLibrary(L"Dll2.dll");
    if (hDll == NULL)
    {
        std::cout << L"Ошибка подключения библиотеки!";
        return 1;
    }

    PGroup* Group;
    PName* Name;
    Group = (PGroup*)GetProcAddress(hDll, "Group");
    Name = (PName*)GetProcAddress(hDll, "Name");

    if (Group == NULL)
    {
        std::cout << L"Ошибка подключения функции number";
        return 1;
    }
    if (Name == NULL)
    {
        std::cout << L"Ошибка подключения функции name";
        return 1;
    }


        std::cout << "Group\n" << Group() << "\n";
        char vi[20];
        Name(vi, 15);
        std::cout << "Name\n" << vi << "\n";
        system("pause");
        return 0;
     
}
