#include <iostream>
#include <fstream>

int main (int arc, char **arv){

    int pos = 0;
    int start = 0;
    std::string stash;
    std::string stash_finale = "";

    std::ifstream file(arv[1]);
    std::string buffer;
    while (getline(file, buffer)){
        stash.append(buffer + '\n');

    }
    while ((pos = stash.find("void", start)) != std::string::npos){
        //pos = buffer.find("HumanB");
        std::cout << "****POSITION : ";
        std::cout << pos << std::endl;
        stash_finale += stash.substr(start,pos - start);
        start = pos + 4 + 1;
    }
	stash_finale += stash.substr(start,pos - start);
    std::cout << stash << std::endl;
    std::cout << "******************************************************" << std::endl;

    std::cout << stash_finale << std::endl;

    


}