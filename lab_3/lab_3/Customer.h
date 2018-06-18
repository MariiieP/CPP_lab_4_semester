//
//  Customer.hpp
//  lab_3
//
//  Created by Мария Юрьевна on 18.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#ifndef Customer_h
#define Customer_h

#include <stdio.h>
#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "help_file_name.h"
#include "type_deposit.h"
#include "help_menu.h"
#include "open_deposit.h"
#include "user.h"

// класс пользователя ( заказчика )
class Customer : public user
{
private:
    // тип указателя на ф-ю
    typedef void (Customer::*DynamicFunction)();

    // вектор ссылок на методы класса
    vector<DynamicFunction> menuFunctions;

    // вектор имен методов
    vector<string> menuNames;

    // регистрация метода
    void Register(string _nmFunction, DynamicFunction _function);

    // вызов метода по индексу
    void Invoke(int index);
protected:
    // статус пользователя
    bool status;
public:
    // конструкткор
    Customer(string _name, bool _status, string _file_client, string _file_report_work, string _file_type_work);

    // добавить заказ
    void AddOrder();

    // посмотреть все отчеты
    void ReadAllReportWork();

    // меню
    void Menu();

};

#endif /* Customer_h */
