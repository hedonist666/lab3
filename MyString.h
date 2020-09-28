#pragma once
#include <iostream> 

class MyString {
    public:
        char* ptr;
        MyString();
        MyString(const char*);
        MyString(const MyString&);
        MyString operator=(const char*);
        MyString operator=(const MyString&);
        friend std::ostream& operator<<(std::ostream&, const MyString&);
        MyString operator+=(const MyString&);
        MyString operator+(const MyString&);
};
