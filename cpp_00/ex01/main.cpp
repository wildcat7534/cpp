#include <iostream>
#include <string>
#include <regex>
#include <thread>
#include <chrono>
#include <iomanip>
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

int	main(){

	Contact ariane; 
	Contact clement;
	Contact paul;

	clement.setFirstName("Clement");
	clement.setLastName("Massol");
	clement.setNickname("WiLDCaT");
	clement.setPhoneNumber(std::stoi("0612270367"));
	clement.setSecret("j'aime les bateaux");
	ariane.setFirstName("Ariane");
	ariane.setLastName("Saulnier");
	ariane.setNickname("AriA");
	ariane.setPhoneNumber(std::stoi("0612345789"));
	ariane.setSecret("j'aime les chiens");	
	paul.setFirstName("paul");
	paul.setLastName("KouaneKouaneKouane");
	paul.setNickname("PetitPaul");
	paul.setPhoneNumber(std::stoi("0712345689"));
	paul.setSecret("j'aime les chats");

	PhoneBook book;
	
	book.addContact(clement);
	book.addContact(ariane);
	book.addContact(paul);

	std::cout << std::endl;
	std::cout << BOLD << RED <<"       ********** Welcome to your PhoneBook **********" << RESET << std::endl<< std::endl;
	std::cout << BOLD << "You can store up to 3 contacts." << RESET << std::endl;
	std::cout << BOLD << "exemple deja rempli avec 3 contacts." << RESET << std::endl;
	std::cout << book.getContact(1).getFirstName() << std::endl;
	std::cout << book.getContact(2).getFirstName() << std::endl;
	std::cout << book.getContact(3).getFirstName() << std::endl;

	while (1){
		//PhoneBook book;
		std::string command;
		const std::regex motif("^(06|07)\\d{8}$");
		std::cout << std::endl << "Use the commands :"<< MAGENTA << " ADD"<< RESET << ", "<< MAGENTA << "SEARCH"<< RESET << " or" << MAGENTA << " EXIT :" << RESET << std::endl;
		std::cout << ">>> ";
		if (getline(std::cin, command))
		{
			if (command == "ADD"){
				std::cout << "** Command: "<< MAGENTA << command << RESET << " received." << std::endl;
				Contact 	newContact;
				std::string firstName;
				std::string lastName;
				std::string nickname;
				std::string	phoneNumber;
				std::string darkSecret;

				std::cout << "	Enter first name: ";
				while (getline(std::cin, firstName)){
					if (firstName == ""){
						std::cout << "cannot be void !" << std::endl;
						std::cout << "	Enter first name: ";
					}
					else{
						newContact.setFirstName(firstName);
						break;
					}
				}
				std::cout << "	Enter last name: ";
				while (getline(std::cin, lastName)){
					if (lastName == ""){
						std::cout << "cannot be void !" << std::endl;
						std::cout << "	Enter last name: ";
					}
					else{
						newContact.setLastName(lastName);
						break;
					}
				}
				std::cout << "	Enter nickname : ";
				while (getline(std::cin, nickname)){
					if (nickname == ""){
						std::cout << "cannot be void !" << std::endl;
						std::cout << "	Enter nickname : ";
					}
					else{
						newContact.setNickname(nickname);
						break;
					}
				}
				std::cout << "	Enter phone number: ";
				while (getline(std::cin, phoneNumber)){
					if (phoneNumber == ""){
						std::cout << "cannot be void !" << std::endl;
						std::cout << "	Enter phone number: ";
					}
					else if ((std::regex_match(phoneNumber, motif) == 0)){
						std::cout << "Not a phone number." << std::endl;
						std::cout << "	Enter phone number: ";
					}
					else{
						int phone = std::stoi(phoneNumber);
						newContact.setPhoneNumber(phone);
						break;
					}
				}
				std::cout << "	Enter darki secret (or not so dark..): ";
				while (getline(std::cin, darkSecret)){
					if (darkSecret == ""){
						std::cout << "cannot be void !" << std::endl;
						std::cout << "	Enter darki secret (or not so dark..): ";
					}
					else{
						newContact.setSecret(darkSecret);
						break;
					}
				}
				std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				book.addContact(newContact);
				std::cout << std::endl << ">> Contact saved !" << std::endl;
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
