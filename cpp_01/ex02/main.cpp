#include <iostream>

int main(){

    std::cout << std::endl << "----- Testing pointers and references -----" << std::endl << std::endl;

    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << std::endl << "----- Addresses -----" << std::endl << std::endl;
    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << std::endl << "----- Values -----" << std::endl << std::endl;
    
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    std::cout << std::endl << "----- End of tests (garbage collection) -----" << std::endl << std::endl;
    return 0;
}