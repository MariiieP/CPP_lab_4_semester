//
//  test_3_C++
//
//  Created by Мария Юрьевна on 17.05.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "bank_account.h"
//#include "help_menu_-.h"

using namespace std;


template <class Type>
class Task {

    
public:

    vector<Type> vect;
    Task() {}
    ~Task() {}

     void remove( int numb)
    {
        if (numb != 0)
            vect.erase(vect.begin() + numb-1);
    }

    // добавление элемента
void add(Type &elem)
    {
        vect.push_back(elem);
    }

    //размер вектора
    int size()
    {
        return (int)vect.size();
    }

    // проверка на пустоту
    bool is_empty()
    {
        return (vect.size() == 0);
    }

    // вывод в фай. void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл
    void output_file(vector<Type> items,string (*f)(Type,int))
    {
        string newfname = input_file_name();
        ofstream fout(newfname, ios::out);
        if (fout)
        {
            int count = 1;
            for (auto pos = items.begin(); pos != items.end(); ++pos)
            {
                fout << f(*pos,count) << ' ';
                count++;
            }
            cout << endl << "Файл заполнен!" << endl;
            fout.close();
        }
        else
        {
            cout << "Файл не заполнен!" << endl;
        }
    }

    // вывод на экран. void(*f) (Type) - указатель на функцию, которая считывает одну структуру на экран
    void output_screen(vector<Type> items, void (*f) (Type))
    {
        int count = 1;
        for (auto pos = items.begin(); pos != items.end(); ++pos)
        {
            cout << "\nЗапись № " << count << endl;
            f(*pos);
            ++count;
        }
        cout << "Конец вывода!" << endl;
    }

    // ввод из файла. Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла
    bool read_from_file(Type(*f)(ifstream&))
    {
        string newfname = input_file_name();
        std::ifstream input;

        input.open(newfname);

        if (!input)
        {
            cout << "Не удалось открыть файл" << endl;
            return false;
        }
        else
        {
            while (!input.eof())
            {
                vect.push_back(f(input));
            }
            vect.erase(vect.begin() + vect.size() - 1);

            input.close();
            return true;
        }
    }

    // ввод с экрана. Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
    void read_from_screen(Type (*f)())
    {
        int n;
        Type elem;
        do
        {
            vect.push_back(f());
            n = input_number(0, 1, "Вы хотите добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
        } while (n != 0);
    }

    // линейный поиск. bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
    vector<Type> lineary_search(Type search_elem,bool(*Equal)(Type,Type))
    {
        vector<Type> new_vect;
        for (auto iter = vect.begin(); iter != vect.end(); iter++)
        {
            if (Equal(search_elem, *iter) )
                new_vect.push_back(*iter);
        }
        return new_vect;
    }

    /* бинарный поиск. int(*compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search
     bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search */
    vector<Type> Tbinary_search( Type find_element, bool(*compare)(Type, Type), bool(*Equal)(Type, Type))
    {
        vector<Type> new_vect;
        sort( vect.begin(), vect.end(), compare );
        auto  index =lower_bound(vect.begin(), vect.end(), find_element, compare);
        while( ( index !=vect.end() ) && Equal( *index, find_element) )
        {
          new_vect.push_back(*index);
          index++;
         }
        return new_vect;
    }

};


