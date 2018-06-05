//
//  help_template.hpp
//  test_3_C++
//
//  Created by Мария Юрьевна on 02.06.2018.
//  Copyright © 2018 Мария Юрьевна. All rights reserved.
//
#pragma once
#ifndef help_template_h
#define help_template_h

#include <stdio.h>
#include <string>
using namespace std;



template <typename Type>
class Corrects
{
public:
    Corrects();
    ~Corrects();
    Type input_number(Type min, Type max,string message);
};
#endif  //help_template_h
