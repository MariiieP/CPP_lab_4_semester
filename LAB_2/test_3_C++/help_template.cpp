//
//  help_template.cpp
//  test_3_C++
//
//  Created by Мария Юрьевна on 02.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "help_template.h"
//#include "help_template.h"

//using namespace std;

template <typename Type>
Corrects<Type>::Corrects(){}
template <typename Type>
Corrects<Type>::~Corrects(){}


template <typename Type>
//class Correct
//{
Type Corrects<Type>::input_number(Type min, Type max,string message)
    {
        Type n;
        do
        {
            cout << message ;
            while ((!(cin >> n)) || cin.get() != '\n')
            {
                cout << "Неправильный ввод !!  Повторите ввод!\n";
                cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
                cout << message  ;
                getchar();
            }
        } while ((n < min) || (n > max));
        return n;
    }


//};
