#include <iostream>
#include "Contact.cpp"

class PhoneBook{
	private:
		Contact tableau[8];
		int		nbContact = 0;
		//int		limitContact = 3; //pour le test/dev on met 3
		int		limitContact = 8;

	public:
		PhoneBook(){}

		void	addContact(Contact contact){
			if (this->nbContact >= limitContact){
				std::cout << std::endl << "[/\\ CONTACT LIMIT REACHED]" << std::endl;
				nbContact = limitContact;
			}
			else
				this->nbContact++;
			this->tableau[nbContact] = contact;
		}
		Contact	getContact(int nb){
			if (nb < 1 || nb > limitContact) {
				return Contact();
			}
			return tableau[nb];
		}
		int	getNbContact(){
				return (nbContact);
		}
};
