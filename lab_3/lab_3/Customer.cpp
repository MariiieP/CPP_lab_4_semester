//
//  Customer.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 18.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "Customer.h"
#pragma once
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "TypeWork.h"
#include "Operation.h"
#include "Report.h"
#include "User.h"
#include "Customer.h"



// конструктор
Customer::Customer(string _name, bool _status, string _file_client, string _file_report_work, string _file_type_work):User(_name,  _file_client, _file_report_work, _file_type_work)
{
    ClientFirmy client;
    client.set_Name_Client(_name);
    client.set_Status(_status);

    // если клиент раньше не был зарегестрирован, то добавляем в список клиентов
    if (!listClientFirmy.SearchEquals(client))
        listClientFirmy.Add(client);

    // регистрация методов
    Register("1 - Добавить отчет о заказе", &Customer::AddOrder);
    Register("2 - Посмотреть отчеты о заказах", &Customer::ReadAllReportWork);
    Register("3 - Посмотреть типы работ", &Customer::ReadAllTypeWork);
    Register("4 - Поиск типа работ", &Customer::SearchTypeWork);
    Register(" ------------------------------------------------\n5 - Выход", &Customer::Close);
}

// добавить заказ ( имя не вводится, а берется имя пользователя)
void Customer::AddOrder()
{
    listTypeWork.OutputScreen(listTypeWork.vect, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
    int numb = InputNumber(0, listTypeWork.size(), "Выберите тип работы (0 - если передумали заказывать): ");
    if (numb != 0)
    {
        listReportWork.Add(ReportWork::Input(name,listTypeWork.vect[numb - 1]));
        listReportWork.OutputFile(listReportWork.vect, ReportWork::WriteReportWorkToFile, file_report_work);
        cout << "Информация добавлена!" << endl;
    }
}


// посмотреть все отчеты ( пользователь видит только свои)
void Customer::ReadAllReportWork()
{
    if (listReportWork.Is_empty())
        cout << "Нет отчетов\n" ;
    else
    {
        // только для имени вашей компании
        ReportWork your_reports;
        your_reports.set_Name(name);
        vector<ReportWork> subset = listReportWork.LinearySearch(your_reports, ReportWork::EqualsReportWork, 1);
        if (subset.size() != 0)
            listReportWork.OutputScreen(subset, ReportWork::OutputScreenReportWork, ReportWork::OutputScreenHeaderReportWork);
        else
            cout << "Ваши отчеты не найдены!" << endl;
    }
}

// регистрация метода
void Customer::Register(string _nmFunction, DynamicFunction _function)
{
    menuNames.push_back(_nmFunction);
    menuFunctions.push_back(_function);
}

// вызов метода
void Customer::Invoke(int index)
{
    (this->*menuFunctions[index-1])();
}

// меню
void Customer::Menu()
{
    while (1)
    {
        cout << " --------------------Меню------------------------" << endl;
        for (int i = 0; i < menuNames.size(); i++)
        {
            cout << menuNames[i] << endl;
        }
        cout << " ------------------------------------------------" << endl;
        int n = InputNumber(1, menuNames.size(), "Ваш выбор: ");
        Invoke(n);
        if (n == menuNames.size())
            break;
    }
}
