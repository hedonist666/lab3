#include "MyString.h"

MyString::MyString() : ptr(0) {}

MyString::MyString(const char* s) {
    int n = 0;
    for (; s[n] != '\0'; ++n) {}
    ptr = new char[n + 1];
    for (int i = 0; i < n; ++i) {
        ptr[i] = s[i];
    }
    ptr[n + 1] = '\0';
}


MyString::MyString(const MyString& other) {
    if (other.ptr == 0) {
        ptr = 0;
        return;
    }
    int n = 0;
    for (; other.ptr[n] != '\0'; ++n) {}
    ptr = new char[n + 1];
    for (int i = 0; i < n; ++i) {
        ptr[i] = other.ptr[i];
    }
    ptr[n + 1] = '\0';
}

MyString MyString::operator=(const char* s) {
    if (ptr != 0) delete[] ptr;
    int n = 0;
    for (; s[n] != '\0'; ++n) {}
    ptr = new char[n + 1];
    for (int i = 0; i < n; ++i) {
        ptr[i] = s[i];
    }
    ptr[n + 1] = '\0';
    return *this;
}

MyString MyString::operator=(const MyString& other) {
    if (&other == this) return *this; // MyString a; a = a;
    if (other.ptr == 0) {
        ptr = 0;
        return *this;
    }
    int n = 0;
    for (; other.ptr[n] != '\0'; ++n) {}
    ptr = new char[n + 1];
    for (int i = 0; i < n; ++i) {
        ptr[i] = other.ptr[i];
    }
    ptr[n + 1] = '\0';
    return *this;
}


std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << "contents: ";
    if (str.ptr != 0) os << '"' << str.ptr << '"';
    return os;
}

MyString MyString::operator+=(const MyString& other) {
    if (other.ptr == 0) return *this;
    int n = 0;
    int k = 0;
    for (; other.ptr[n] != '\0'; ++n) {}
    if (ptr != 0) {
        for (; ptr[k] != '\0'; ++k) {}
        n += k;
    }
    char* s = new char[n + 1];
    if (ptr != 0) {
        for (int i = 0; ptr[i] != '\0'; ++i) {
            s[i] = ptr[i];
        }
        delete[] ptr;
    }
    for (int i = 0; other.ptr[i] != '\0'; ++i) {
        s[k + i] = other.ptr[i];
    } 
    ptr = s;
    ptr[n + 1] = '\0';
    return *this;
}

MyString MyString::operator+(const MyString& other) {
    if (other.ptr == 0) return *this;
    int n = 0;
    int k = 0;
    for (; other.ptr[n] != '\0'; ++n) {}
    if (ptr != 0) {
        for (; ptr[k] != '\0'; ++k) {}
        n += k;
    }
    char* s = new char[n + 1];
    if (ptr != 0) {
        for (int i = 0; ptr[i] != '\0'; ++i) {
            s[i] = ptr[i];
        }
    }
    for (int i = 0; other.ptr[i] != '\0'; ++i) {
        s[k + i] = other.ptr[i];
    } 
    s[n + 1] = '\0';
    MyString res(s);
    return res;
}
