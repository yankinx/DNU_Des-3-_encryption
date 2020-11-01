// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <bitset>
using namespace std; 
#include "DES.h"
#include "file_manager.h"
int main()
{
    unsigned long long key = 0x3b3898371520f75e;
    ECB<unsigned long long> ecb;
    DES<unsigned long long> des;
    des.SetKey(key);
    cout << "Key "  << endl;
    cout << bitset<sizeof(key)* CHAR_BIT>(key) << endl << endl;
    ecb.SetEncryp(&des); 
    File_Manager<unsigned long long> FM;
    FM.setEnctupt(&ecb);
    FM.SetReadFile((LPCSTR)"C://ws//t_2.txt");
    FM.SetWriteFile((LPCSTR)"C://ws//CRYPT.txt");
    FM.Async_Encrypt(false);
    int a;
    cin >> a;
}

