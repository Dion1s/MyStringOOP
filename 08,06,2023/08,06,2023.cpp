#include "String.h"

int main() {
    String defaultString;
    String customSizeString(50);
    String userString("Hello, world!");
    String copiedString(userString);
    String equalString;

    defaultString = userString + " " + copiedString;
    equalString = defaultString;
    equalString.displayString();

    defaultString.displayString();
    customSizeString.displayString();
    userString.displayString();
    copiedString.displayString();

    size_t position = userString.findSubstring("Hello, world!");
    if (position != std::string::npos) 
        std::cout << "Substring found at position" << std::endl;
    else 
        std::cout << "Substring not found." << std::endl;
    


    return 0;
}
