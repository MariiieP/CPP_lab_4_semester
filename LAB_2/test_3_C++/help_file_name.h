//
//  Help.h
//  test_3_C++
//
//  Created by Мария Юрьевна on 24.04.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//
/*
#ifndef Help_h
#define Help_h


#endif  Help_h */
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

//template <class Type>



//class correct
//{
template <class Type>
Type input_number(Type min, Type max,string message)
{
    Type n;
    do
    {
        cout << message ;
        while ((!(cin >> n)) || cin.get() != '\n')
        {
            cout << "Неправильный ввод !!  Повторите ввод!\n";
            cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
            cout << message  ;
            getchar();
        }
    } while ((n < min) || (n > max));
    return n;
}


// ввод информации
string input_information(string messge)
{
    string a;
    cout << messge ;
    cin >> a;
    return a;
}

// проверка символа на корректность в имени файла
bool correct_symbol(char c)
{
    switch (c)
    {
        case '.':
        case '*':
        case '?':
        case '<':
        case '>':
        case ':':
        case '|':
        case '/':
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '(':
        case ')':
        case '_':
        case '-':
        case '+':
        case '=':
        case '[':
        case ']':
        case ';':
            return false;
        default:
            return true;
    }
}


// проверка имени файла на коректность
bool correct_name(string name)
{
    bool good_symbol = true;
    for (int i = 0; (i < name.length() && good_symbol);i++)
        good_symbol= correct_symbol(name[i]);
    return good_symbol;
}

// ввод имени файла
string input_file_name()
{
    string filename;
    do
    {
        cout << "Введите имя файла (без расширения):  ";
        cin >> filename;
        if (filename.length() > 40)
            filename.erase(filename.begin(), filename.begin() + 35);
        if (correct_name(filename))
        {
            filename = filename + ".txt";
            break;
        }
        else
            cout << "Неверное имя файла\n";
    } while (true);

    return filename;
}
//};



