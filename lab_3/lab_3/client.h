//
//  client.hpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef client_hpp
#define client_hpp

#include <stdio.h>
#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "help_file_name.h"
#include "type_deposit.h"



// класс клиент фирмы
class Client
{
private:
    // имя
    string name_client;
public:
    // конструктор
    Client();

    // перегруженный конструктор
    Client(string cl_name);

    // св-во имени
    void set_name_client(string value);

    // функция ввода структуры "клиент банка" с консоли
    static Client input_screen_client();

    //функция вывода структуры "клиент банка" на консоль
    static void o_utput_screen_client(Client c);

    //запись в бинарный файл
    static void write_client_firmy_file(Client a, ofstream& os);

    // считывание из бинарного файла
    static Client read_client_file(ifstream& in);

    // вывод заголовка на экран
    static void output_screen_cap_client();

    // перегруженный оператор равенства
    friend bool operator ==(const Client &a, const Client &b); //перегрузка ==
};
#endif /* client_hpp */
