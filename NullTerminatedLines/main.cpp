#include <iostream>
#include <Windows.h>
using namespace std;

int Strlen(char str[]);
void To_upper(char str[]);
void To_lower(char str[]);
void No_spaces(char str[]);
void Shrink(char str[]);
bool Is_palindrome_simple(char str[]);
bool Is_palindrome_complex(char str[]);
bool Is_int_number(char str[]);
int To_int_number(char str[]);
bool Is_bin_number(char str[]);
int Bin_to_dec(char str[]);
bool Is_hex_number(char str[]);
int  Hex_to_dec(char str[]);

int main()
{
	setlocale(LC_ALL, "");
	const int n = 256;
	char sz_str[n] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(sz_str, n);
	SetConsoleCP(866);
	cout << sz_str << endl;
	
	// Определение размеров буфера и строки
	/*cout << "Размер буфера: " << sizeof(sz_str) << endl;
	cout << "Размер строки: " << Strlen(sz_str) << endl;*/

	// Тест на перевод в верхний регистр
	/*cout << "В верхний регистр: ";
	To_upper(sz_str);
	cout << sz_str << endl;*/

	// Тест на перевод в нижний регистр
	/*cout << "В нижний регистр: ";
	To_lower(sz_str);
	cout << sz_str << endl;*/

	// Тест на удаление лишних пробелов
	/*cout << "Без лишних пробелов: ";
	Shrink(sz_str);
	cout << sz_str << endl;*/

	// Тест на палиндром
	/*if (Is_palindrome_complex(sz_str))
		cout << "Это палиндром!" << endl;
	else
		cout << "Это не палиндром." << endl;*/

	// Тест на int
	/*if (Is_int_number(sz_str))
		cout << "Это int!" << endl;
	else
		cout << "Это не int." << endl;*/

	// Тест на перевод строки в int
	//cout << typeid(To_int_number(sz_str)).name() << "\t" << To_int_number(sz_str) << endl;

	// Тест на двоичное число
	/*if (Is_bin_number(sz_str))
		cout << "Это binary!" << endl;
	else
		cout << "Это не binary." << endl;*/

	// Тест на перевод двоичного числа в десятичное
	//cout << "В десятичной форме введенное число равно " << Bin_to_dec(sz_str) << endl;

	// Тест на шестнадцатеричное число
	/*if (Is_hex_number(sz_str))
		cout << "Это hex!" << endl;
	else
		cout << "Это не hex." << endl;*/

	// Тест на перевод шестнадцатеричного числа в десятичное
	cout << "В десятичной форме введенное число равно " << Hex_to_dec(sz_str) << endl;
}

int Strlen(char str[])
{
	int cnt = 0;
	for (; str[cnt]; cnt++);
	return cnt;
}

void To_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я'))
			str[i] -= 32;
	}
}

void To_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'А' && str[i] <= 'Я'))
			str[i] += 32;
	}
}

void No_spaces(char str[])
{
	int cnt = 0;
	for (int i = 0; str[i]; i++)
	{
		if (cnt > 0)
		{
			str[i - cnt] = str[i];
			if (str[i] == ' ')
				cnt++;
			str[i] = 0;
		}
		if (str[i] == ' ')
			cnt++;
	}
}

void Shrink(char str[])
{
	int cnt = 0; // Счётчик пробелов
	char temp = str[0]; // Переменная, чтобы хранить str[i] до изменения
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && temp == ' ')
			cnt++; // Увеличиваем счётчик, если только пробел следует за пробелом
		temp = str[i];
		if (cnt > 1)
		{
			str[i - cnt] = str[i];
			str[i] = 0;
		}
	}
}

bool Is_palindrome_simple(char str[])
{
	int n = Strlen(str);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i])
			return false;
	}
	return true;
}

bool Is_palindrome_complex(char str[])
{
	To_lower(str);
	Shrink(str);
	No_spaces(str);
	return Is_palindrome_simple(str);
}

bool Is_int_number(char str[])
{
	if (str[0] == '-')
	{
		for (int i = 1; str[i]; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				return false;
		}
		return true;
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				return false;
		}
		return true;
	}
}

int To_int_number(char str[])
{
	if (Is_int_number(str))
	{
		int n = Strlen(str);
		int sum = 0;
		if (str[0] == '-')
		{
			for (int i = 1; str[i]; i++)
			{
				sum += (str[i] - 48) * pow(10, n - 1 - i);
			}
			return -sum;
		}
		else
		{
			for (int i = 0; str[i]; i++)
			{
				sum += (str[i] - 48) * pow(10, n - 1 - i);
			}
			return sum;
		}
	}
	return NULL;
}

bool Is_bin_number(char str[])
{
	if (Is_int_number(str))
	{
		if (str[0] == '-')
		{
			for (int i = 1; str[i]; i++)
			{
				if (str[i] != '0' && str[i] != '1')
					return false;
			}
		}
		else
		{
			for (int i = 0; str[i]; i++)
			{
				if (str[i] != '0' && str[i] != '1')
					return false;
			}
		}
		return true;
	}
	return false;
}

int Bin_to_dec(char str[])
{
	if (Is_bin_number(str))
	{
		int n = Strlen(str);
		int sum = 0;
		if (str[0] == '-')
		{
			for (int i = 1; str[i]; i++)
			{
				sum += (str[i] - 48) * pow(2, n - 1 - i);
			}
			return -sum;
		}
		else
		{
			for (int i = 0; str[i]; i++)
			{
				sum += (str[i] - 48) * pow(2, n - 1 - i);
			}
			return sum;
		}
	}
	return NULL;
}

bool Is_hex_number(char str[])
{
	To_lower(str);
	if (str[0] == '-')
	{
		for (int i = 1; str[i]; i++)
		{
			if ((str[i] < '0' || str[i] > 'f') || (str[i] > '9' && str[i] < 'a'))
				return false;
		}
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if ((str[i] < '0' || str[i] > 'f') || (str[i] > '9' && str[i] < 'a'))
				return false;
		}
	}
	return true;
}

int Hex_to_dec(char str[])
{
	if (Is_hex_number(str))
	{
		int n = Strlen(str);
		int sum = 0;
		if (str[0] == '-')
		{
			for (int i = 1; str[i]; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'f')
				{
					switch (str[i])
					{
					case 'a':
						str[i] = 10; break;
					case 'b':
						str[i] = 11; break;
					case 'c':
						str[i] = 12; break;
					case 'd':
						str[i] = 13; break;
					case 'e':
						str[i] = 14; break;
					case 'f':
						str[i] = 15; break;
					}
					sum += (int)str[i] * pow(16, n - 1 - i);
				}
				else
					sum += (str[i] - 48) * pow(16, n - 1 - i);
			}
			return -sum;
		}
		else
		{
			for (int i = 0; str[i]; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'f')
				{
					switch (str[i])
					{
					case 'a':
						str[i] = 10; break;
					case 'b':
						str[i] = 11; break;
					case 'c':
						str[i] = 12; break;
					case 'd':
						str[i] = 13; break;
					case 'e':
						str[i] = 14; break;
					case 'f':
						str[i] = 15; break;
					}
					sum += (int)str[i] * pow(16, n - 1 - i);
				}
				else
					sum += (str[i] - 48) * pow(16, n - 1 - i);
			}
			return sum;
		}
	}
	return NULL;
}