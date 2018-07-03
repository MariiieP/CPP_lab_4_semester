#pragma once
#include <string>
#include <fstream>

using namespace std;

//структура "дата"
struct Date {
	int32_t day;
	int32_t month;
	int32_t year;
};

//считывание даты из строки
bool date_from_str(std::string str, Date &date);
string date_to_str(Date d);
//вывод даты в консоль
void date_to_console(Date date);

//сравнение дат
int compare_dates(Date d1, Date d2);

//считывание даты из бинарного файла
bool date_from_bin(Date &d, std::ifstream *f);

//запись даты в бинарный файл
void date_to_bin(Date d, std::ofstream *f);

