#include <iostream>
#include <iomanip>
#include <ctime>
#include "HelpUtils.h"
#include "Deposit.h"
#include "stdafx.h"

int32_t const count_types = 3;
TypeDeposit type_dep[count_types];
//Изменение типа счета
int change_type_dep(TypeDeposit & tp) 
{
	int ans;
	do {
		cout << "1 - Название вклада" << endl;
		cout << "2 - Возможность пополнять средства" << endl;
		cout << "3 - Возможность снимать средства" << endl;
		cout << "4 - Процентная ставка" << endl;
		cout << "0 - Отмена" << endl;
	} while (!input_number(ans, "Ваш выбор: ") || ans < 0 || ans > 4);

	if (ans == 0) {
		//пользователь ввел отмену
		return 2;
	}
	string str;
	double per;
	switch (ans) 
	{
	case 1:
		cout << "Введите название вклада" << endl;
		cin >> str;
		if (str == "") 
		{
			//не удалось изменить счет
			return 1;
		}
		tp.type_name = str;
		//счет успешно изменен
		return 0;

	case 2:
		cout << "Разрешить пополнение средств? " << endl;
		tp.inc_money = input_query();
		//успешно
		return 0;

	case 3:
		cout << "Разрешить снятие средств? " << endl;
		tp.dec_money = input_query();
		//успешно
		return 0;

	case 4:
		//cout << "Введите процентную ставку:" << endl;
		if (!input_number(per, "Введите процентную ставку:")) 
		{
			//ошибка
			return 1;
		}
		tp.percent = per;
		//успешно
		return 0;
	}
}

//Вывод заголовка типов
void type_dep_header()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << setw(1) << left << "|№" << "|"
		<< setw(19) << left << "Название"<<"|"
		<< setw(14) << left << "В-сть пополн."<<"|"
		<< setw(14) << left << "В-сть сним"<<"|"
		<< setw(8) << left << "Процент" <<"|"<< endl;
	cout << "--------------------------------------------------------------" << endl;
}

//вывод типов в консоль
void type_dep_to_console(TypeDeposit tp)
{
	cout << setw(1) << left << "|" << setw(19) << left << tp.type_name << "|"
		<< setw(14) << left << (tp.inc_money ? "да" : "нет") << "|"
		<< setw(14) << left << (tp.dec_money ? "да" : "нет") << "|"
		<< setw(8) << left << tp.percent * 100 << "|" << endl;
}

//ввод с консоли
bool open_deposit(Deposit &dep) 
{
	string str = input_information("Введите ФИО: ");
	dep.fio = str;
	int len = sizeof(type_dep) / sizeof(type_dep[0]);
	cout << "Выберите номер типа" << endl;
	type_dep_header();

	for (int i = 0; i < len; ++i) 
	{
		cout <<setw(1)<<left<<"|"<<setw(1)<<left<< i + 1;
		type_dep_to_console(type_dep[i]);
	}

	while (!input_number(dep.id_type_dep, "--------------------------------------------------------------") || dep.id_type_dep < 1 || dep.id_type_dep > len)
	{
		cout << "Введено неверное значение, повторите попытку" << endl;
	}
	--dep.id_type_dep;
	while (!input_number(dep.sum, "Введите сумму: ") || dep.sum < 0)
	{
		cout<<"Введена некорректная сумма, повторите ввод:"<<endl;
	}
	cout << "Введите дату открытия счета (дд.мм.гггг): ";
	cin >> str;
	while (!date_from_str(str, dep.date)) 
	{
		cout << "Введена некорректная дата, повторите ввод" << endl;
		cout << "Введите дату открытия счета (дд.мм.гггг): ";
		cin >> str;
	}
	while (!input_number(dep.period, "Введите срок вклада в месяцах: ") || dep.period < 1) 
	{
		cout << "Введен некорректный срок, повторите ввод:" << endl;
	}
	while (!input_number(dep.code, "Введите код счета (100-999): ") || dep.code > 999 || dep.code <100) 
	{

		cout << "Введена код счета, повторите ввод:" << endl;
	}
	srand(time(NULL));
	dep.number = rand() % 100000;
	show_header();
	show_deposit(dep);
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Вы уверены, что хотите открыть вклад? ";
	if (!input_query()) {
		return false;
	}

	return true;
}

//вывод на консоль
void show_deposit(Deposit dep) 
{
	cout << setw(1) << "|" << setw(7) << left << dep.number << "|"
		<< setw(4) << left << dep.code<<"|"
		<< setw(15) << left << dep.fio << "|"
		<< setw(10) << left << dep.sum << "|"
		<< setw(15) << left << date_to_str(dep.date) << "|"
		<< setw(5) << left << dep.period ;
	type_dep_to_console(type_dep[dep.id_type_dep]);
}

//снятие и зачисление средств для клиента
bool change_deposit_for_user(Deposit &dep) {
	int ans;
	do {
		cout << "1 - Снять средства" << endl;
		cout << "2 - Пополнить счет" << endl;
		cout << "0 - Отмена" << endl;
	} while (!input_number(ans, "Ваш выбор: ") || ans < 0 || ans > 2);
	if (ans == 0) {
		return false;
	}
	int quant;
	//снятие средств
	if (ans == 1) {
		if (!type_dep[dep.id_type_dep].dec_money) 
		{
			cout
				<< "Вы не можете снимать средства при данном типе вклада" <<
				endl;
			return false;
		}
		if (!input_number(quant, "Введите сумму: ") || quant >= dep.sum)
		{
			cout << "Введена неверная сумма" << endl;
			return false;
		}
		dep.sum -= quant;
		return true;
	}
	//пополнение средств
	if (!type_dep[dep.id_type_dep].inc_money) 
	{
		cout
			<< "Вы не можете пополнять средства при данном типе вклада" <<
			endl;
		return false;
	}
	if (!input_number(quant, "Введите сумму: ")) 
	{
		cout << "Введена неверная сумма" << endl;
		return false;
	}
	dep.sum += quant;
	return true;
}

//считывание счета из файла
bool deposit_from_file(Deposit &dep, ifstream *f)
{
	Deposit d;
	if (!f->is_open()) 
	{
		return false;
	}
	string str;
	try 
	{
		f->read(reinterpret_cast<char*>(&(d.number)), sizeof(d.number));
		f->read(reinterpret_cast<char*>(&(d.code)), sizeof(d.code));
		str = str_from_bin(f);
		d.fio = str;
		f->read(reinterpret_cast<char*>(&(d.sum)), sizeof(d.sum));
		f->read(reinterpret_cast<char*>(&(d.id_type_dep)), sizeof(d.id_type_dep));
		if (!date_from_bin(d.date, f))
		{
			return false;
		}
		f->read(reinterpret_cast<char*>(&(d.period)), sizeof(d.period));
		dep = d;
		return true;
	}
	catch (...) {
		throw "Не удалось считать из файла";
	}
}

//вывод в файл
void deposit_to_file(Deposit dep, ofstream *f) 
{
	f->write(reinterpret_cast<char*>(&(dep.number)), sizeof(dep.number));
	f->write(reinterpret_cast<char*>(&(dep.code)), sizeof(dep.code));
	StrToBin(f, dep.fio);
	f->write(reinterpret_cast<char*>(&(dep.sum)), sizeof(dep.sum));
	f->write(reinterpret_cast<char*>(&(dep.id_type_dep)), sizeof(dep.id_type_dep));
	date_to_bin(dep.date, f);
	f->write(reinterpret_cast<char*>(&(dep.period)), sizeof(dep.period));
}

//загрузка типов счетов из файла
void load_types_to_file(string fileName)
{
	ifstream file;
	file.open(fileName, ios::binary | ios::in);
	if (file.is_open()) 
	{
		int i = 0;
		bool OK = true;
		string str;
		while (OK) {
			str = str_from_bin(&file);
			if (str == "")
			{
				break;
			}
			type_dep[i].type_name = str;
			OK = 
				file.read(reinterpret_cast<char*>(&(type_dep[i].inc_money)), sizeof(type_dep[i].inc_money)) &&
				file.read(reinterpret_cast<char*>(&(type_dep[i].dec_money)), sizeof(type_dep[i].dec_money)) &&
				file.read(reinterpret_cast<char*>(&(type_dep[i].percent)), sizeof(type_dep[i].percent));
			++i;
		}
		file.close();
	}
	else 
	{
		type_dep[0].type_name = "Вклад_№1";
		type_dep[0].dec_money = type_dep[0].inc_money = false;
		type_dep[0].percent = 0.03;

		type_dep[1].type_name = "Вклад_№2";
		type_dep[1].dec_money = false;
		type_dep[1].inc_money = true;
		type_dep[1].percent = 0.01;

		type_dep[2].type_name = "Вклад_№3";
		type_dep[2].dec_money = type_dep[2].inc_money = true;
		type_dep[2].percent = 0.08;
	}
}

//сохранение типов счетов в файл
void save_types_to_file(string fileName) 
{
	ofstream file;
	file.open(fileName, ios::out | ios::binary);
	if (!file.is_open())
		throw "Файл не открыт";
	int i;
	for (i = 0; i < count_types; ++i) 
	{
		StrToBin(&file, type_dep[i].type_name);
		file.write(reinterpret_cast<char*>( &(type_dep[i].inc_money) ), sizeof(type_dep[i].inc_money) );
		file.write(reinterpret_cast<char*>( &(type_dep[i].dec_money) ), sizeof(type_dep[i].dec_money));
		file.write(reinterpret_cast<char*>( &(type_dep[i].percent) ), sizeof(type_dep[i].percent));
	}
	file.close();
}





