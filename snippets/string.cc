#include <stdio.h>
#include <iostream>

int main() {
    std::string str = "Hello!";
    std::cout << str << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << str[0] << std::endl;
    std::cout << str.back() << std::endl;
    str[str.length()-1] = ' ';
    std::cout << str << std::endl;
    str += "Cory";
    std::cout << str << std::endl;
    std::cout << str.find('C') << std::endl;
    std::string newstr = "Hello Cory";
    std::cout << str.compare(newstr) << std::endl;
}
