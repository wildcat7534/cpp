#include <iostream>
#include <string>


#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#include "PhoneBook.cpp"

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}
// ADD, seulement dans le main, gerer avec la classe contact (appeler par phonebook) 
// le process d'ajout d'un contact
// SEARCH, gerer par phonebook
// CTRL - D et CTRL - C a gerer 
// VALGRIND --leaks=full --track-origins=yes --show-leak-kinds=all
// corriger affichage debut main 8 contacts


int	main(){

	// Contact clement("Clement", "Massol", "WiLDCaT", "0612270367", "j'aime les bateaux");
	// Contact ariane("Ariane", "Saulnier", "AriA", "0612345789", "j'aime les chiens");
	// Contact paul("paul", "KouaneKouaneKouane", "PetitPaul", "0712345689", "j'aime les chats");

	// PhoneBook book;
	
	// book.addContact(clement);
	// book.addContact(ariane);
	// book.addContact(paul);
	// std::cout << book.getContact(1).getFirstName() << std::endl;
	// std::cout << book.getContact(2).getFirstName() << std::endl;
	// std::cout << book.getContact(3).getFirstName() << std::endl;

	std::cout << std::endl;
	std::cout << BOLD << RED <<"       ********** Welcome to your PhoneBook **********" << RESET << std::endl<< std::endl;
	std::cout << BOLD << "You can store up to 8 contacts." << RESET << std::endl;
	std::cout << BOLD << "exemple deja rempli avec 3 contacts (mettre limite a 3)" << RESET << std::endl;

	while (1){
		PhoneBook book;
		std::string command;
		std::cout << std::endl << "Use the commands :"<< MAGENTA << " ADD"<< RESET << ", "<< MAGENTA << "SEARCH"<< RESET << " or" << MAGENTA << " EXIT :" << RESET << std::endl;
		std::cout << ">>> ";
		if (getline(std::cin, command))
		{
			if (command == "ADD"){
				std::cout << "** Command: "<< MAGENTA << command << RESET << " received." << std::endl;


				book.addContact();
				
			}

			if (command == "SEARCH"){
				std::string id;
				std::cout << "** Command: " << MAGENTA << command << RESET << " received." << std::endl;
				std::cout << std::endl;
				int i = 1;
				std::cout << std::setw(10) << "ID" << "|" 
					<< std::setw(10) << "FirstName" << "|"
					<< std::setw(10) << "LastName" << "|" 
					<< std::setw(10) << "Nickname" << "|" << std::endl;
				std::cout << "[DEBUG] Nb de contact :" << book.getNbContact() << std::endl;
				std::cout << std::endl;
				while (book.getNbContact() != 0 && book.getNbContact() >= i){
					std::cout << CYAN << BOLD ;
					std::cout << std::setw(10) << i << "|" 
					<< std::setw(10) << formatField(book.getContact(i).getFirstName()) << "|" 
					<< std::setw(10) << formatField(book.getContact(i).getLastName()) << "|" 
					<< std::setw(10) << formatField(book.getContact(i).getNickname()) << "|" 
					<< std::endl;
					std::cout << RESET;
					i++;
				}
				std::cout << std::endl;
				std::cout << "select ID and we will search it for you :) : ";
				getline(std::cin, id);
				if (id.length() > 8) {
					std::cout << "ID too long." << std::endl;
					continue;
				}
				if (id.empty()) {
					std::cout << "ID cannot be empty." << std::endl;
					continue;
				}
				if (!std::all_of(id.begin(), id.end(), ::isdigit)) {
					std::cout << "ID must be a number." << std::endl;
					continue;
				}
				if (std::stoi(id) < 1 || std::stoi(id) > book.getNbContact()) {
					std::cout << "ID out of range." << std::endl;
					continue;
				}
				int idint = std::stoi(id);
				std::cout << "ID :" << id << std::endl;
				std::cout << book.getContact(idint).getFirstName() << std::endl;
				std::cout << book.getContact(idint).getLastName() << std::endl;
				std::cout << book.getContact(idint).getNickname() << std::endl;
				std::cout << book.getContact(idint).getPhoneNumber() << std::endl;
				std::cout << book.getContact(idint).getSecret() << std::endl;
			}
			if (command == "EXIT"){
				std::cout << "*********  Merci au revoir :)  ***********" << std::endl;
				break;
			}
		}
	}

}
