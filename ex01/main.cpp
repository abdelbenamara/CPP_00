/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:18:11 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 20:39:48 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int strToIndex(std::string str)
{
	int sign;
	std::size_t n;

	sign = 1;
	n = 0;

	if (str.length() == 0)
		return -1;

	if (str.length() == 1)
		return str.at(0) - '0';

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

static void addOrSearchContact(PhoneBook *phoneBook, std::string input)
{
	if (input == "ADD")
	{
		while (!std::cin.eof() && !phoneBook->addContact())
			continue;
	}
	else if (input == "SEARCH")
	{
		phoneBook->previewContacts();
		std::cout << ">>> Enter an index between 0 and 7: ";
		std::getline(std::cin, input);
		phoneBook->showContactInformations(strToIndex(input));
	}

	return;
}

int main()
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "Hello, welcome to My Awesome PhoneBook !" << std::endl;
	std::cout << std::endl;
	phoneBook.previewContacts();
	std::cout << std::endl;
	input = "";

	while (!std::cin.eof() && input != "EXIT")
	{
		if (input == "ADD" || input == "SEARCH")
			std::cout << std::endl;

		std::cout << ">>> Enter one command of ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		addOrSearchContact(&phoneBook, input);
	}

	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cerr << "Warning: no more entries (`EOF' reached)" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Your contacts are lost forever, bye !" << std::endl;

	return 0;
}
