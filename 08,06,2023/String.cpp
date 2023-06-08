#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

String::String() {
    this->length = 80;
    str = new char[length + 1];
    std::memset(str, '\0', length + 1);
}

String::String(size_t size) {
    this->length = size;
    str = new char[length + 1];
    std::memset(str, '\0', length + 1);
}

String::String(const char* s) {
    this->length = std::strlen(s);
    str = new char[length + 1];
    std::strcpy(str, s);
}

String::String(const String& other) {
    this->length = other.length;
    str = new char[length + 1];
    std::strcpy(str, other.str);
}

String::String(const char* s, size_t size) {
    this->length = size;
    str = new char[length + 1];
    std::strncpy(str, s, length);
    str[length] = '\0';
}

String::~String() {
    delete[] str;
}

void String::inputString() {
    std::cout << "Enter a string: ";
    std::cin.getline(str, length + 1);
}

void String::displayString() {
    std::cout << "String: " << str << std::endl;
} 

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        this->length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
    return *this;
}

String String::operator+(const String& other) const {
    size_t newLength = this->length + other.length;
    char* newStr = new char[newLength + 1];
    std::strcpy(newStr, str);
    std::strcat(newStr, other.str);
    String result(newStr);
    delete[] newStr;
    return result;
}

bool String::operator==(const String& other) const {
    return (std::strcmp(str, other.str) == 0);
}

size_t String::findSubstring(const String& substring) const {
    size_t subLength = substring.length;
    size_t strLength = this->length;

    for (size_t i = 0; i <= strLength - subLength; i++) {
        String temp(&str[i],subLength);
        if (temp == substring) {
            return i;
        }
    }

    return std::string::npos;
}
