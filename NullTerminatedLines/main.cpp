#include <iostream>
#include <Windows.h>
using namespace std;

int Strlen(char str[]);
void ToUpper(char str[]);
void ToLower(char str[]);
void Shrink(char str[]);

int main()
{
	setlocale(LC_ALL, "");
	//char sz_str[] = {'H','e','l','l','o', '\0'};
	/*char sz_str[] = "Hello";
	cout << sz_str << endl;*/
	const int n = 20;
	char sz_str[n] = {};
	cout << "Введите строку: ";
	//cin >> sz_str;
	SetConsoleCP(1251);
	cin.getline(sz_str, n);
	SetConsoleCP(866);
	cout << sz_str << endl;
	cout << "Размер буфера: " << sizeof(sz_str) << endl;
	cout << "Размер строки: " << Strlen(sz_str) << endl;
	cout << "В верхний регистр: ";
	ToUpper(sz_str);
	cout << sz_str << endl;
	cout << "В нижний регистр: ";
	ToLower(sz_str);
	cout << sz_str << endl;
	cout << "Без пробелов: ";
	Shrink(sz_str);
	cout << sz_str << endl;
}

int Strlen(char str[])
{
	int cnt = 0;
	/*for (int i = 0; str[i] != '\0'; i++)
	{
		cnt++;
	}*/
	for (; str[cnt]; cnt++);
	return cnt;
}

void ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я'))
			str[i] -= 32;
	}
}

void ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'А' && str[i] <= 'Я'))
			str[i] += 32;
	}
}

void Shrink(char str[])
{
	int n = Strlen(str);
	int cnt = 0;
	char* buffer = new char[n] {};
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] != ' ') || (str[i] == ' ' && str[i + 1] != ' '))
		{
			buffer[cnt] = str[i];
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		str[i] = buffer[i];
		str[cnt] = 0;
	}
}