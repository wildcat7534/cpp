#include <iostream>
#include "Contact.cpp"
#include <thread>
#include <chrono>
#include <iomanip>

class PhoneBook{
	private:
		Contact _tableau[8];
		int		_nbContact = 0;
		//int		_limitContact = 3; // pour le test/dev on met 3
		int		_limitContact = 8;

	public:
		PhoneBook(){}

		void	addContact(){
			if (this->_nbContact >= _limitContact){
				std::cout << std::endl << "[/\\ CONTACT LIMIT REACHED]" << std::endl;
				_nbContact = _limitContact;
			}
			else
				this->_nbContact++;

			Contact 	newContact;
			newContact.askAndSetContactInfo();
			newContact.printContactInfo();

			std::cout << std::endl << ">> Saving contact... please wait..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			this->_tableau[_nbContact] = newContact;
			std::cout << std::endl << ">> Contact saved !" << std::endl;
		}
		Contact&	getContact(int nb){
			if (nb < 1 || nb > _limitContact) {
				return *new Contact();
			}
			return _tableau[nb];
		}
		int	getNbContact(){
				return (_nbContact);
		}
};
