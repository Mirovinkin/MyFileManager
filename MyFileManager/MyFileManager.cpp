// MyFileManager.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <bitset>

using namespace std;

class MyFile
{
protected:
    ifstream in;
    string line;
public:
    virtual void OpenFile(const char* path)
    {

        in.open(path);
        
    }
    virtual void Display(const char* path)
    {
        if (in.is_open())
        {
            while (getline(in, line))
            {
                cout << line << endl;
            }
            in.close();
        }
    };
};

class MyAscii : public MyFile
{
    void Display(const char* path) {
        if (in.is_open())
        {
            while (getline(in, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    cout << static_cast<int>(line[i]);
                }
                cout << endl;
            }
            in.close();
        }
    }
};

class MyBinary : public MyFile
{

    void Display(const char* path) {
        if (in.is_open())
        {
            while (getline(in, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    cout << bitset<8>(line[i]);
                }
                cout << endl;
            }
            in.close();
        }
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");


}
