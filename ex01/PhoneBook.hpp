/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:00:58 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/04 22:51:18 by abenamar         ###   ########.fr       */
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
	int _oldestIndex;
	Contact _contacts[8];

	Contact *wipeContact(int index);
	std::string _truncate(std::string const str) const;
};

#endif
