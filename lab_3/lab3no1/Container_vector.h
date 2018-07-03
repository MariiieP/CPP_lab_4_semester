#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "HelpUtils.h"

using namespace std;

//класс контейнер 
template <typename T>
class Container_vector
{
private:
	vector<T> _vect_t; //контейнер
	string _source_name;
	void(*_save)(T, ofstream*); // сохранение
	bool (*_load)(T&, ifstream*); //загрузка

public:

	//сохранение в файл
	void save() {
		if (_source_name == "") 
		{
			return;
		}
		ofstream file;
		file.open(_source_name, ios::binary | ios::out);
		for (T el : _vect_t)
		{
			_save(el, &file);
		}
		file.close();
	}

	Container_vector()
	{
		_source_name = "";
	}

	//конструктор
	Container_vector(string fileName, bool (*ld)(T&, ifstream*),
		void (*sv)(T, ofstream*))
	{
		_load = ld;
		_save = sv;
		if (fileName == "") 
		{
			_source_name = "Default.bin";
		}
		else
		{
			_source_name = fileName;
		}
		ifstream file;
		file.open(_source_name, ios::binary | ios::in);
		if (file.is_open()) {
			T el;
			while (_load(el, &file)) 
			{
				add(el);
			}
		}
		else 
		{
			file.open(_source_name, ios::binary | ios::out);
		}
		file.close();
	}

	//деструктор
	~Container_vector()
	{
		save();
		_vect_t.clear();
	}

		//вывод в консоль
	void to_console(void(*output)(T))
	{
		for (T write_concole : _vect_t)
		{
			output(write_concole);
		}
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl <<"Всего записей: " << _vect_t.size() << endl;
	}
	
	//кол-во элементов в контейнере
	int size() 
	{
		return _vect_t.size();
	}
	
	//получить элемент по индексу
	T get_elem_by_index(int ind) {
		if (ind < 0 || ind >= _vect_t.size()) 
		{
			throw "Неверный индекс";
		}
		return _vect_t[ind];
	}

	//сортировка
	void surt_vct(bool(*compare)(T, T)) 
	{
		sort(_vect_t.begin(), _vect_t.end(), compare);
	}

	//возвращает индекс элемента с заданным критерием
	int linear_search(bool(*func)(T, T), T crit) 
	{
		int i = 0;
		for (T rec : _vect_t) 
		{
			if (func(rec, crit)) 
			{
				return i;
			}
			++i;
		}
		return -1;
	}

	//выборка подмножества по заданному критерию
	Container_vector<T> linear_search_sub_set(bool(*func)(T, T), T crit)
	{
		Container_vector<T> sub_set;
		for (T rec : _vect_t)
		{
			if (func(rec, crit)) 
			{
				sub_set.add(rec);
			}
		}
		return sub_set;
	}


	//очистка
	void clear() 
	{
		_vect_t.clear();
		save();
	}

	//добавить 
	void add(T client) 
	{
		_vect_t.push_back(client);
		save();
	}

	//удаление по индексу
	void remove_ind(int ind)
	{
		if (ind < 0 || ind >= _vect_t.size())
		{
			throw "Неверный индекс";
		}
		_vect_t.erase(_vect_t.begin() + ind);
		save();
	}


	//изменение записи в консоли
	bool change(bool(*func)(T&), int ind) 
	{
		if (ind < 0 || ind >= _vect_t.size()) 
		{
			return false;
		}
		func(_vect_t[ind]);
		save();
		return true;
	}


	//ввод с консоли
	void input_from_console(bool(*input)(T&))
	{
		T t;
		do {
			cout << endl;
			if (input(t)) 
			{
				add(t);
				cout << "Запись успешно довавлена, еще? ";
			}
			else 
			{
				cout << "Введено некорректное значение, повторить? ";
			}
		} while (input_query());
		save();
	}



	bool input_from_file(bool(*f)(fstream&), string newfname)
	{
		std::fstream input;

		input.open(newfname, ios::binary);

		if (!input)
		{
			cout << "Ошибка" << endl;
			return false;
		}
		else
		{
			int size;
			Type elem;
			input.read((char*)&size, sizeof(int));
			for (int i = 0; i < size; i++)
			{
				vect.push_back(f(input));
			}

			input.close();
			return true;
		}
	}
	//запись в поток
	void to_file(void(*output)(T, fstream*), fstream *f)
	{
		if (!f->is_open())
		{
			throw "Файл не открыт";
		}
		for (T write_concole : _vect_t)
		{
			output(write_concole, f);
		}
	}

};
