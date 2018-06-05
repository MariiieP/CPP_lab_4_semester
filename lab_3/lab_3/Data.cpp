//
//  Data.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "Data.h"
#include "help_file_name.cpp"


// проверка является ли год високосным
bool Data::is_leap(int year)
{
    if ( (year % 4) || ( ( year % 100 ) == 0 && ( year % 400 ) ) )
        return false;
    return true;
}

// проверка даты на корректность
bool Data::correct_date(int day, int month, int year,string &message)
{
    // если год вискосный                            //если не високосный
    if ((month == 2 && day > 29 && is_leap(year)) || (month == 2 && day > 28 && !is_leap(year)))
    {
        message = "Неверное кол-во дней в феврале!";
        return false;
    }
    //кол-во дней в месяце
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            message = "Неверное кол-во дней в месяце!";
            return false;
        }
    }
    return true;
}


// конструктор по умолчанию
Data::Data()
{
    day=1;
    month=1;
    year = 1990;
}

// ввод даты с консоли
void Data::input_date()
{
    bool answer = true; // корректна ли введенная дата
    string message = "";  // сообщение о причине ошибки
    do
    {
        if (!answer)
            cout << message << endl;
        day = input_number(1, 31, "Ввод даты:\nВведите день (1-31): ");
        month = input_number(1, 12, "Введите номер месяца (1-12): ");
        year = input_number(1970, 2018, "Введите год (1970-2018): ");
        answer = correct_date(day, month, year, message);
    } while (!answer);  // повторять ввод пока не корректная дата
}

// перевод даты в строку (для последующей записи в файл)
string Data::date_to_string()
{
    return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
}

// перегруженный оператор равенства
bool Data::operator == (const Data &c)
{
    return ((day == c.day) && (month == c.month) && (year == c.year));
}

// конструктор копирования
Data& Data::operator = (Data c)
{
    day = c.day;
    month = c.month;
    year = c.year;

    return (*this);
}

// перегруженный оператор больше
bool Data::operator > (const Data &c)
{
    return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
}

// перегруженные оператор меньше
bool Data::operator < (const Data &c)
{
    return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
}


