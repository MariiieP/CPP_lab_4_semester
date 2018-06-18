//
//  main.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//
//Задача 3,№1.
//Счет в банке представляет собой структуру с полями: номер счета, код счета, фамилия владельца, сумма на счете, дата открытия счета, годовой процент начисления. Поиск по номеру счета, дате открытия и владельцу.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "help_file_name.h"
#include "help_menu.h"
#include "bank_account.h"
#include  "Data.h"

using namespace std;


// 3)Реализовать виртуальный магазин ПК. Магазин должен иметь два режима работы — клиент и сотрудник (выбирается в меню).
//Сотрудник имеет возможность управления магазином: добавление, редактирование, удаление моделей ПК.
//Предусмотреть вывод списка моделей ПК с сортировкой и/или фильтрацией по выбранному полю.
//Пользователь имеет возможность поиска ПК по заданному критерию (любое поле, для полей типа цены и объема памяти — предусмотреть ввод диапазона)
//и покупки выбранного ПК. Предусмотреть хранение истории покупок и просмотр истории сотрудником.

#include <stdio.h>
//#include "stdafx.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include "help_file_name.h"
#include "user.h"
#include "Customer.h"
#include "Administrator.h"

using namespace std;

void Shop()
{

    user *user;

    string name_client;

    string filename_model_PC = "files\\PC.dat";
    string filename_history_buy = "files\\buy.dat";

    while (1)
    {
        cout << " --------------------Меню---------------------  " << endl;
        cout << "1 - Зайти как клиент" << endl;
        cout << "2 - Зайти как сотрудник " << endl;
        cout << "0 - Выход" << endl;
        int changemenu = input_number(0, 2, "---> ");
        switch (changemenu)
        {
            case 1:
                name_client = input_information("Режим клиента\n Введите имя : ");
                user = new Client(name_client, filename_model_PC, filename_history_buy);
                user->Menu();
                break;

            case 2:
                cout << "Режим сотрудника" << endl;
                user = new Worker(filename_model_PC, filename_history_buy);
                user->Menu();
                break;

            default:
                exit(1);
                break;
        }
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Shop();
}
/*int menu()
{
    cout << "\n";
    cout << " ||||||||||||||||||| ---Меню--- |||||||||||||||||||  " << endl;
    cout << "[1] - Добавить элемент в контейнер" << endl;
    cout << "[2] - Удалить элемент из контейнера" << endl;
    cout << "[3] - Изменить элемент в контейнере" << endl;
    cout << "[4] - Вывод на экран" << endl;
    cout << "[5] - Сохранить в файл " << endl;
    cout << "[6] - Линейный поиск" << endl;
    cout << "[7] - Двоичный поиск" << endl;
    cout << "[0] - Выход" << endl;
    int n = input_number(0, 8, "Ваш выбор: ");
    cout << "\n";
    return n;
}

void menu_item_lineary_search(Task<bank_account> task)
{
    int numb;
    vector<bank_account> subset;
    bank_account elem;
    bool ( *compare )( bank_account, bank_account ) = NULL;
    numb = input_number(1, 3, "Выберите тип поиска:\n 1 - по владельцу\n 2 - по номеру счета\n 3 - по дате\nВаш выбор: ");
    elem = elem.input_change_type_search(numb);
    switch (numb)
    {
        case 1:
            compare = elem.search_element_surname;
            break;
        case 2:
            compare = elem.search_element_number_account;
            break;
        case 3:
            compare = elem.search_element_surname_date_account_opening;
            break;
    }
    subset = task.lineary_search(elem,compare);
    if (subset.size() != 0)
        task.output_screen(subset, elem.output_screen_bank_account);
    else
        cout << "Элементы не найдены" << endl;
}

void menu_item_binary_search(Task<bank_account> task)
{
    int numb;
    vector<bank_account> subset;
    bank_account elem;
    bool ( *compare )( bank_account, bank_account ) = NULL;
    bool ( *sort )( bank_account, bank_account) = NULL;
    numb = input_number(1, 3, "Выберите тип поиска:\n 1 - по владельцу\n 2 - по номеру счета\n 3 - по дате\nВаш выбор:  ");
    elem = elem.input_change_type_search(numb);
    switch (numb)
    {
        case 1:
            compare = elem.search_element_surname;
            sort = elem.sorte_surname;
            break;
        case 2:
            compare = elem.search_element_number_account;
            sort = elem.sorte_number_account;
            break;
        case 3:
            compare = elem.search_element_surname_date_account_opening;
            sort = elem.sorte_date_account_opening;
            break;
    }
    subset = task.Tbinary_search(elem, sort, compare);
    if (subset.size() != 0)
        task.output_screen(subset, elem.output_screen_bank_account);
    else
        cout << "Элементы не найдены" << endl;
}

int menu_user()
{
    cout << "\n";
    cout << " ||||||||||||||||||| ---Меню--- |||||||||||||||||||  " << endl;
    cout << "[1] - Открыть счет" << endl;
    cout << "[2] - Закрыть счет" << endl;
    cout << "[3] - Снять часть средств со счета"<< endl;
    cout << "[4] - Посмотреть остаток средств на счетах" << endl;
    cout << "[0] - Выход" << endl;
    int n = input_number(0, 5, "Ваш выбор: ");
    cout << "\n";
    return n;
}

int change_input_info()
{
    Task<bank_account> task;
    bank_account elem;
    cout << " ||||||||||||||||||| ---Меню--- |||||||||||||||||||  " << endl;
    cout << "[1] - Режим пользователя" << endl;
    cout << "[2] - Режим сотрудника" << endl;
    cout << "[10] - Выход" << endl;

    int changemenu = input_number(0, 2, "Ваш выбор: ");
    for(;;)
    {
    int numb;
    switch (changemenu)
    {
        case 1:
        {
            int number_user = menu_user();
            switch (number_user)
            {
                case 1:
                    task.read_from_screen(elem.input_screen_bank_account);
                    break;
                case 2:
                    task.output_screen(task.vect, elem.output_screen_bank_account);
                    task.remove(input_number(0, task.size(), "Введите номер удаляемого эл-та ( [0] - если передумали удалять): "));
                    break;
                case 3:
                    task.output_screen(task.vect, elem.output_screen_bank_account);
                    numb = input_number(0, task.size(), "Введите номер изменяеиого эл-та ( [0] - если передумали изменять): ");
                    if (numb != 0)
                        task.vect[number_user-1] = elem.сhange_sum_on_the_account(task.vect[numb -1]);
                    break;

                case 4:
                    task.output_screen(task.vect, elem.output_screen_year_present);
                    break;
                case 5:
                    break;
                default:
                    cout << "Выход " << endl; exit(0);
                    break;
            }
        }


        case 2:
        {
            int nr_user = menu_user();
            switch (nr_user)
            {
                case 1:
                    cout << "Выход eddfef" << endl;
                    break;
                case 2:
                case 3:
                case 4:
                default:
                    cout << "Выход " << endl; exit(0);
                    break;
            }
        }
           // task.read_from_file(elem.read_from_string);
            //break;

//        default:
//            cout << "Выход\n";
//            return 0;
            break;
    }

    }
    for(;;)
    {
        vector<bank_account> subset;
        int numb;
        int n = menu();
        switch (n)
        {
            case 1: {
                auto ba = bank_account::input_screen_bank_account();
                task.add(ba);
                break;
            }
            case 2: {
                task.output_screen(task.vect, elem.output_screen_bank_account);
                task.remove(input_number(0, task.size(), "Введите номер удаляемого эл-та ( [0] - если передумали удалять): "));
                break;
            }
            case 3:
                task.output_screen(task.vect, elem.output_screen_bank_account);
                numb = input_number(0, task.size(), "Введите номер изменяеиого эл-та ( [0] - если передумали изменять): ");
                if (numb != 0)
                    task.vect[n-1] = elem.сhange_bank_account(task.vect[numb -1]);
                break;

            case 4:
                task.output_screen(task.vect,elem.output_screen_bank_account);
                break;

            case 5:
              //  task.output_file(task.vect,elem.bank_account_to_string,bank_account_to_string);
                break;

            case 6:
                menu_item_lineary_search(task);
                break;

            case 7:
                menu_item_binary_search(task);
                break;


            default:
                cout << "Выход " << endl; exit(0);
                break;
        }
    }
}

int main()
{
    //    system("mode con cols=80 lines=25");
    //    HANDLE nwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //    COORD bufferSize ={80,50};
    //    SetConsoleScreenBufferSize(wHnd,bufferSize);
    setlocale(LC_ALL, "Russian");
    change_input_info();
}*/
