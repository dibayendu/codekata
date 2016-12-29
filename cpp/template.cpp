// To run the program, try the command below:
// g++ tempate.cpp

// This is just a template to be used.

#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "What is your name? ";
    getline (std::cin, name);
    std::cout << "Hello, " << name << "!\n";
}
