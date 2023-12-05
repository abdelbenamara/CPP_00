/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:08:51 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 12:02:40 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->oldestIndex = 0;

	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

Contact *PhoneBook::wipeContact(int index)
{
	this->contacts[index].setFirstName("");
	this->contacts[index].setLastName("");
	this->contacts[index].setNickname("");
	this->contacts[index].setPhoneNumber("");
	this->contacts[index].setDarkestSecret("");

	return &this->contacts[index];
}

void PhoneBook::addContact()
{
	Contact *contact;
	std::string input;

	contact = this->wipeContact(this->oldestIndex);
	std::cout << "first name: ";
	std::getline(std::cin, input);
	contact->setFirstName(input);
	std::cout << "last name: ";
	std::getline(std::cin, input);
	contact->setLastName(input);
	std::cout << "nick name: ";
	std::getline(std::cin, input);
	contact->setNickname(input);
	std::cout << "phone number: ";
	std::getline(std::cin, input);
	contact->setPhoneNumber(input);
	std::cout << "darkest secret: ";
	std::getline(std::cin, input);
	contact->setDarkestSecret(input);

	if (contact->isValid())
		this->oldestIndex = (this->oldestIndex + 1) % 8;
	else
	{
		std::cerr << "A contact cannot have empty fields !" << std::endl;
		this->addContact();
	}

	return;
}

void PhoneBook::previewContacts() const
{
	std::cout << std::right << std::setfill('-');
	std::cout << std::setw(45) << "" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << std::setw(45) << "" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << std::setfill(' ') << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10);
		std::cout << this->truncate(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10);
		std::cout << this->truncate(contacts[i].getLastName());
		std::cout << "|" << std::setw(10);
		std::cout << this->truncate(contacts[i].getNickname());
		std::cout << "|" << std::endl;
		std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
	}
}

void PhoneBook::showContactDetails(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cerr << "Error: invalid index" << std::endl;
		return;
	}
	else if (!this->contacts[index].isValid())
	{
		std::cerr << "Error: no contact at index `";
		std::cerr << index << "'" << std::endl;
		return;
	}

	std::cout << "first name: \"";
	std::cout << this->contacts[index].getFirstName() << "\"" << std::endl;
	std::cout << "last name: \"";
	std::cout << this->contacts[index].getLastName() << "\"" << std::endl;
	std::cout << "nickname: \"";
	std::cout << this->contacts[index].getNickname() << "\"" << std::endl;
	std::cout << "phone number: \"";
	std::cout << this->contacts[index].getPhoneNumber() << "\"" << std::endl;
	std::cout << "darkest secret: \"";
	std::cout << this->contacts[index].getDarkestSecret() << "\"" << std::endl;
}

std::string PhoneBook::truncate(std::string const str) const
{
	if (str.length() <= 10)
		return str;

	return str.substr(0, 9) + ".";
}
