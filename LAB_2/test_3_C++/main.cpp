//
//  main.cpp
//  test_3_C++
//
//  Created by Мария Юрьевна on 24.04.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//
//Задача 2,№1.
//Счет в банке представляет собой структуру с полями: номер счета, код счета, фамилия владельца, сумма на счете, дата открытия счета, годовой процент начисления. Поиск по номеру счета, дате открытия и владельцу.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "help_file_name.h"
#include "help_menu.cpp"
#include "bank_account.h"
using namespace std;

//template class Task<bank_account>;

int menu()
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
    int n = input_number(0, 9, "Ваш выбор: ");
    cout << "\n";
    return n;
}

int change_input_info()
{
    Task<bank_account> task;
    cout << " ||||||||||||||||||| ---Меню--- |||||||||||||||||||  " << endl;
    cout << "[1] - Заполнение контейнера с консоли" << endl;
    cout << "[2] - Заполнение контейнера из файла " << endl;
    cout << "[0] - Выход" << endl;

    int changemenu = input_number(0, 2, "Ваш выбор: ");
    switch (changemenu)
    {
        case 1:
            task.read_from_screen(input_screen_bank_account);
            break;

        case 2:
            task.read_from_file(read_from_string);
            break;

        default:
            cout << "Выход\n";
            return 0;
    }
    for(;;)
    {
        bank_account elem;
        bank_account search_elem;
        vector<bank_account> subset;
        int numb;
        bool ( *compare )( bank_account, bank_account ) = 0;
        bool ( *sort )( bank_account, bank_account) = 0;
        int n = menu();
        switch (n)
        {
            case 1:
                //task.add(input_screen_bank_account());
                break;

            case 2:
                task.output_screen(task.vect, output_screen_bank_account);
                task.remove(input_number(0, task.size(), "Введите номер удаляемого эл-та ( [0] - если передумали удалять): "));
                break;

            case 3:
                task.output_screen(task.vect, output_screen_bank_account);
                numb = input_number(0, task.size(), "Введите номер изменяеиого эл-та ( [0] - если передумали изменять): ");
                if (numb != 0)
                    task.vect[n-1] = elem.сhange_bank_account(task.vect[numb -1]);
                break;

            case 4:
                task.output_screen(task.vect,output_screen_bank_account);
                break;

            case 5:
                task.output_file(task.vect,bank_account_to_string);
                break;

            case 6:
                numb = input_number(1, 3, "Выберите тип поиска:\n 1 - по владельцу\n 2 - по номеру счета\n 3 - по дате\nВаш выбор: ");
                search_elem = input_change_type_search(numb);
                switch (numb)
                {
                    case 1:
                        compare = search_element_surname;
                        break;
                    case 2:
                        compare = search_element_number_account;
                        break;
                    case 3:
                        compare = search_element_surname_date_account_opening;
                        break;
                }
                subset = task.lineary_search(search_elem,compare);
                if (subset.size() != 0)
                    task.output_screen(subset, output_screen_bank_account);
                    else
                        cout << "Элементы не найдены" << endl;
                break;

            case 7:
                numb = input_number(1, 3, "Выберите тип поиска:\n 1 - по владельцу\n 2 - по номеру счета\n 3 - по дате\nВаш выбор:  ");
                search_elem = input_change_type_search(numb);
                switch (numb)
                {
                    case 1:
                        compare = search_element_surname;
                        sort = sorte_surname;
                        break;
                    case 2:
                        compare = search_element_number_account;
                        sort = sorte_number_account;
                        break;
                    case 3:
                        compare = search_element_surname_date_account_opening;
                        sort = sorte_date_account_opening;
                        break;
                }
                subset = task.binary_search(search_elem, sort, compare);
                if (subset.size() != 0)
                    task.output_screen(subset, output_screen_bank_account);
                else
                    cout << "Элементы не найдены" << endl;
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
}
