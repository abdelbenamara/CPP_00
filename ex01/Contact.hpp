/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:25:09 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 12:06:12 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	void setFirstName(std::string firstName);
	std::string getLastName() const;
	void setLastName(std::string lastName);
	std::string getNickname() const;
	void setNickname(std::string nickname);
	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string phoneNumber);
	std::string getDarkestSecret() const;
	void setDarkestSecret(std::string darkestSecret);

	bool isValid() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
