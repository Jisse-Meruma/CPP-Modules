/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:26 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 13:24:27 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstname(void) {
	return _first_name;
}

std::string Contact::getLastname(void) {
	return _last_name;
}

std::string Contact::getNickname(void) {
	return _nickname;
}

std::string Contact::getPhonenumber(void) {
	return _phone_number;
}

std::string Contact::getSecrect(void) {
	return _secret;
}

void Contact::setFirstname(std::string string) {
	_first_name = string;
}

void Contact::setLastname(std::string string) {
	_last_name = string;
}

void Contact::setNickname(std::string string) {
	_nickname = string;
}

void Contact::setPhonenumber(std::string string) {
	_phone_number = string;
}

void Contact::setSecrect(std::string string) {
	_secret = string;
}
