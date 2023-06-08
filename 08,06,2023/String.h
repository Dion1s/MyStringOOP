#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    size_t length;

public:
    String();
    String(size_t size);
    String(const char* s);
    String(const String& other);
    String(const char* s, size_t size);
    ~String();

    void inputString();
    void displayString();

    String& operator=(const String& other);
    String operator+(const String& other) const;
    bool operator==(const String& other) const;

    size_t findSubstring(const String& substring) const;

};

#endif
