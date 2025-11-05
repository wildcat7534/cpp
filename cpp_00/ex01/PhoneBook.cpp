#include "PhoneBook.hpp"

#include <cstdlib>
#include <cerrno>
#include <climits>


bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

PhoneBook::PhoneBook() : _nbContact(0), _indexContact(0), _modulo(0), _limitContact(8) {
}

std::string formatField(const std::string& input) {
    if (input.length() > 10)
        return input.substr(0, 9) + ".";
    else
        return input;
}

void	PhoneBook::addContact(Contact newContact) {

	if (this->_nbContact >= _limitContact){
		std::cout << std::endl << "[/\\ CONTACT LIMIT REACHED]" << std::endl;
		this->_indexContact = this->_modulo % _limitContact;
		this->_modulo++;
		std::cout << ">> The new contact will overwrite the contact n°" << this->_indexContact + 1 << std::endl;
		_repertory[this->_indexContact].printContactInfo();
		std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
		this->_repertory[this->_indexContact] = newContact;
		_repertory[this->_indexContact].printContactInfo();
		std::cout << std::endl << ">> Contact saved !" << std::endl;
		return ;
	}
	//newContact.askAndSetContactInfo();
	newContact.printContactInfo();
	
	std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
	this->_repertory[_indexContact] = newContact;
	this->_nbContact++;
	this->_indexContact++;
	std::cout << std::endl << ">> Contact saved !" << std::endl;
}

void	PhoneBook::addContact(){
	if (this->_nbContact >= _limitContact){
		std::cout << std::endl << "[/\\ CONTACT LIMIT REACHED]" << std::endl;
		this->_indexContact = this->_modulo % _limitContact;
		this->_modulo++;
		std::cout << ">> The new contact will overwrite the contact n°" << this->_indexContact + 1 << std::endl;
		_repertory[this->_indexContact].printContactInfo();
		_repertory[this->_indexContact].askAndSetContactInfo();
		_repertory[this->_indexContact].printContactInfo();
		std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
		std::cout << std::endl << ">> Contact saved !" << std::endl;
		return ;
	}
	Contact 	newContact;
	newContact.askAndSetContactInfo();
	newContact.printContactInfo();

	std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
	this->_repertory[_indexContact] = newContact;
	this->_nbContact++;
	this->_indexContact++;
	std::cout << std::endl << ">> Contact saved !" << std::endl;
}

Contact&	PhoneBook::getContact(int nb) {
	if (nb < 1 || nb > _limitContact) {
		return *new Contact();
	}
	return _repertory[nb - 1];
}

int	PhoneBook::getNbContact() const {
	return (_nbContact);
}

void PhoneBook::searchContact() {
	std::cout << "Searching contact..." << std::endl;
	int i = 1;
	std::cout << "Nb de contact :" << this->getNbContact() << std::endl << std::endl;
	std::cout << std::setw(10) << "ID" << "|" 
		<< std::setw(10) << "FirstName" << "|"
		<< std::setw(10) << "LastName" << "|" 
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	//std::cout << std::endl;
	while (this->getNbContact() != 0 && this->getNbContact() >= i){
		std::cout << CYAN << BOLD ;
		std::cout << std::setw(10) << i << "|" 
		<< std::setw(10) << formatField(this->getContact(i).getFirstName()) << "|" 
		<< std::setw(10) << formatField(this->getContact(i).getLastName()) << "|" 
		<< std::setw(10) << formatField(this->getContact(i).getNickname()) << "|" 
		<< std::endl;
		std::cout << RESET;
		i++;
	}
	std::cout << std::endl;
	std::string id;
	std::cout << "select ID and we will search it for you :) : ";
	getline(std::cin, id);
	if (id.empty()) {
		std::cout << "ID cannot be empty." << std::endl;
		return ;
	}
	if (id.length() > 2) {
		std::cout << "ID too long." << std::endl;
		return ;
	}
	if (!is_digit(id[0])) {
		std::cout << "ID " << id << " must be a number." << std::endl;
		return ;
	}
	int int_id = std::atoi(id.c_str());
	if (int_id < 1 || int_id > this->getNbContact() || int_id > 8) {
		std::cout << "ID out of range." << std::endl;
		return ;
	}

	std::cout << "ID :" << id << std::endl;
	std::cout << this->getContact(int_id).getFirstName() << std::endl;
	std::cout << this->getContact(int_id).getLastName() << std::endl;
	std::cout << this->getContact(int_id).getNickname() << std::endl;
	std::cout << this->getContact(int_id).getPhoneNumber() << std::endl;
	std::cout << this->getContact(int_id).getSecret() << std::endl;
}

