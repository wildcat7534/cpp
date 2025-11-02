#include "PhoneBook.hpp"
#include "Contact.hpp"

// ADD, seulement dans le main, gerer avec la classe contact (appeler par phonebook) 
// le process d'ajout d'un contact
// SEARCH, gerer par phonebook
// CTRL - D et CTRL - C a gerer 
// VALGRIND --leaks=full --track-origins=yes --show-leak-kinds=all
// corriger affichage debut main 8 contacts


int	main(){

	// [DEBUG] exemple deja rempli avec 8 contacts //////
	Contact clement("Clement", "Massol", "WiLDCaT", "0612270367", "j'aime Baldur's Gate");
	Contact ariane("Ariane", "Saulnier", "AriA", "0612345789", "j'aime les potis chiens");
	Contact lapinou("Lapinou", "LeGrandLapin", "Lapinou", "0611122233", "j'aime les carottes");
	Contact Kamila("Kamila", "LaKamikaze", "Kamy", "0622233344", "j'aime le parachute");
	Contact lucas("Lucas", "LePetitLucas", "Lulu", "0633344455", "j'aime les legos");
	Contact emma("Emma", "Lemaitre", "Emmy", "0644455566", "j'aime la danse");
	Contact noah("Noah", "Duval", "NoNo", "0655566677", "j'aime le foot");
	Contact paul("Paul", "Durand", "Paulo", "0677788899", "j'aime la musique");
	Contact test("Test", "User", "Tester", "0688899000", "j'aime les tests");

	PhoneBook myPhoneBook;
	myPhoneBook.addContact(clement);
	myPhoneBook.addContact(ariane);
	myPhoneBook.addContact(paul);
	myPhoneBook.addContact(lapinou);
	myPhoneBook.addContact(Kamila);
	myPhoneBook.addContact(lucas);
	myPhoneBook.addContact(emma);
	myPhoneBook.addContact(noah);
	myPhoneBook.addContact(test); // to test overwrite when limit reached

	// Fin [DEBUG] exemple deja rempli avec 8 contacts //////

	std::cout << std::endl;
	std::cout << BOLD << RED <<"       ********** Welcome to your PhoneBook **********" << RESET << std::endl<< std::endl;
	std::cout << BOLD << "You can store up to 8 contacts." << RESET << std::endl;
	std::cout << BOLD << "[DEBUG] Exemple deja rempli avec 8 contacts" << RESET << std::endl;

	//PhoneBook book; // decommenter si [DEBUG] exemple deja rempli avec 8 contacts est desactive
	while (1){
		std::string command;
		std::cout << std::endl << "Use the commands :"<< MAGENTA << " ADD"<< RESET << ", "<< MAGENTA << "SEARCH"<< RESET << " or" << MAGENTA << " EXIT :" << RESET << std::endl;
		std::cout << ">>> ";
		if (getline(std::cin, command))
		{
			if (command == "ADD"){
				std::cout << "** Command: "<< MAGENTA << command << RESET << " received." << std::endl;
				myPhoneBook.addContact();
			}

			if (command == "SEARCH"){
				std::cout << "** Command: " << MAGENTA << command << RESET << " received." << std::endl;
				std::cout << std::endl;
				myPhoneBook.searchContact();
			}
			if (command == "EXIT"){
				std::cout << "*********  Merci au revoir :)  ***********" << std::endl;
				break;
			}
		}
	}

}
