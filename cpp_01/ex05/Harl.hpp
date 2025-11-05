#include <iostream>
#include <string>
#include <algorithm>

class Harl {
    private:
        void debug(void) {
            std::cout << "DEBUG message\n";
        }
        void info(void) {
            std::cout << "INFO message\n";
        }
        void warning(void) {
            std::cout << "WARNING message\n";
        }
        void error(void) {
            std::cout << "ERROR message\n";
        }

    public:
        void complain(const std::string &level) {};
};