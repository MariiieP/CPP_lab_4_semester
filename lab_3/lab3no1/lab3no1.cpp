/*
Реализовать виртуальный банк. Предусмотрено два режима работы
с банком — режим пользователя и режим сотрудника. Пользователь имеет
возможность открыть счет под заданный процент (выбирается из доступных видов вкладов),
закрыть счет, снять часть средств со счета (если допускается видом вклада), посмотреть остаток
средств на счете. Сотрудник банка может редактировать список видов вкладов (название вида,
процентная ставка, возможность частичного снятия суммы), просматривать список вкладчиков (вкладчик,
вид вклада, срок вклада, дата открытия вклада, сумма на счету), список вкладчиков должен иметь
возможность фильтрации по любому полю.
*/
#include "stdafx.h"
#include <iostream>
#include <string>

#include <iomanip>
#include "Deposit.h"
#include "DateUtils.h"
#include "Container_vector.h"
#include <Windows.h>

using namespace std;

//Меню для клиента
void menu_client(Container_vector<Deposit> &bank)
{
	int answer, num;
	while (true)
	{
		do 
		{
			cout << "********************************" << endl;
			cout << "1 - Открыть счет" << endl;
			cout << "2 - Просмотреть счета" << endl;
			cout << "0 - Отмена" << endl;
			cout << "********************************" << endl;
		} while (!input_number(answer, "Ваш выбор: ") || answer < 0 || answer > 3);

		if (answer == 0) 
		{
			break;
		}
		cout << endl;
		int ind;
		Deposit dep;
		Container_vector<Deposit> cnt;
		if (answer == 1) 
		{
			//открыть счет
			if (open_deposit(dep)) 
			{
				bank.add(dep);
				cout << "Счет открыт." << endl;
			}
			else 
			{
				cout << "Введены неверные данные." << endl;
			}
		}
		else 
		{
			//ввод номера
			string str;
			str = input_information("Введите ФИО: ");
			if (trim(str) == "") 
			{
				cout << "Введено пустое поле" << endl;
				break;
			}
			dep.fio = str;
			for (;;) 
			{
				cnt = bank.linear_search_sub_set(
					[](Deposit d, Deposit crit) 
				{
					return d.fio == crit.fio;
				},
					dep);
				if (cnt.size() == 0) 
				{
					cout << "На данные ФИО счетов не зарегестрировано" << endl;
					break;
				}
				show_header();
				cnt.to_console(show_deposit);

				do 
				{
					cout << "********************************" << endl;
					cout << "1 - Изменить средства" << endl;
					cout << "2 - Закрыть счет" << endl;
					cout << "0 - Назад" << endl;
					cout << "********************************" << endl;
				} while (!input_number(answer, "Ваш выбор: ") || answer < 0 || answer > 3);

				if (answer == 0) 
				{
					break;
				}

				//ввод номера
				if (!input_number(num, "Введите номер счета: ") || num < 0) 
				{
					break;
				}
				dep.number = num;
				ind = cnt.linear_search(
					[](Deposit d, Deposit crit) 
				{
					return d.number == crit.number;
				},
					dep);
				if (ind == -1) 
				{
					cout << "У вас нет такого счета." << endl;
					break;
				}

				//изменение средств
				if (answer == 1) 
				{
					if (bank.change(change_deposit_for_user, ind)) 
					{
						cout << "Счет изменен." << endl;
					}
					else 
					{
						cout << "Не удалось изменить счет." << endl;
					}
				}

				//закрытие счета
				else 
				{
					bank.remove_ind(ind);
					cout << "Счет закрыт." << endl;
				}
			}
		}
		system("pause");
	}
}





//Меню для сотрудника
void menu_employee(Container_vector<Deposit> &bank)
{
	int ans, num;
	Deposit dep;
	int len;
	for (;;) 
	{
		do 
		{
			cout << "********************************" << endl;
			cout << "1 - Отфильтровать список вкладчиков" << endl;
			cout << "2 - Изменить тип вклада" << endl;
			cout << "3 - Просмотреть всех вкладчиков" << endl;
			cout << "0 - Отмена" << endl;
			cout << "********************************" << endl;
		} while (!input_number(ans, "Ваш выбор: ") || ans < 0 || ans > 3);

		if (ans == 0) {
			break;
		}
		cout << endl;
		Deposit crit;
		Container_vector<Deposit> subs;
		int num;
		string str;
		Date date;
		int res;
		switch (ans)
		{
		case 1:
			cout << "Отфильтровать по:" << endl;
			do {
				cout << "1 - Номеру счета" << endl;
				cout << "2 - ФИО" << endl;
				cout << "3 - Сумме" << endl;
				cout << "4 - Названию вклада" << endl;
				cout << "5 - Возможности пополнять счет" << endl;
				cout << "6 - Возможности снимать средства" << endl;
				cout << "7 - Дате открытия" << endl;
				cout << "8 - Сроку договора" << endl;
				cout << "9 - Процентной ставке" << endl;
				cout << "0 - Отмена" << endl;
			} while (!input_number(ans, "Ваш выбор: ") || ans < 0 || ans > 9);
			if (ans == 0) {
				break;
			}

			switch (ans)
			{
			case 1:
				if (!input_number(num, "Введите номер счета: ") || num < 0)
				{
					cout << "Введены неверные данные" << endl;
					break;
				}
				crit.number = num;
				subs = bank.linear_search_sub_set(
					[](Deposit dep, Deposit crit)
				{
					return dep.number == crit.number;
				}, crit);
				break;
			case 2:

				str = input_information("Введите ФИО: ");
				if (trim(str) == "") 
				{
					cout << "Введены неверные данные" << endl;
					break;
				}
				crit.fio = str;
				subs = bank.linear_search_sub_set(
					[](Deposit dep, Deposit crit) 
				{
					return dep.fio == crit.fio;
				}, crit);
				break;
			case 3:

				if (!input_number(num, "Введите сумму: ") || num < 0) 
				{
					cout << "Введены неверные данные" << endl;
					break;
				}
				crit.sum = num;
				subs = bank.linear_search_sub_set(
					[](Deposit dep, Deposit crit) {
					return dep.sum == crit.sum;
				}, crit);
				break;

			case 4:
				cout << "Выберите вклад " << endl;
				do {
					cout << "1 - " << type_dep[0].type_name << endl;
					cout << "2 - " << type_dep[1].type_name << endl;
					cout << "3 - " << type_dep[2].type_name << endl;
				} while (!input_number(ans, "Ваш выбор: ") || ans < 1 || ans > 3);

				crit.id_type_dep = ans;
				subs = bank.linear_search_sub_set(
					[](Deposit dep, Deposit crit) 
				{
					return dep.id_type_dep == crit.id_type_dep;
				}, crit);
				break;
			case 5:

				cout << "По способности пополнять средства: ";
				subs = bank.linear_search_sub_set(
					[](Deposit d, Deposit crit)
				{
					return type_dep[d.id_type_dep].inc_money;
				},
					crit);
				break;
			case 6:

				cout << "По способности снимать средства: ";
				subs = bank.linear_search_sub_set(
					[](Deposit d, Deposit crit)
				{
					return type_dep[d.id_type_dep].dec_money;
				},
					crit);
				break;

			case 7:
				cout << "Введите дату: ";
				cin >> str;
				if (!date_from_str(str, date)) 
				{
					cout << "Введены неверные данные" << endl;
					break;
				}
				crit.date = date;
				subs = bank.linear_search_sub_set(
					[](Deposit d, Deposit crit) 
				{
					return compare_dates(d.date, crit.date) == 0;
				},
					crit);
				break;

			case 8:
				if (!input_number(num, "Введите срок вклада: "))
				{
					cout << "Введены неверные данные" << endl;
					break;
				}
				crit.period = num;
				subs = bank.linear_search_sub_set(
					[](Deposit d, Deposit crit)
				{
					return d.period == crit.period;
				},
					crit);
				break;

			case 9:
				cout << "Введите процент: ";
				do {
					cout << "1 - " << type_dep[0].percent << endl;
					cout << "2 - " << type_dep[1].percent << endl;
					cout << "3 - " << type_dep[2].percent << endl;
				} while (!input_number(ans, "Ваш выбор: ") || ans < 1 || ans > 3);

				crit.id_type_dep = ans;
				subs = bank.linear_search_sub_set(
					[](Deposit dep, Deposit crit) 
				{
					return dep.id_type_dep == crit.id_type_dep;
				}, crit);
				break;
			}
			show_header();
			subs.to_console(show_deposit);
			break;

			//изменить тип вклада
		case 2:
			len = sizeof(type_dep) / sizeof(type_dep[0]);

			do {
				cout << "Выберите номер типа" << endl;
				type_dep_header();

				for (int i = 0; i < len; ++i) {
					cout << setw(1) << left << "|" << setw(1) << left << i + 1;
					type_dep_to_console(type_dep[i]);
				}
			} while (!input_number(ans, "--------------------------------------------------------------") || ans < 1 || ans > 3);

			res = change_type_dep(type_dep[--ans]);
			if (res == 0) 
			{
				cout << "Вклад успешно изменен" << endl;
				save_types_to_file("types.bin");
			}
			else if (res == 1) 
			{
				cout << "Не удалось изменить вклад" << endl;
			}
			break;

			//показ всех вкладчиков
		case 3:
			cout << endl;
			show_header();
			bank.to_console(show_deposit);
			break;
		}
		cout << endl;
		system("pause");
		cout << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	setlocale(LC_ALL, "Rus"); 
	Container_vector<Deposit> bank("bank.bin", deposit_from_file, deposit_to_file);
	int ans;
	load_types_to_file("types.bin");
	do
	{
		do 
		{
			cout << "********************************" << endl;
			cout << "Выберите тип учетной записи:" << endl;
			cout << "1 - Клиент" << endl;
			cout << "2 - Сотрудник банка" << endl;
			cout << "0 - Выход" << endl;
			cout << "********************************" << endl;
		} while (!input_number(ans, "Ваш выбор: ") || ans < 0 || ans > 2);

		switch (ans)
		{
		case 0:
			break;
		case 1:
			menu_client(bank);
			break;
		case 2:
			menu_employee(bank);
			break;
		}
	} while (ans != 0);

	save_types_to_file("types.bin");
	return 0;
}

