/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:25:09 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:26:53 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	std::string const &getFirstName(void) const;
	void setFirstName(std::string const &firstName);
	std::string const &getLastName(void) const;
	void setLastName(std::string const &lastName);
	std::string const &getNickname(void) const;
	void setNickname(std::string const &nickname);
	std::string const &getPhoneNumber(void) const;
	void setPhoneNumber(std::string const &phoneNumber);
	std::string const &getDarkestSecret(void) const;
	void setDarkestSecret(std::string const &darkestSecret);
	bool isValid(void) const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
