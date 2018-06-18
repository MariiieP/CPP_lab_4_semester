//
//  Administrator.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 18.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "Administrator.h"
#pragma once
#include <iostream>
#include <string>
#include "help_file_name.h"
#include "type_deposit.h"
#include "help_menu.h"
#include "open_deposit.h"
#include "user.h"
#include "Administrator.h"



// класс администратора
Administrator::Administrator(string _name, string _file_client, string _file_report_work, string _file_type_work):user(_name, _file_client, _file_report_work, _file_type_work)
{
    // регистрация методов класса администратор
    Register("1 - Добавить отчет о заказе", &Administrator::AddOrder);
    Register("2 - Посмотреть отчеты о заказах", &Administrator::ReadAllReportWork);
    Register("3 - Посмотреть типы работ", &Administrator::ReadAllTypeWork);
    Register("4 - Поиск типа работ", &Administrator::SearchTypeWork);
    Register("5 - Поиск отчетов о заказе", &Administrator::SearchReportWork);
    Register("6 - Изменить отчет о заказе", &Administrator::ChangeReportWorking);
    Register("7 - Удалить отчет о заказе", &Administrator::DeleteReportWork);
    Register("8 - Добавить тип работ", &Administrator::AddTypeWork);
    Register("9 - Изменить тип работы", &Administrator::ChangeTypeWorking);
    Register("10 - Удалить тип работы", &Administrator::DeleteTypeWork);
    Register("11 - Просмотреть пользователей", &Administrator::ReadClients);
    Register(" ------------------------------------------------\n12 - Выход", &Administrator::Close);
}

// добавление отчета о заказе
void Administrator::AddOrder()
{
    string nm_com = InputInformation("Введите имя(наименование компании) : ");
    listTypeWork.OutputScreen(listTypeWork.vect, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
    int numb = InputNumber(0, listTypeWork.size(), "Выберите тип работы (0 - если передумали заказывать): ");
    if (numb != 0)
    {
        listReportWork.Add(ReportWork::Input(nm_com, listTypeWork.vect[numb-1]));
        listReportWork.OutputFile(listReportWork.vect, ReportWork::WriteReportWorkToFile, file_report_work);
        cout << "Информация добавлена!" << endl;
    }
}

// добавление типа работ
void Administrator::AddTypeWork()
{
    TypeWork tp = TypeWork::InputScreenTypeWork();
    // если типа работа нет в списке ранее
    if (!listTypeWork.SearchEquals(tp))
    {
        // добавляем новый тип работы
        listTypeWork.Add(tp);
        listTypeWork.OutputFile(listTypeWork.vect, TypeWork::WriteTypeWorkToFile, file_type_work);
        cout << "Информация добавлена!" << endl;
    }
    else
        cout << "Тип работы уже есть!" << endl;
}

// изменить доступные работы по выбранному критерию
void Administrator::ChangeTypeWorking()
{
    if (listTypeWork.Is_empty())
        cout << "Нет типов работ";
    else
    {
        listTypeWork.OutputScreen(listTypeWork.vect, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
        int numb = InputNumber(0, listTypeWork.size(), "\nВведите номер изменяемой записи (0 - если передумали изменять): ");
        if (numb != 0)
        {
            TypeWork::ChangeTypeWork(listTypeWork.vect[numb - 1]);
            listTypeWork.OutputFile(listTypeWork.vect, TypeWork::WriteTypeWorkToFile, file_type_work);
            cout << "Запись изменена!" << endl;
        }
    }
}

// удалить доступный тип работы
void Administrator::DeleteTypeWork()
{
    if (listTypeWork.Is_empty())
        cout << "Нет типов работ";
    else
    {
        listTypeWork.OutputScreen(listTypeWork.vect, TypeWork::OutputScreenTypeWork, TypeWork::OutputScreenHeaderTypeWork);
        listTypeWork.Remove(InputNumber(0, listTypeWork.size(), "\nВведите номер удаляемого эл-та (0 - если передумали удалять): "));
        listTypeWork.OutputFile(listTypeWork.vect, TypeWork::WriteTypeWorkToFile, file_type_work);
    }
}


// посмотреть все отчеты
void Administrator::ReadAllReportWork()
{
    listReportWork.OutputScreen(listReportWork.vect, ReportWork::OutputScreenReportWork, ReportWork::OutputScreenHeaderReportWork);
}

// удалить отчет
void Administrator::DeleteReportWork()
{
    if (listTypeWork.Is_empty())
        cout << "Нет отчетов о работах";
    else
    {
        listReportWork.OutputScreen(listReportWork.vect, ReportWork::OutputScreenReportWork, ReportWork::OutputScreenHeaderReportWork);
        listReportWork.Remove(InputNumber(0, listReportWork.size(), "\nВведите номер удаляемого эл-та (0 - если передумали удалять): "));
        listReportWork.OutputFile(listReportWork.vect, ReportWork::WriteReportWorkToFile, file_report_work);
    }
}

// поиск отчета о заказе
void Administrator::SearchReportWork()
{
    if (listReportWork.Is_empty())
        cout << "Нет отчетов о работах";
    else
    {
        int numb = InputNumber(1, 3, "Выберите тип поиска:\n 1 - по имени ( наименование компании )\n 2 - по единице измерения\n 3 - по дате \nВаш выбор: ");
        ReportWork search_elem = ReportWork::InputCriteriaSearchReportWork(numb);
        vector<ReportWork> subset = listReportWork.LinearySearch(search_elem, ReportWork::EqualsReportWork, numb);
        if (subset.size() != 0)
            listReportWork.OutputScreen(subset, ReportWork::OutputScreenReportWork, ReportWork::OutputScreenHeaderReportWork);
        else
            cout << "Элементы не найдены" << endl;
    }
}

// изменить отчет
void Administrator::ChangeReportWorking()
{
    if (listReportWork.Is_empty())
        cout << "Нет отчетов о работах";
    else
    {
        listReportWork.OutputScreen(listReportWork.vect, ReportWork::OutputScreenReportWork, ReportWork::OutputScreenHeaderReportWork);
        int numb = InputNumber(0, listReportWork.size(), "Введите номер изменяемого эл-та (0 - если передумали изменять): ");
        if (numb != 0)
        {
            ReportWork::ChangeReportWork(listReportWork.vect[numb - 1]);
            listReportWork.OutputFile(listReportWork.vect, ReportWork::WriteReportWorkToFile, file_report_work);
            cout << "Элемент изменен!" << endl;
        }
    }
}

// посмотреть пользователей
void  Administrator::ReadClients()
{
    cout << "Пользователи:" << endl;
    listClientFirmy.OutputScreen(listClientFirmy.vect, ClientFirmy::OutputScreenClientFirmy, ClientFirmy::OutputScreenHeaderClientFirmy);
}

// регистрация метода
void Administrator::Register(string _nmFunction, DynamicFunction _function)
{
    menuNames.push_back(_nmFunction);
    menuFunctions.push_back(_function);
}

// вызов метода по индексу из вектора ссылок
void Administrator::Invoke(int index)
{
    (this->*menuFunctions[index-1])();
}

// меню
void Administrator::Menu()
{
    while (1)
    {
        cout << " \n--------------------Меню------------------------" << endl;
        for (int i = 0; i < menuNames.size(); i++)
        {
            cout << menuNames[i] << endl;
        }
        cout << " \n------------------------------------------------" << endl;
        int n = InputNumber(1, menuNames.size(), "Ваш выбор: ");
        Invoke(n);
        if (n == menuNames.size())
            break;
    }
}

