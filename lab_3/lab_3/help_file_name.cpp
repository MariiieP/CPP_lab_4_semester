//
//  help_file_name.h
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef help_file_name_h
#define help_file_name_h
#include "help_file_name.h"



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

// ввод информации
int input_information(int mes,string messge)
{
    int a;
    cout << messge ;
    cin >> a;
    return a;
}

// ввод информации
bool input_information(bool mes,string messge)
{
    bool a;
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

string string_from_binary_file(ifstream& in)
{
    string result;
    size_t len;
    in.read((char*)&len, sizeof(len));
    char *  buf = new char[len];
    result = buf;
    delete[]buf;

    return result;
}

void string_in_binary_file(ofstream& ofs, string str)
{
    size_t len = str.length() + 1;
    ofs.write( (char*)&len, sizeof(int) );
    ofs.write( str.c_str(), len );
}





#endif /* help_file_name_h */
