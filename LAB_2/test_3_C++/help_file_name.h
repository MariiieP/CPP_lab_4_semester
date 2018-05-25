//
//  help_file_name.cpp
//  test_3_C++
//
//  Created by Мария Юрьевна on 25.05.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
////#include <algorithm>
//#include "bank_account.h"
//#include "help_file_name.h"
using namespace std;

class correct{

public:
    int input_number(int min, int max,string message);
    string input_information(string messge);
    bool correct_symbol(char c);
    bool correct_name(string name);
    string input_file_name();
};

