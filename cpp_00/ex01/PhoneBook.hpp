#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"
#include <signal.h>

#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

extern volatile sig_atomic_t g_running;

class PhoneBook {
	private:
		Contact _repertory[8];
		int		_nbContact;
		int		_indexContact;
		int		_modulo;
		//int		_limitContact = 4; // pour le test/dev on met 4
		int		_limitContact;

	public:
		PhoneBook();
		void	addContact(Contact newContact);
		void	addContact();
		Contact&	getContact(int nb);
		int	getNbContact() const;
		void searchContact();
};

#endif
