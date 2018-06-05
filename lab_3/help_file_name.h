//
//  help_file_name.c
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


template <class Type>
Type input_number(Type min, Type max,string message);
// ввод информации
string input_information(string messge);
// ввод информации
int input_information(int mes,string messge);
// ввод информации
bool input_information(bool mes,string messge);
// проверка символа на корректность в имени файла
bool correct_symbol(char c);
// проверка имени файла на коректность
bool correct_name(string name);
// ввод имени файла
string input_file_name();


string string_from_binary_file(ifstream& in);

void string_in_binary_file(ofstream& ofs, string str);
