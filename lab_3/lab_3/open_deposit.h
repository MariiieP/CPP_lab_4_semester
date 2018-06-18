//
//  open_deposit.hpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef open_deposit_hpp
#define open_deposit_hpp

#include <stdio.h>
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "help_file_name.h"
#include "Data.h"
#include "type_deposit.h"



// класс "отчет о заказе"
class open_deposit
{
private:
    //имя вкладчика
    string name_client;
    // вид вклада
    string type_of_deposit;
    // срок вклада
    string time_deposit;
    // дата открытия вклада
    string date_open_deposit;
    // осумма на счету
    int sum_account;

public:

    // конструктор
    open_deposit();

    // св-во для имени
    void set_name(string value);

    // функция ввода структуры "вклад" с консоли
    static open_deposit input_screen_open_deposit();

    // функция ввода структуры "отчет" для администратора
    static open_deposit input(string _nm, type_deposit tp);

    // функция вывода структуры "вклад" на консоль
    static void output_screen_open_deposit(open_deposit c);

    // запись в бинарный файл
    static void write_open_deposit_file(open_deposit a, ofstream& os);

    // считывание из бинарного файла
    static open_deposit read_open_deposit_file(ifstream& in);

    // вывод на консоль заголовка
    static void output_screen_cap_open_deposit();

    // изменение отчета
    static void change_open_deposit(open_deposit &result);

    // поиск равного элемента по выбранному критерию
    static bool equals_open_deposit(open_deposit m, open_deposit n, int type_search);

    // ввод критерия поиска в зависимости от выбранного типа
    static open_deposit input_criteria_search_open_deposit(int type_search);

    // сравнения структур в зависимости от выбранного поля для сортировки
    static int compare_open_deposit(open_deposit n, open_deposit m, int type_search);
};
#endif /* open_deposit_hpp */
