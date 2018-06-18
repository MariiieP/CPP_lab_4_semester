//
//  bank_account.c
//  test_3_C++
//
//  Created by Мария Юрьевна on 18.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//


#include "Data.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "help_file_name.h"

class bank_account {
private:
    int number_account; // номер счета
    int code_account; // код счета
    string surname;// фамилия владельца
    double sum_on_the_account;// сумма на счете
    Data date_account_opening;// дата открытия счета
    int year_percent;// годовой процент начисления
public:
    // конструктор по умолчанию
    bank_account();
    // изменение структуры "счет в банке"
    bank_account сhange_bank_account(bank_account &result);
    // функция ввода структуры "счет в банке" с консоли
    static bank_account input_screen_bank_account();
    // функция вывода структуры "счет в банке" на консоль
    static void output_screen_bank_account(bank_account c);
    //извлечение структуры "дата" из строки. Формат: день месяц год
    static Data from_string  /*hack()*/ (string str);
    //перевод структуры "счет в банке" в строку
    static string bank_account_to_string(bank_account c,int i);
    //считывание структуры "счет в банке" из строки
    static bank_account read_from_string(ifstream& input);
    //поиск равного элемента по владельцу
    static bool search_element_surname(bank_account m, bank_account n);
    //поиск равного элемента по номеру счета
    static bool search_element_number_account(bank_account m, bank_account n);
    //поиск равного элемента по по дате
    static bool search_element_surname_date_account_opening(bank_account m, bank_account n);
    /* ввод критерия поиска в зависимости от выбранного типа. type_search - тип поиска
     1 - по владельцу
     2 - по номеру счета
     3 - по дате */
    static bank_account input_change_type_search(int type_search);
    //сравнения структур по владельцу
    static bool sorte_surname(bank_account n, bank_account m);

    //сравнения структур по номеру счета
    static bool sorte_number_account(bank_account n, bank_account m);

    //сравнения структур по дате
    static bool sorte_date_account_opening(bank_account n, bank_account m);
};
