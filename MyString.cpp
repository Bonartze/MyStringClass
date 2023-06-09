//
// Created by ivan on 09.06.23.
//

#include "MyString.h"

void MyString::print() {
    std::cout << str << std::endl;
}

MyString::~MyString() {
    delete[] str;
}

MyString::MyString() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char *s) : str(nullptr) {
    if (!s) {
        MyString();
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::MyString(MyString &&st) {
    std::cout << "Move ctor\n";
    if (!st.str)
        MyString();
    else {
        str = st.str;
        st.str = nullptr;
    }
}

MyString::MyString(const MyString &st) {
    std::cout << "Copy ctor\n";
}

MyString &MyString::operator=(const MyString &rhs) {
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
    std::cout << "Move assignment\n";
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

bool MyString::operator==(const MyString &s) const {
    if (std::strcmp(s.str, str) == 0)
        return true;
    return false;
}

MyString MyString::operator+(const MyString &s) {
    char *buffer = new char[strlen(s.str) + strlen(str) + 1];
    strcpy(buffer, str);
    strcat(buffer, s.str);
    MyString temp{buffer};
    delete[] buffer;
    return temp;
}

MyString MyString::operator-() const {
    char *buffer = new char[strlen(str) + 1];
    strcpy(buffer, str);
    for (size_t i = 0; i < strlen(str); i++)
        buffer[i] = str[i];
    buffer[strlen(str)] = '\0';
    MyString temp{buffer};   //to avoid leak memory
    return temp;
}
