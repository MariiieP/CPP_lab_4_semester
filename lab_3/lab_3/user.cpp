//
//  user.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 05.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "user.h"


// конструктор
user::user(string _name, string _file_client, string _file_open_deposit, string _file_type_deposit)
{
    name = _name;
    file_client = _file_client;
    file_open_deposit = _file_open_deposit;
    file_type_deposit = _file_type_deposit;


    list_client.read_from_file(Client::read_client_file, file_client);

    list_open_deposit.read_from_file(open_deposit::read_open_deposit_file,_file_open_deposit);

    list_type_deposit.read_from_file(type_deposit::read_type_deposit_to_binary_file, _file_type_deposit);

}


// поиск типа работ
void user::search_type_work()
{
    bool ( *compare )( type_deposit, type_deposit ) = NULL;
    if (list_type_deposit.is_empty())
        cout << "Нет типов работ";
    else
    {
        int numb = input_number(1, 3, "Выберите тип поиска:\n 1 - по владельцу\n 2 - по номеру счета\n 3 - по дате\nВаш выбор:  ");
        type_deposit search_elem = type_deposit::input_search_type_deposit(numb);
        vector<type_deposit> subset = list_type_deposit.lineary_search(search_elem, compare/*type_deposit::equals_type_deposit*/);

        // линейный поиск. bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
       // vector<Type> lineary_search(Type search_elem,bool(*Equal)(Type,Type))


        if (subset.size() != 0)
            list_type_deposit.output_screen(subset, type_deposit::output_screen_type_deposit/*, type_deposit::output_cap_type_deposit()*/);
        else
            cout << "Тип работы не найден!" << endl;
    }
}// void output_file(vector<Type> items,string (*f)(Type,int))

// посмотреть все типы работ
void user::read_all_type_work()
{
    list_type_deposit.output_screen(list_type_deposit.vect, type_deposit::output_screen_type_deposit/*, type_deposit::output_cap_type_deposit*/);
}

// выход
void user::close()
{
    list_client.output_file(list_client.vect, Client::write_client_firmy_file/*, file_client*/);
    list_open_deposit.output_file(list_open_deposit.vect, open_deposit::write_open_deposit_file/*,file_open_deposit */);
    list_type_deposit.output_file(list_type_deposit.vect, type_deposit::write_open_deposit_file, file_type_deposit);
}





