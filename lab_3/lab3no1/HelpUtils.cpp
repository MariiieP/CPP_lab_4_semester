#include <iostream>
#include <iomanip>
#include <sstream>
#include "HelpUtils.h"
#include "stdafx.h"

//считывание строки из бинарного файла
string str_from_bin(ifstream *f)
{
	string result;
	int32_t len;// размер необходимого буффера

	if (!f->read(reinterpret_cast<char*>(&len), sizeof(len)))
	{//преобразование указателей
		return "";
	}
	char *buf = new char[len];
	if (!f->read(buf, len)) 
	{
		return "";
	}
	result = buf;
	delete[] buf;
	return result;
}

//Обрезка строки
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');//first = поция первого непробельного символа, max знач типа в противном случае   
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');//last = поция последнего непробельного символа
	return
		str.substr(first, (last - first + 1));// верни всю строку без пробелов
}



//запись строки в бинарный файл
void StrToBin(ofstream *f, string str) 
{
	int32_t len = str.length() + 1;//+ нулевой байт для отделения строк(чтобы потом читать красиво)
	f->write(reinterpret_cast<char*>(&len), sizeof(len));
	f->write(str.c_str(), len);
}

void show_header() 
{
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(1) << "|" << setw(7) << left << "Номер"<<"|"
		<<setw(4)<<left<<"Код"<<"|"
		<< setw(15) << left << "ФИО" <<"|"
		<< setw(10) << left << "Сумма"<<"|"
		<< setw(15) << left << "Дата"<<"|"
		<< setw(5) << left << "Срок"<<"|"
		<< setw(19) << left << "Название" << "|"
		<< setw(14) << left << "В-сть пополн." << "|"
		<< setw(14) << left << "В-сть сним" << "|"
		<< setw(8) << left << "Процент" << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
}


//вопрос пользователю
bool input_query() 
{
	char c;
	do {
		cout << "Y/N? ";
		cin >> c;
	} while (c != 'n' && c != 'N' && c != 'y' && c != 'Y');
	return c == 'Y' || c == 'y';
}
//ввод номера
bool input_number(double & num, string message)
{
	cout << message << endl;;
	cin >> num;
	bool OK = cin.good();
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return OK;
}



bool input_number(int32_t &num, string message)
{
	cout << message << endl;;
	cin >> num;
	bool OK = cin.good();
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return OK;
}

string input_information(string message)
{
	string a; 
	cout << message << endl;;
	getline(cin, a);
	while (trim(a) == "")
	{
		cout << "Ошибка. Повторите ввод:" << endl;
		getline(cin, a);
	}
	return a;
}