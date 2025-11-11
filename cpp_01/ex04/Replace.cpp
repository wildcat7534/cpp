#include "Replace.h"

Replace::Replace(std::string const &filename, std::string const &search, std::string const &replacement)
: filename(filename), search(search), replacement(replacement), content("") {}

std::string Replace::getFilename() const {
	return filename;
}

std::string Replace::getSearch() const {
	return search;
}

std::string Replace::getReplacement() const {
	return replacement;
}

std::string Replace::getContent() const {
	return content;
}


bool Replace::readFileContent(Replace &replacer) {

	std::ifstream file(replacer.getFilename().c_str(), std::ios::in |  std::ios::binary);
	if (!file) {
		std::cerr << "Error opening file: " << replacer.getFilename() << std::endl;
		return false;
	}
	replacer.content = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	if (replacer.content.empty()) {
		std::cerr << "Error reading file: " << replacer.getFilename() << std::endl;
		return false;
	}
	    std::cout << "************************ORIGINAL********************************" << std::endl;
    std::cout << replacer.getContent() << std::endl;
    std::cout << "***********************FIN ORIGINAL*****************************" << std::endl;
	file.close();
	return true;
}

void Replace::replaceInFile(Replace &replacer) {
	std::string::size_type pos = 0;
	std::string::size_type start = 0;
	std::string stash_finale = "";

	while ((pos = replacer.content.find(replacer.search, start)) != std::string::npos) {
		stash_finale.append(replacer.content, start, pos - start);
		stash_finale.append(replacer.replacement);
		start = pos + replacer.search.length();
	}
	stash_finale.append(replacer.content, start, replacer.content.length() - start);
	replacer.content = stash_finale;
}

void Replace::setNewFileName(Replace &replacer) {
	replacer.filename += ".replace";
}

bool Replace::createNewFile(Replace &replacer) {
	std::ofstream outfile(replacer.getFilename().c_str(), std::ios::out | std::ios::binary);
	if (!outfile) {
		std::cerr << "Error creating file: " << replacer.getFilename() << std::endl;
		return false;
	}
	outfile << replacer.getContent();
	outfile.close();
	replacer.getContent().clear();
	return true;
}
