#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "bank_account.h"
#include "help_file_name.h"


template <class Type>
class Task {
public:
    Task() {}
    ~Task() {}

    void remove( int numb);
    void add(Type &elem);
    int size();
    bool is_empty();
    bool read_from_file(Type(*f)(ifstream&));
    void read_from_screen(Type (*f)());
    void output_file( vector<Type> items,string (*f)(Type,int) );
    void output_screen(vector<Type> items, void (*f) (Type));
    vector<Type> vect;
    vector<Type> lineary_search(Type search_elem,bool(*Equal)(Type,Type));
    vector<Type> binary_search( Type find_element, bool(*compare)(Type, Type), bool(*Equal)(Type, Type));

};

