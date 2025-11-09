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

    // std::ifstream file(arv[1]);
    // std::string s1 = arv[2];
    // std::string s2 = arv[3];
    std::string::size_type pos = 0;
    std::string::size_type start = 0;
    std::string stash;
    std::string stash_finale = "";
    std::string buffer;
    std::string res;
    
    std::string const &filename = arv[1];
    std::string const &search = arv[2];
    std::string const &replacement = arv[3];
    std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
    std::cout << "filename: " << filename << std::endl;
    if (!file) {
        std::cerr << "Error opening file: " << arv[1] << std::endl;
        return 1;
    }


    std::string content;
    std::cout << "Reading file content..." << std::endl;
    content = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    if (!content.empty()) {
        std::cout << "Successfully read file content" << std::endl;
    } else {
        std::cerr << "Error reading file: " << arv[1] << std::endl;
        return 1;
    }
    std::cout << "File content: " << content << std::endl;


    std::cout << "Replacing all occurrences of '" << search << "' with '" << replacement << "'..." << std::endl;
    while ((pos = content.find(search, start)) != std::string::npos){
        stash_finale.append(content, start, pos - start);
        stash_finale.append(replacement);
        start = pos + search.length();
    }
    std::cout << "Final append from position " << start << " to end." << std::endl;
    stash_finale.append(content, start, content.length() - start);
    std::cout << "Replacement done." << std::endl;


    std::cout << "************************ORIGINAL**************************" << std::endl;
    std::cout << content << std::endl;
    std::cout << "***********************FIN ORIGINAL***********************" << std::endl;
    
    std::cout << "************************STASH FINALE****************************" << std::endl;
    std::cout << stash_finale << std::endl;
    std::cout << "************************FIN*************************************" << std::endl;

    std::cout << "Creating output file: " << (filename + ".replace") << std::endl;
    std::ofstream output_file((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
    if (!output_file) {
        std::cerr << "Error creating output file: " << (filename + ".replace") << std::endl;
        return 1;
    }


    std::cout << "Writing to file: " << (filename + ".replace") << std::endl;
    output_file.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);

    output_file << stash_finale;
    std::cout << "Writing completed." << std::endl;
    output_file.close();
    file.close();
    return 0;
}