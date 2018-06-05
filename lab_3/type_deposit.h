//
//  type_deposit.hpp
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef type_deposit_hpp
#define type_deposit_hpp
#pragma once
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "string"

using namespace std;


class type_deposit
{
//private:
 public:
    //название вида вклада
    string type_of_deposit;
    //процентная ставка
    int percent;
    //возможность частичного снятия суммы
    bool take_sum;

public:
    //конструктор
    type_deposit();

    //свойство вида вклада
    string get_type_of_deposit();
    
    //свойство процентной ставки
    int get_percent();

    //свойство частичного снятия суммы
    bool get_take_sum();

    //ввод вида вклада с консоли
    static type_deposit input_screen_type_deposit();

    //ввод вида вклада на консоль
    static void output_screen_type_deposit(type_deposit obj_type_deposit);

    //запись в бинарный файл
    static void write_type_deposit_to_binary_file(type_deposit obj_type_deposit, ofstream& ofs);

    //считывание из бинарного файла
    static type_deposit read_type_deposit_to_binary_file(ifstream& in);

    //печать шапки
    static void output_cap_type_deposit();

    //изменение типа работ
    static void change_type_deposit(type_deposit &result);

    //поиск эквивалентного по выбранному критерию
    static bool equals_type_deposit(type_deposit f,type_deposit s, int type_search);

    //ввод критерия поиска в зависимости от выбранного типа
    static type_deposit input_search_type_deposit(int type_search);

    //сравнение в зависимости от выбранного критерия
    static int compare_type_deposit(type_deposit f,type_deposit s, int type_search);

    //перегруженный оператор равенства
    /*friend*/ //bool operator ==(const type_deposit &a, type_deposit &b);
};





#endif /* type_deposit_hpp */
