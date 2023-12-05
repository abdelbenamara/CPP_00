/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 12:02:40 by abenamar         ###   ########.fr       */
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

	void addContact();
	void previewContacts() const;
	void showContactDetails(int index) const;

private:
	int oldestIndex;
	Contact contacts[8];

	Contact *wipeContact(int index);
	std::string truncate(std::string const str) const;
};

#endif
