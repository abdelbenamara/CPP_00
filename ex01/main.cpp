/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:18:11 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 16:58:34 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int strToIndex(std::string str)
{
	if (str.length() == 0 || str.length() > 2)
		return -1;

	if (str.length() == 1)
		return str.at(0) - '0';

	if (str.at(0) == '-' && str.at(1) == '0')
		return 0;

	if (str.at(0) == '+')
		return str.at(1) - '0';

	return -1;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string input;

	std::cout << "Hello, welcome to My Awesome PhoneBook !" << std::endl;
	phoneBook.previewContacts();
	input = "";

	while (!std::cin.eof() && input != "EXIT")
	{
		std::cout << ">>> Enter one command of ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);

		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
		{
			phoneBook.previewContacts();
			std::cout << ">>> Enter an index between 0 and 7: ";
			std::getline(std::cin, input);
			phoneBook.showContactDetails(strToIndex(input));
		}
	}

	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cerr << "Error: no character left (`EOF' reached)" << std::endl;
	}

	std::cout << "Your contacts are lost forever, bye !" << std::endl;

	return 0;
}
