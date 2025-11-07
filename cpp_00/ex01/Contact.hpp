#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _secret;
		int			_phoneNumber;

	public:
		Contact();

		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret);

		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(int phoneNumber);
		void		setSecret(std::string secret);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		int			getPhoneNumber() const;
		std::string	getSecret() const;
		//void		setAll(std::string firstName, std::string lastName, std::string nickname, int phoneNumber,  std::string secret);
		int 		askAndSetContactInfo();
		void 		printContactInfo();
};

#endif
