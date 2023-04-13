#include "Contact.hpp"
#define SIZE 8

class PhoneBook {
	public:
		// Contact getContact(size_t i);
		// void	setContact(Contact contact);
		void	task_add(size_t i);
		void	task_search(int lenght);
		void	print_contact(std::string data, std::string end);

	private:
		Contact info[SIZE];
};