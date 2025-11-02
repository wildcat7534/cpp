#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

class PhoneBook{
	private:
		Contact _repertory[8];
		int		_nbContact = 0;
		int		_indexContact = 0;
		int		_modulo = 8;
		//int		_limitContact = 4; // pour le test/dev on met 4
		int		_limitContact = 8;

	public:
		PhoneBook() {}
		void	addContact(Contact newContact) {}
		void	addContact() {}
		Contact&	getContact(int nb) {}
		int	getNbContact() const {}
		void searchContact() {}
};

