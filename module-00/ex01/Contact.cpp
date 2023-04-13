#include "Contact.hpp"

std::string Contact::getFirstname(void) {
	return first_name;
}

std::string Contact::getLastname(void) {
	return last_name;
}

std::string Contact::getNickname(void) {
	return nickname;
}

std::string Contact::getPhonenumber(void) {
	return phone_number;
}

std::string Contact::getSecrect(void) {
	return secret;
}

void Contact::setFirstname(std::string string) {
	first_name = string;
}

void Contact::setLastname(std::string string) {
	last_name = string;
}

void Contact::setNickname(std::string string) {
	nickname = string;
}

void Contact::setPhonenumber(std::string string) {
	phone_number = string;
}

void Contact::setSecrect(std::string string) {
	secret = string;
}
