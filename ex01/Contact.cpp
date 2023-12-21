/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:16:27 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 12:54:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : firstName(""),
						 lastName(""),
						 nickname(""),
						 phoneNumber(""),
						 darkestSecret("")
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string const &Contact::getFirstName(void) const
{
	return this->firstName;
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;

	return;
}

std::string const &Contact::getLastName(void) const
{
	return this->lastName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;

	return;
}

std::string const &Contact::getNickname(void) const
{
	return this->nickname;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;

	return;
}

std::string const &Contact::getPhoneNumber(void) const
{
	return this->phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;

	return;
}

std::string const &Contact::getDarkestSecret(void) const
{
	return this->darkestSecret;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;

	return;
}

bool Contact::isValid(void) const
{
	if (this->firstName.empty() ||
		this->lastName.empty() ||
		this->nickname.empty() ||
		this->phoneNumber.empty() ||
		this->darkestSecret.empty())
		return false;

	return true;
}
