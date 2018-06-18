//
//  Data.hpp
//  test_3_C++
//
//  Created by Мария Юрьевна on 18.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef Data_h
#define Data_h

#include <stdio.h>
#include <string>
#include "help_file_name.h"

using namespace std;

class Data {
    friend class bank_account;
private:

    // день
    int day;
    // месяц
    int month;
    // год
    int year;

    bool is_leap(int year);
    bool correct_date(int day, int month, int year,string &message);

public:

    // конструктор по умолчанию
    Data();
    // ввод даты с консоли
    void input_date();
    // перевод даты в строку (для последующей записи в файл)
    string date_to_string();
    // перегруженный оператор равенства
    bool operator == (const Data &c);
    // конструктор копирования
    Data& operator = (Data c);
    // перегруженный оператор больше
    bool operator > (const Data &c);
    // перегруженные оператор меньше
    bool operator < (const Data &c);
};

#endif /* Data_h */
