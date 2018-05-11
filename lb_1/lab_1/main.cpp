//
//  main.cpp
//  lab_1
//
//  Created by Мария Юрьевна on 04.04.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//
//Разделить все нечетные по абсолютной величине числа на среднее арифметическое всех чисел.
//
//. 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <string>
#include "math.h"
using namespace std;


class class_container_deq
{
private:
    double arithmetical_mean;
public:
    class_container_deq(const double& _Val) :arithmetical_mean(_Val) {
    }
    
    double operator ( ) (double& elem) const
    {
        if (remainder(elem, 2) != 0)
            elem = arithmetical_mean;
        return elem;
    }
};

class random_range
{
private:
    int M;
public:
    random_range(const int& Value) : M(Value) {
    }
    int operator () () const
    {
        return rand() % (2 * M + 1) - M;
    }
};

int random(int M)
{
    return rand() % (2 * M + 1) - M;
}

// проверка корректности символа в имени файла
bool correct_symbol(char c)
{
    switch (c)
    {
        case '/':
        case ':':
        case '*':
        case '?':
        case '"':
        case '<':
        case '|':
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '(':
        case ')':
        case '_':
        case '-':
        case '+':
        case '=':
        case '[':
        case ']':
        case ';':
            
            return false;
        default:
            return true;
    }
}

// проверка корректности имени
bool correct_name(string name)
{
    int i;
    i= 1;
    bool goodsymbol = true;
    for(int i = 1; (i < name.length() && goodsymbol);i++)
        goodsymbol = correct_symbol(name[i++]);
    return goodsymbol;
}

//ввод имени файла
string input_file_name()
{
    char *filename;
    filename = new char[30];
    
    do
    {
        cout << "Введите имя файла(без расширения):  ";
        cin >> filename;
        if (correct_name(filename))
        {
            strcat(filename, ".txt");//объединение строк конкотенацией
            break;
        }
        else
            cout << "Файл не удалось создать\n";
    } while (true);
    
    return filename;
}

// заполнение файла случайными числами
ofstream in_text_file(string filename,int N, int M)
{
    ofstream file(filename);
    deque<double> deq_numbers;
    srand((unsigned int)time(0));
    for (int i = 1; i < N; i++)
        deq_numbers.push_back(random(M));
    copy(deq_numbers.begin(), deq_numbers.end(), ostream_iterator<int>(file," "));
    file.close();
    return file;
    
}

// заполнение файла случайными числами через generate
ofstream in_text_fileIn_generate(string filename,int N, int M)
{
    ofstream file(filename);
    deque<double> deq_numbers(N);
    srand((unsigned int)time(0));
    generate(deq_numbers.begin(), deq_numbers.end(), random_range(M));
    copy(deq_numbers.begin(), deq_numbers.end(), ostream_iterator<int>(file, " "));
    file.close();
    return file;
}

// загрузка чисел из файла в очередь
deque<double> load_from_file(string filename)
{
    ifstream file(filename);
    deque<double> deq_numbers;
    double x;
    while (!file.eof())
    {
        file >> x;
        deq_numbers.push_back(x);
    }
    file.close();
    return deq_numbers;
}

// печать очереди в файл
void PrintFile(string filename,deque<double> &items)
{
    ofstream fout;
    fout.open(filename, ios::out);
    if (fout)
    {
        for (auto pos = items.begin(); pos != items.end(); ++pos)
        {
            fout << *pos << ' ';
        }
        cout << endl << "Файл выведен!" << endl;
        fout.close();
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
}


// печать очереди на экран
void output_screen(deque<double> &items)
{
    for (auto pos = items.begin(); pos != items.end(); ++pos)
    {
        cout << *pos << ' ';
    }
    cout << endl;
}

// функция  для вычисления суммы
int sum(deque<double> &deq_numbers)
{
    int sum = 0;
    for (auto iter = deq_numbers.begin(); iter != deq_numbers.end(); iter++)
    {
        sum += *iter;
    }
    return sum;
}




// функция  для вычисления среднего арифметоческого (через итераторы)
double average(deque<double>::iterator begin, deque<double>::iterator end)
{
    int summ = 0;
    int col = 0;
    for (auto iter = begin; iter != end; iter++)
    {
        summ += *iter;
        col++;
    }
    return (double)summ / col;
}


// функция  для вычисления среднего арифметоческого
double average(deque<double> &deq_numbers)
{
    return average(deq_numbers.begin(), deq_numbers.end());
}



// перегруженная функция modify для изменения очереди
deque<double> modify(deque<double>::iterator begin, deque<double>::iterator end)
{
    deque<double> deq_numbers;
    double arithmetical_mean = average(begin, end);
    for (auto iter = begin; iter != end; iter++)
    {
        if (remainder(*iter, 2) != 0)
        {
            *iter = arithmetical_mean;
        }
        deq_numbers.push_back(*iter);
    }
    return deq_numbers;
}

// функция modify для изменения очереди
deque<double> modify(deque<double> &deq_numbers)
{
    return modify(deq_numbers.begin(), deq_numbers.end());
}

// функция  для изменения очереди через transform
void transform_deque(deque<double> &deq_numbers)
{
    double arithmetical_mean = average(deq_numbers);
    transform(deq_numbers.begin(), deq_numbers.end(), deq_numbers.begin(), class_container_deq(arithmetical_mean));
}

// функция  для изменения очереди через for_each
void for_each_deque(deque<double> &deq_numbers)
{
    double arithmetical_mean = average(deq_numbers);
    for_each(deq_numbers.begin(), deq_numbers.end(), class_container_deq(arithmetical_mean));
}



int input_number(int min, int max)
{
    int n = -1;
    do
    {
        cout << "Ваш выбор: ";
        while ((!(cin >> n)) || cin.get() != '\n')
        {
            cout << "Неправильный ввод !!  Повторите снова!\n";
            cin.clear();
            cin.sync();
            cout << "Ваш выбор : ";
        }
    } while ((n < min) || (n > max));
    return n;
}

int menu()
{
    cout << " _____________________Меню___________________ " << endl;
    cout << "1 - modify(преобразование очереди)" << endl;
    cout << "2 - modify(преобразование очереди - перегруженный вариант) " << endl;
    cout << "3 - Преобразование с помощью transform" << endl;
    cout << "4 - Преобразование с помощью for_each" << endl;
    cout << "5 - Посчитать сумму" << endl;
    cout << "6 - Посчитать среднее арифметическое" << endl;
    cout << "7 - Вывод на экран " << endl;
    cout << "8 - Вывод в файл" << endl;
    cout << "0 - Выход " << endl;
    int n = input_number(0, 8);
    cout << "\n";
    return n;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    ofstream OutputFile;
    string filename = "";
    deque<double> deq_numbers;
    int N ;
    int M ;
    int changemenu;

    
    cout << " _____________________Меню___________________  " << endl;
    cout << "1 - Заполнение текстового файла случайными числами(цикл)" << endl;
    cout << "2 - Заполнение текстового файла случайными числами(generate) " << endl;
    cout << "0 - Выход" << endl;
    changemenu = input_number(0, 2);
    switch (changemenu)
    {
        case 1:
        {
            filename = input_file_name();
            cout << ("введите число N") << endl;
            cin >> N;
            cout << ("введите число M") << endl;
            cin >> M;
            OutputFile = in_text_file(filename, N, M);
            break;
        }
            
        case 2:
        {
            filename = input_file_name();
            cout << ("введите число N") << endl;
            cin >> N;
            cout << ("введите число M") << endl;
            cin >> M;
            OutputFile =in_text_fileIn_generate(filename, N, M);
            break;
        }
        default: {
            cout << "Выход\n";

            return 0;
        }

    }

    deq_numbers = load_from_file(filename);
    for (;;)
    {
        int n = menu();
        switch (n)
        {
            case 1:
            {
                cout << "Очередь  до: " << endl;
                output_screen(deq_numbers);
                deq_numbers = modify(deq_numbers);
                cout << "Очередь после: " << endl;
                output_screen(deq_numbers);
                break;
            }


            case 2:
            {
                cout << "Очередь  до: " << endl;
                output_screen(deq_numbers);
                deq_numbers = modify(deq_numbers.begin(), deq_numbers.end());
                cout << "Очередь после: " << endl;
                output_screen(deq_numbers);
                break;
            }

            case 3:
            {
                cout << "Очередь  до: " << endl;
                output_screen(deq_numbers);
                transform_deque(deq_numbers);
                cout << "Очередь после: " << endl;
                output_screen(deq_numbers);
                break;
            }

            case 4:
            {
                cout << "Очередь  до: " << endl;
                output_screen(deq_numbers);
                for_each_deque(deq_numbers);
                cout << "Очередь после: " << endl;
                output_screen(deq_numbers);
                break;
            }

            case 5:
            {
                cout << "Очередь: " << endl;
                output_screen(deq_numbers);
                cout << "Сумма: " << sum(deq_numbers) << endl;
                break;
            }

            case 6:
            {   cout << "Очередь: " << endl;
                output_screen(deq_numbers);
                cout << "Среднее арифметическое: " << average(deq_numbers) << endl;
                break;
            }

            case 7:
                cout << "Очередь: " << endl;
                output_screen(deq_numbers);
                break;

            case 8:
                PrintFile(filename,deq_numbers);
                break;

            default:
                cout << "Выход " << endl; exit(0);
                break;

        }
    }
}
