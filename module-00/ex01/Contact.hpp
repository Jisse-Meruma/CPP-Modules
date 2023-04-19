/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:29 by jmeruma           #+#    #+#             */
/*   Updated: 2023/04/17 13:24:30 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::string	_first_name;
		std::string _last_name;
		std::string _nickname;
		std::string	_phone_number;
		std::string _secret;
};