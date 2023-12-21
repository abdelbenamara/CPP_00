/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:08:51 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:38 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : oldestIndex(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

bool PhoneBook::addContact(void)
{
	Contact &contact = this->wipeContact(this->oldestIndex);

	contact.setFirstName(this->askForContactInfo("first name"));
	contact.setLastName(this->askForContactInfo("last name"));
	contact.setNickname(this->askForContactInfo("nickname"));
	contact.setPhoneNumber(this->askForContactInfo("phone number"));
	contact.setDarkestSecret(this->askForContactInfo("darkest secret"));

	if (contact.isValid())
	{
		this->oldestIndex = (this->oldestIndex + 1) % 8;

		if (!std::cin || std::cin.eof())
			std::cout << std::endl;

		return true;
	}

	if (!std::cin || std::cin.eof())
		std::cout << std::endl;

	std::cout << std::endl;
	std::cerr << "Error: contact cannot have empty fields !" << std::endl;

	if (std::cin && !std::cin.eof())
		std::cout << std::endl;

	return false;
}

void PhoneBook::previewContacts(void) const
{
	if (!std::cin || std::cin.eof())
		std::cout << std::endl;

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

void PhoneBook::showContactInformations(int const index) const
{
	if (!std::cin || std::cin.eof())
		std::cout << std::endl;

	if (index < 0 || 7 < index)
	{
		std::cout << std::endl;
		std::cerr << "Error: invalid index" << std::endl;

		return;
	}
	else if (!this->contacts[index].isValid())
	{
		std::cout << std::endl;
		std::cerr << "Error: no contact at index `";
		std::cerr << index << "'" << std::endl;

		return;
	}

	std::cout << std::endl;
	this->showContactInfo("first name",
						  this->contacts[index].getFirstName());
	this->showContactInfo("last name",
						  this->contacts[index].getLastName());
	this->showContactInfo("nickname",
						  this->contacts[index].getNickname());
	this->showContactInfo("phone number",
						  this->contacts[index].getPhoneNumber());
	this->showContactInfo("darkest secret",
						  this->contacts[index].getDarkestSecret());

	return;
}

Contact &PhoneBook::wipeContact(int const index)
{
	this->contacts[index].setFirstName("");
	this->contacts[index].setLastName("");
	this->contacts[index].setNickname("");
	this->contacts[index].setPhoneNumber("");
	this->contacts[index].setDarkestSecret("");

	return this->contacts[index];
}

std::string PhoneBook::askForContactInfo(std::string const &label) const
{
	std::locale loc;
	std::string line;

	if (std::cin && !std::cin.eof())
	{
		std::cout << std::right << std::setfill(' ');
		std::cout << std::setw(14) << label << ": ";
		std::getline(std::cin, line);

		for (std::size_t i = 0; i < line.length(); ++i)
		{
			if (!std::isprint(line.at(i), loc))
				line.at(i) = '?';
		}
	}

	return line;
}

std::string PhoneBook::truncate(std::string const &str) const
{
	if (str.length() <= 10)
		return str;

	return str.substr(0, 9) + ".";
}

void PhoneBook::showContactInfo(std::string const &label,
								std::string const &info) const
{
	std::cout << std::right << std::setfill(' ');
	std::cout << std::setw(14) << label << ": \"";
	std::cout << info << "\"" << std::endl;
}
