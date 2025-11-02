# include <iostream>
# include <string>
# include <regex>
# include <iomanip>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _secret;
		int			_phoneNumber;

	public:
		Contact(){}

		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret){}

		void	setFirstName(std::string firstName){}
		void	setLastName(std::string lastName){
		}
		void	setNickname(std::string nickname){
		}
		void	setPhoneNumber(int phoneNumber){
		}
		void	setSecret(std::string secret){
		}
		std::string	getFirstName(){
		}
		std::string	getLastName(){
		}
		std::string	getNickname(){
		}
		int			getPhoneNumber(){
		}
		std::string	getSecret(){
		}
		void setAll(std::string firstName, std::string lastName, std::string nickname, int phoneNumber,  std::string secret){
		}
		void askAndSetContactInfo(){
		}
		void printContactInfo(){

		}
};
