//
//  open_deposit.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "open_deposit.h"



// конструктор
open_deposit::open_deposit()
{
    //имя вкладчика
    string name_client = "";
    // вид вклада
    string type_of_deposit = "";
    // срок вклада
    string time_deposit = "";
    // дата открытия вклада
    string date_open_deposit;
    // осумма на счету
    int sum_account = 0;

}

// св-во для имени
void open_deposit::set_name(string value)
{
    name_client = value;
}


// функция ввода структуры "вклад" с консоли
open_deposit open_deposit::input_screen_open_deposit()
{
    open_deposit c;
    Data t;
    c.name_client = input_information("Введите наименование: ");
    c.type_of_deposit = input_information("Введите вид вклада: ");
    c.time_deposit = input_information("Введите срок вклада: ");
    t.input_date();
    c.date_open_deposit = t.date_to_string();
    c.sum_account = input_number(0, 999999, "Введите сумму на счету");
    return c;
}

// функция ввода структуры "отчет" для администратора
open_deposit open_deposit::input(string _nc, type_deposit td)
{
    open_deposit obj_open_deposit;
    Data t;
    obj_open_deposit.name_client = _nc;
    obj_open_deposit.type_of_deposit = td.get_type_of_deposit();
    obj_open_deposit.time_deposit = td.get_time_deposit();
    t.input_date();
    obj_open_deposit.date_open_deposit = t.date_to_string();
    obj_open_deposit.sum_account = td.get_sum_account();
    return obj_open_deposit;
}

// функция вывода структуры "вклад" на консоль
void open_deposit::output_screen_open_deposit(open_deposit c)
{
    cout << setw(15) << setiosflags(ios::left) << c.name_client << "|";
    cout << setw(15) << setiosflags(ios::left) << c.type_of_deposit << "|";
    cout << setw(10) << setiosflags(ios::left) << c.time_deposit << "|";
    cout << setw(15) << setiosflags(ios::left) << c.date_open_deposit << "|";
    cout << setw(15) << setiosflags(ios::left) << c.sum_account << endl;
}

// запись в бинарный файл
void open_deposit::write_open_deposit_file(open_deposit a, ofstream& os)
{
    string_in_binary_file(os, a.name_client);
    string_in_binary_file(os, a.type_of_deposit);
    string_in_binary_file(os, a.time_deposit);
    string_in_binary_file(os, a.date_open_deposit);
    os.write((char*)&a.sum_account, sizeof(int));
}

// считывание из бинарного файла
open_deposit open_deposit::read_open_deposit_file(ifstream& in)
{
    open_deposit obj_open_deposit;

    obj_open_deposit.name_client = string_from_binary_file(in);
    obj_open_deposit.type_of_deposit = string_from_binary_file(in);
    obj_open_deposit.time_deposit = string_from_binary_file(in);
    obj_open_deposit.date_open_deposit = string_from_binary_file(in);
    in.read((char*)&obj_open_deposit.sum_account, sizeof(int));

    return obj_open_deposit;
}

// вывод на консоль заголовка
void open_deposit::output_screen_cap_open_deposit()
{
    cout << setw(15) << setiosflags(ios::left) << "Вкладчик" << "|";
    cout << setw(15) << setiosflags(ios::left) <<"Вид вклада" << "|";
    cout << setw(15) << setiosflags(ios::left) << "Срок вклада" << "|";
    cout << setw(15) << setiosflags(ios::left) <<"Дата открытия" << "|";
    cout << setw(15) << setiosflags(ios::left) << "Сумма на счету" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}




