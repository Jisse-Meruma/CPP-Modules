#include <string>

class Contact {

	public:
		std::string getFirstname(void);
		std::string getLastname(void);
		std::string getNickname(void);
		std::string getPhonenumber(void);
		std::string getSecrect(void);

		void setFirstname(std::string string);
		void setLastname(std::string string);
		void setNickname(std::string string);
		void setPhonenumber(std::string string);
		void setSecrect(std::string string);

		
		

	private:
		std::string	first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string secret;
};