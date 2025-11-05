# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include <cerrno>
# include <cstdlib>
# include "Contact.hpp"

bool is_digits(const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

bool is_valid_phone(const std::string& s) {
    if (s.size() != 10) return false;              // longueur must be 10
    if (s[0] != '0') return false;                 // commence par 0
    if (s[1] != '6' && s[1] != '7') return false;  // 06 ou 07
    return is_digits(s);                           // tous les characters sont digits
}

bool parse_int_strtol(const std::string& s, int& out) {
    char* endptr = 0;
    errno = 0; // réinitialiser
    long val = strtol(s.c_str(), &endptr, 10);
    if (endptr == s.c_str()) return false;             // aucun caractère converti
    if (*endptr != '\0') return false;                 // reste des caractères non numériques
    if (errno == ERANGE || val < INT_MIN || val > INT_MAX) return false; // overflow
    out = static_cast<int>(val);
    return true;
}

Contact::Contact(){}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret){
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = parse_int_strtol(phoneNumber, _phoneNumber) ? _phoneNumber : 0;
	this->_secret = secret;
}

void	Contact::setFirstName(std::string firstName) { _firstName = firstName; }
void	Contact::setLastName(std::string lastName) { _lastName = lastName; }
void	Contact::setNickname(std::string nickname) { _nickname = nickname; }
void	Contact::setPhoneNumber(int phoneNumber) { _phoneNumber = phoneNumber; }
void	Contact::setSecret(std::string secret) { _secret = secret; }
std::string	Contact::getFirstName() const { return _firstName; }
std::string	Contact::getLastName() const { return _lastName; }
std::string	Contact::getNickname() const{ return _nickname; }
int			Contact::getPhoneNumber() const { return _phoneNumber; }
std::string	Contact::getSecret() const{ return _secret; }

void	Contact::setAll(std::string firstName, std::string lastName, std::string nickname, int phoneNumber,  std::string secret){
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_secret = secret;
}
void	Contact::askAndSetContactInfo(){
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
				setFirstName(firstName);
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
				setLastName(lastName);
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
				setNickname(nickname);
				break;
			}
		}
		std::cout << "	Enter phone number: ";
		while (getline(std::cin, phoneNumber)){
			if (phoneNumber == ""){
				std::cout << "cannot be void !" << std::endl;
				std::cout << "	Enter phone number: ";
			}
			else if ((is_valid_phone(phoneNumber) == 0)){
				std::cout << "Not a phone number." << std::endl;
				std::cout << "	Enter phone number: ";
			}
			else{
				int phone;
				if (parse_int_strtol(phoneNumber, phone)){
					setPhoneNumber(phone);
				}
				else{
					std::cout << "Error converting phone number." << std::endl;
				}
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
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() <<  std::endl;
	std::cout << "Nickname: " << getNickname() <<  std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() <<  std::endl;
	std::cout << "Dark Secret: " << getSecret() <<  std::endl;
}
