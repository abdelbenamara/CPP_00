/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/06 18:23:00 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	bool addContact();
	void previewContacts() const;
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
