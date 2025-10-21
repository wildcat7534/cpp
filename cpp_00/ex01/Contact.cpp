#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string secret;
		int			phoneNumber;

	public:
		Contact(){}

		void	setFirstName(std::string firstName){
			this->firstName = firstName;
		}
		void	setLastName(std::string lastName){
			this->lastName = lastName;
		}
		void	setNickname(std::string nickname){
			this->nickname = nickname;
		}
		void	setPhoneNumber(int phoneNumber){
			this->phoneNumber = phoneNumber;
		}
		void	setSecret(std::string secret){
			this->secret = secret;
		}
		std::string	getFirstName(){
			return this->firstName;
		}
		std::string	getLastName(){
			return this->lastName;
		}
		std::string	getNickname(){
			return this->nickname;
		}
		int			getPhoneNumber(){
			return this->phoneNumber;
		}
		std::string	getSecret(){
			return this->secret;
		}
};
