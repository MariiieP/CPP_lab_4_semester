//
//  type_deposit.cpp
//  lab_3
//
//  Created by Мария Юрьевна on 04.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#include "type_deposit.h"
#include "help_file_name.h"

using namespace std;

//конструктор
type_deposit::type_deposit()
{
    string type_of_deposit = "";
    int percent = 0;
    bool take_sum = true;
}

//свойство вида вклада
string type_deposit::get_type_of_deposit()
{
    return type_of_deposit;
}

//свойство процентной ставки
int type_deposit::get_percent()
{
    return percent;
}

//свойство частичного снятия суммы
bool type_deposit::get_take_sum()
{
    return take_sum;
}

//ввод вида вклада с консоли
 type_deposit input_screen_type_deposit()
{
    type_deposit ob_type_deposit;
    ob_type_deposit.type_of_deposit = input_information("Введите вид вклада");
    ob_type_deposit.percent = input_information(0,"Введите процент");
    ob_type_deposit.take_sum = input_information(true,"Возможно снимать?");

    return ob_type_deposit;
}

//ввод вида вклада на консоль
 void output_screen_type_deposit(type_deposit obj_type_deposit)
{
    cout << setw(15) << setiosflags(ios::right) << obj_type_deposit.type_of_deposit << "|";
    cout << setw(10) << setiosflags(ios::right) << obj_type_deposit.percent << "|";
    cout << setw(10) << setiosflags(ios::right) << obj_type_deposit.take_sum << endl;
}

//запись в бинарный файл
 void write_type_deposit_to_binary_file(type_deposit obj_type_deposit, ofstream& ofs)
{
    string_in_binary_file(ofs, obj_type_deposit.type_of_deposit);
    ofs.write( (char*)&obj_type_deposit.percent, sizeof(int));
    ofs.write( (char*)&obj_type_deposit.take_sum, sizeof(bool) );           //????????????????????????????????
}

type_deposit read_type_deposit_to_binary_file(ifstream& in)
{
    type_deposit obj_type_deposit;

    obj_type_deposit.type_of_deposit = string_from_binary_file(in);
    in.read( (char*)&obj_type_deposit.percent, sizeof(int));
    in.read( (char*)&obj_type_deposit.take_sum, sizeof(bool) );         //??????????????????????????????????????????

    return obj_type_deposit;
}

//печать шапки
void output_cap_type_deposit()
{
    cout << setw(4) << setiosflags(ios::right) << "№" << "|";
    cout << setw(15) << setiosflags(ios::right) << "Вид вклада" << "|";
    cout << setw(10) << setiosflags(ios::right) << "Процент" << "|";
    cout << setw(10) << setiosflags(ios::right) << "Возможность снятия" << endl;
    cout << "------------------------------------------------" << endl;
}

//изменение типа работ
 void change_type_deposit(type_deposit &result)
{
    if (input_number(0, 1, "Вы хотите изменить вид вклада " + result.type_of_deposit + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
        result.type_of_deposit = input_information("Введите новый вид вклад : ");

    if (input_number(0, 1, "Вы хотите изменить процент " + to_string(result.percent) + " (0 - нет, 1 - да)\nВыш выбор: ") == 1)
        result.percent = input_information(0,"Введите новый процент: ");

    if (input_number(0, 1, "Вы хотите изменить возмодность снятия " + to_string(result.take_sum) + " (0-нет, 1 - да)\nВыш выбор: ") == 1)
        result.take_sum = input_information(true, "Введите новое значение: ");  //????????????
}

//поиск эквивалентного по выбранному критерию
 bool equals_type_deposit(type_deposit f,type_deposit s, int type_search)
{
    switch (type_search)
    {
        case 1:
            return (f.type_of_deposit == s.type_of_deposit);
        case 2:
            return (f.percent == s.percent);
        case 3:
            return (f.take_sum == s.take_sum);
        default:
            return false;
    }
}

//ввод критерия поиска в зависимости от выбранного типа
type_deposit input_search_type_deposit(int type_search)
{
type_deposit result;
switch (type_search)
{
    case 1:
        result.type_of_deposit = input_information("Введите твид вклада: ");
        return result;
    case 2:
        result.percent = input_information(0,"Введите процент: ");
        return result;
    case 3:
        result.take_sum = input_information(true, "Введите возможность снятия: ");
        return result;
    default:
        return result;
}

}

//сравнение в зависимости от выбранного критерия
int compare_type_deposit(type_deposit f,type_deposit s, int type_search)
{
    switch(type_search)
    {
        case 1:
            if (f.type_of_deposit > s.type_of_deposit) return 1;
            else if (f.type_of_deposit < s.type_of_deposit) return -1;
            else return 0;
        case 2:
            if (f.percent > s.percent) return 1;
            else if (f.percent < s.percent) return -1;
            else return 0;
        case 3:
            if (f.take_sum > s.take_sum) return 1;
            else if (f.take_sum < s.take_sum) return -1;
            else return 0;
        default:
            return -2;
    }
}

//bool operator ==(const type_deposit &a, type_deposit &b)
//{
//    double e = 0.001;
//    return ((a.type_of_deposit == b.type_of_deposit) && (a.percent == b.percent) && (abs(a.take_sum - b.take_sum) < e));
//}









