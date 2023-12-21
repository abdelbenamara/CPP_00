/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:18:11 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:31:29 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static int stringToIndex(std::string const &str)
{
	int sign;
	std::size_t n;

	if (str.length() == 0)
		return -1;

	if (str.length() == 1)
		return str.at(0) - '0';

	sign = 1;
	n = 0;

	if (str.at(0) == '-' || str.at(0) == '+')
	{
		if (str.at(0) == '-')
			sign = -1;

		++n;
	}

	while (n < str.length() - 1 && str.at(n) == '0')
		++n;

	if (n < str.length() - 1 || str.at(n) < '0' || '7' < str.at(n))
		return -1;

	return sign * (str.at(n) - '0');
}

static void addOrSearchContact(PhoneBook &phoneBook, std::string const &command)
{
	std::string line;

	if (command == "ADD")
	{
		while (std::cin && !std::cin.eof() && !phoneBook.addContact())
			continue;

		if (std::cin && !std::cin.eof())
			std::cout << std::endl;
	}
	else if (command == "SEARCH")
	{
		phoneBook.previewContacts();
		std::cout << ">>> Enter an index between 0 and 7: ";
		std::getline(std::cin, line);
		phoneBook.showContactInformations(stringToIndex(line));

		if (std::cin && !std::cin.eof())
			std::cout << std::endl;
	}

	return;
}

static void runPhoneBook(PhoneBook &phoneBook)
{
	std::string line;

	while (std::getline(std::cin, line) && line != "EXIT")
	{
		std::cout << std::endl;
		addOrSearchContact(phoneBook, line);

		if (std::cin.eof())
			break;

		std::cout << ">>> Enter one command of ADD, SEARCH or EXIT: ";
	}

	std::cout << std::endl;

	if (line.empty() || (line == "EXIT" && std::cin.eof()))
		std::cout << std::endl;

	return;
}

int main(void)
{
	PhoneBook phoneBook;

	std::cout << "Hello, welcome to My Awesome PhoneBook !" << std::endl;
	std::cout << std::endl;
	phoneBook.previewContacts();
	std::cout << std::endl;
	std::cout << ">>> Enter one command of ADD, SEARCH or EXIT: ";
	runPhoneBook(phoneBook);

	if (std::cin.eof())
	{
		std::cerr << "Warning: no more entries (`EOF' reached)" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Your contacts are lost forever, bye !" << std::endl;

	return 0;
}
