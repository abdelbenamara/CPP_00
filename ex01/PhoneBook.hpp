/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/21 13:32:58 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	bool addContact(void);
	void previewContacts(void) const;
	void showContactInformations(int const index) const;

private:
	int oldestIndex;
	Contact contacts[8];

	Contact &wipeContact(int const index);
	std::string askForContactInfo(std::string const &label) const;
	std::string truncate(std::string const &str) const;
	void showContactInfo(std::string const &label,
						 std::string const &info) const;
};

#endif
