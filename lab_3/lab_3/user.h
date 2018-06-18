//
//  user.hpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>
#include "help_menu.h"
#include "type_deposit.h"
#include "help_file_name.h"
#include "client.h"
#include "open_deposit.h"


class user {
protected:
    // имя файла пользователей
    string file_client;

    // имя файла видов вкладов
    string file_type_deposit;

    //имя файла отчетов видов кладов
    string file_open_deposit;

    // имя пользователя
    string name;

    //список пользователей
    Task<Client> list_client;

    //список с отчетами о видах вклада
    Task<open_deposit> list_open_deposit;

    // список с доступными видами вклада
    Task<type_deposit> list_type_deposit;

public:

    // конструктор
    user(string _name, string _file_client, string file_open_deposit,string _file_type_deposit);

    // посмотреть доступные виды вкладов по выбранному критерию
    void search_type_work();

    // посмотреть все доступные виды вкладов
    void read_all_type_work();

    // ЧИСТО виртуальная функция меню
    virtual void menu() = 0;//????????????????????????????????

    // выход
    void close();

};
#endif /* user_hpp */
