//
//  client.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "client.h"


// конструктор
Client::Client()
{
    name_client = "";
}

// перегруженный конструктор
Client::Client(string cl_name)
{
    name_client = cl_name;
}

// св-во имени клиента
void Client::set_name_client(string value)
{
    name_client = value;
}

// функция ввода структуры "клиент банка" с консоли
Client Client::input_screen_client()
{
    Client c;
    c.name_client = input_information("Введите клиента: ");

    return c;
}

// функция вывода структуры "клиент банка" на консоль
void Client::o_utput_screen_client(Client c)
{
    cout << setw(15) << setiosflags(ios::left) << c.name_client << "|";
}

// запись в бинарный файл
void Client::write_client_firmy_file(Client c, ofstream& os)
{
    string_in_binary_file(os, c.name_client);
}

// чтение из бинарного файла
Client Client::read_client_file(ifstream& in)
{
    Client c;
    c.name_client = string_from_binary_file(in);

    return c;
}


// вывод на консоль заголовка таблицы с клиентами
void Client::output_screen_cap_client()
{
    cout << setw(4) << setiosflags(ios::left) << "№" << "|";
    cout << setw(15) << setiosflags(ios::left) << "Клиент" << "|";
    cout << "------------------------------------------------" << endl;
}

// оператор равенства
bool operator ==(const Client &a, const Client &b)//перегрузка ==
{
    return (a.name_client == b.name_client);
}
