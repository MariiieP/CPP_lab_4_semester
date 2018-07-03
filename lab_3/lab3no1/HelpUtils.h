#pragma once
#include <fstream>
using namespace std;

//вопрос пользователю
bool input_query();
//считывание строки из бинарного файла
string str_from_bin(ifstream *f);
//запись строки в бинарный файл
void StrToBin(ofstream *f, string str);
//Обрезка строки
string trim(const string& str);


//ввод номера
bool input_number(double & num, string message);
bool input_number(int32_t &num, string message);
//Функция для ввода строковой информации
string input_information(string message);

//Показать заголовок
void show_header();