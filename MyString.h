//
// Created by ivan on 09.06.23.
//

#ifndef UNTITLED57_MYSTRING_H
#define UNTITLED57_MYSTRING_H

#include <cstring>
#include <iostream>

class MyString {
private:
    char *str;
public:
    MyString();
    MyString(const char *str);

    MyString(const MyString &st);

    MyString(MyString &&st);

    ~MyString();

    MyString &operator=(const MyString &rhs);

    MyString &operator=(MyString &&rhs);

    MyString operator-() const;

    bool operator==(const MyString &str) const;

    MyString operator+(const MyString &str);

    void print();
};


#endif //UNTITLED57_MYSTRING_H
