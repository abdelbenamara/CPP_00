/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/14 13:00:45 by abenamar         ###   ########.fr       */
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
	void showContactInformations(int index) const;

private:
	int oldestIndex;
	Contact contacts[8];

	Contact &wipeContact(int index);
	std::string getContactInfo(std::string const label) const;
	void showContactInfo(std::string const label,
						 std::string const info) const;
	std::string truncate(std::string const str) const;
};

#endif
