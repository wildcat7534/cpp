# include <iostream>
# include <string>
# include <regex>
# include <iomanip>
# include "Contact.hpp"


Contact::Contact(){}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret){
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = (stoi(phoneNumber));
	this->_secret = secret;
}

void	Contact::setFirstName(std::string firstName){
	this->_firstName = firstName;
}
void	Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}
void	Contact::setNickname(std::string nickname){
	this->_nickname = nickname;
}
void	Contact::setPhoneNumber(int phoneNumber){
	this->_phoneNumber = phoneNumber;
}
void	Contact::setSecret(std::string secret){
	this->_secret = secret;
}
std::string	Contact::getFirstName(){
	return this->_firstName;
}
std::string	Contact::getLastName(){
	return this->_lastName;
}
std::string	Contact::getNickname(){
	return this->_nickname;
}
int			Contact::getPhoneNumber(){
	return this->_phoneNumber;
}
std::string	Contact::getSecret(){
	return this->_secret;
}
void	Contact::setAll(std::string firstName, std::string lastName, std::string nickname, int phoneNumber,  std::string secret){
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_secret = secret;
}
void	Contact::askAndSetContactInfo(){
	const std::regex motif("^(06|07)\\d{8}$");
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
				this->setFirstName(firstName);
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
				this->setLastName(lastName);
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
				this->setNickname(nickname);
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
				this->setPhoneNumber(phone);
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
				this->setSecret(darkSecret);
				break;
			}
		}
}
void	Contact::printContactInfo(){
	std::cout << "First Name: " << this->getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getLastName() <<  std::endl;
	std::cout << "Nickname: " << this->getNickname() <<  std::endl;
	std::cout << "Phone Number: " << this->getPhoneNumber() <<  std::endl;
	std::cout << "Dark Secret: " << this->getSecret() <<  std::endl;
}