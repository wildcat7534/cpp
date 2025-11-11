#include "Replace.h"

int main (int arc, char **arv){
    if (arc != 4) {
        std::cerr << "Invalid arguments. Usage: " << arv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (arv[2][0] == '\0'){
        std::cerr << "s1 cannot be an empty string." << std::endl;
        return 1;
    }
    Replace replacer(arv[1], arv[2], arv[3]);

    if (!replacer.readFileContent(replacer))
        return 1;
    replacer.replaceInFile(replacer);
    replacer.setNewFileName(replacer);
    if (!replacer.createNewFile(replacer))
        return 1;
    
    std::cout << "************************FINAL CONTENT***************************" << std::endl;
    std::cout << replacer.getContent() << std::endl;
    std::cout << "************************FIN*************************************" << std::endl;

    return 0;
}