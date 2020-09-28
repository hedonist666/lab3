#pragma once 
#include <map>
#include <string>
#include <iostream>


enum class Sex {
    MALE,
    FEMALE
};

struct Data {
    int age;
    Sex sex;
    std::string post;     
    int income;
    Data();
    Data(int, Sex, std::string, int);
};

class BD {
    std::map<std::string, Data> data;
public:
    BD();
    BD(BD&);
    BD operator=(BD&);
    BD(BD&&);
    BD operator=(BD&&);
    Data& operator[](std::string);
    friend std::ostream& operator<<(std::ostream&, BD&);
};

