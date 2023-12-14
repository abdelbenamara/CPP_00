/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:25:09 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/14 13:00:37 by abenamar         ###   ########.fr       */
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

	std::string getFirstName(void) const;
	void setFirstName(std::string firstName);
	std::string getLastName(void) const;
	void setLastName(std::string lastName);
	std::string getNickname(void) const;
	void setNickname(std::string nickname);
	std::string getPhoneNumber(void) const;
	void setPhoneNumber(std::string phoneNumber);
	std::string getDarkestSecret(void) const;
	void setDarkestSecret(std::string darkestSecret);
	bool isValid(void) const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
