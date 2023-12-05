/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:16:27 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/04 22:43:20 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""),
					 _lastName(""),
					 _nickname(""),
					 _phoneNumber(""),
					 _darkestSecret("")
{
	return;
}

Contact::~Contact()
{
	return;
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;

	return;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;

	return;
}

std::string Contact::getNickname() const
{
	return this->_nickname;
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;

	return;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;

	return;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;

	return;
}

bool Contact::isValid() const
{
	if (this->_firstName.empty() ||
		this->_lastName.empty() ||
		this->_nickname.empty() ||
		this->_phoneNumber.empty() ||
		this->_darkestSecret.empty())
		return false;

	return true;
}
