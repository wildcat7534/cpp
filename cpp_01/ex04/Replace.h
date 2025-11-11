#ifndef REPLACE_H
# define REPLACE_H
# include <string>
# include <fstream>
# include <iostream>

class Replace {
	private:
		std::string filename;
		std::string search;
		std::string replacement;
		std::string content;
	public:
		Replace(std::string const &filename, std::string const &search, std::string const &replacement);
		std::string getFilename() const;
		std::string getSearch() const;
		std::string getReplacement() const;
		std::string getContent() const;
		bool readFileContent(Replace &replacer);
		void replaceInFile(Replace &replacer);
		void setNewFileName(Replace &replacer);
		bool createNewFile(Replace &replacer);
		bool closeFile(std::ofstream &outfile);
};

#endif