#include <iostream>
#include <fstream>

int main (int arc, char **arv){
    if (arc != 4) {
        std::cerr << "Invalid arguments. Usage: " << arv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (arv[2][0] == '\0'){
        std::cerr << "s1 cannot be an empty string." << std::endl;
        return 1;
    }

    std::ifstream file(arv[1]);
    std::string s1 = arv[2];
    std::string s2 = arv[3];
    std::string::size_type pos = 0;
    std::string::size_type start = 0;
    std::string stash;
    std::string stash_finale = "";
    std::string buffer;
    
    if (!file.is_open()){
        std::cerr << "Error opening file: " << arv[1] << std::endl;
        return 1;
    }
    while (getline(file, buffer)){
        stash.append(buffer + '\n');
    }
    while ((pos = stash.find(s1, start)) != std::string::npos){
        /*
        // copie la portion entre 'start' et le début de l'occurrence
            stash_finale.append(stash, start, pos - start);
        */
        stash_finale += stash.substr(start, pos - start);
        if (s2 != "")
            stash_finale += s2;
        else
            stash_finale += s1;
        
        start = pos + s1.length();
    }
	stash_finale += stash.substr(start,pos - start);

    std::cout << "************************ORIGINAL**************************" << std::endl;
    std::cout << stash << std::endl;
    std::cout << "******************************************************" << std::endl;

    std::cout << stash_finale << std::endl;

    // record the new file
    std::ofstream newfile;
    std::string outname = std::string(arv[1]) + ".replace";
    newfile.open(outname.c_str());
    newfile << stash_finale;
    newfile.close();
    file.close();
    return 0;
}