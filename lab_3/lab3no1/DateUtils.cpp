#include <iostream>
#include <cstdlib>
#include <sstream>
#include "DateUtils.h"
#include "stdafx.h"

//выделение числа из строкового представления даты
int get_number(string str, int &num)
{
	int p = str.find('.', 0);
	if (p != -1) {
		const char *ch = str.c_str();//преобразовывает str  в мас символов 
		num = atoi(ch);
		return p;
	}
	return -1;
}

//проверка на высокосный год
bool leap_year(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//возвращает кол-во дней в месяце 
int count_day_in_month(int month, int year) 
{
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return leap_year(year) ? 29 : 28;
	default:
		return 31;
	}
}

//выделение даты из строки
bool date_from_str(string str, Date &date) 
{
	if (str == "")
	{
		return false;
	}
	str += '.';
	Date d;
	int p = get_number(str, d.day);
	if (p != 1 && p != 2) 
	{
		return false;
	}
	str = str.substr(p + 1);
	p = get_number(str, d.month);
	if (p != 1 && p != 2)
	{
		return false;
	}
	str = str.substr(p + 1);
	p = get_number(str, d.year);
	if (p != 4)
	{
		return false;
	}
	if (d.month >= 1 && d.month <= 12 && d.year > 1900 &&
		d.day >= 1 && d.day <= count_day_in_month(d.month, d.year)) 
	{
		date = d;
		return true;
	}
	return false;
}

//вывод даты в консоль
void date_to_console(Date date)
{
	cout << date.day << '.' << date.month << '.' << date.year;
}

string date_to_str(Date d)
{
	string res = "";
	if (d.day < 10)
	{
		res += '0';
	}
	res += to_string(d.day) + '.';
	if (d.month < 10)
	{
		res += '0';
	}
	res += to_string(d.month) + '.';
	res += to_string(d.year);
	return res;
}

//считывание даты из бинарного файла
bool date_from_bin(Date &d, ifstream *f) 
{
	return f->read(reinterpret_cast<char*>(&(d.day)), sizeof(d.day)) &&
		f->read(reinterpret_cast<char*>(&(d.month)), sizeof(d.day)) &&
		f->read(reinterpret_cast<char*>(&(d.year)), sizeof(d.day));
}

//запись даты в бинарный файл
void date_to_bin(Date d, ofstream *f) 
{
	f->write(reinterpret_cast<char*>(&(d.day)), sizeof(d.day));
	f->write(reinterpret_cast<char*>(&(d.month)), sizeof(d.month));
	f->write(reinterpret_cast<char*>(&(d.year)), sizeof(d.year));
}

//сравнение дат
int compare_dates(Date d1, Date d2) 
{
	if (d1.year > d2.year) 
		return 1;
	if (d1.year < d2.year) 
		return -1;
	if (d1.month > d2.month) 
		return 1;
	if (d1.month < d2.month) 
		return -1;
	if (d1.day > d2.day) 
		return 1;
	if (d1.day < d2.day) 
		return -1;
	return 0;
}
