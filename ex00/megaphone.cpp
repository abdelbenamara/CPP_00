/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:49:45 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/06 16:29:32 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int main(int argc, char *argv[])
{
	std::locale loc;
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			str = argv[i];

			for (std::size_t n = 0; n < str.length(); ++n)
				std::cout << std::toupper(str.at(n), loc);
		}
	}

	std::cout << std::endl;

	return 0;
}
