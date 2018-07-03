#pragma once
#include "DateUtils.h"
#include <string>
#include <fstream>


using namespace std;

//тип счета
struct TypeDeposit {
	//Название типа вклада
	string type_name;
	//Возможность пополнения
	bool inc_money;
	//Возможность снятия
	bool dec_money;
	//Процент
	double percent;
};

//счет
struct Deposit {
	//Номер счета
	int32_t number;
	//Код счета
	int32_t code;
	//ФИО
	string fio;
	//Сумма
	double sum;
	//id типа вклада
	int32_t id_type_dep;
	//Дата вклада
	Date date;
	//Период
	int32_t period;
};

//Вывод заголовка типов
void type_dep_header();

extern int32_t const count_types;
//типы счетов
extern TypeDeposit type_dep[3];

//изменить тип счета
int change_type_dep(TypeDeposit &tp);

//вывод счета в консоль
void type_dep_to_console(TypeDeposit tp);

//Открытие счета для клиента
bool open_deposit(Deposit &dep);

//Показ информации о счете
void show_deposit(Deposit dep);

//изменение в консоли
bool change_deposit_for_user(Deposit &dep);

//ввод из файла
bool deposit_from_file(Deposit &dep, std::ifstream *f);

//вывод в файл
void deposit_to_file(Deposit dep, std::ofstream *f);

//сохранение типов счетов в файл
void save_types_to_file(std::string fileName);

//загрузка типов счетов из файла
void load_types_to_file(std::string fileName);


