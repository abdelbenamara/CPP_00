/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:49:45 by abenamar          #+#    #+#             */
/*   Updated: 2023/12/05 21:22:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			while (*argv[i])
			{
				std::cout << static_cast<char>(toupper(*argv[i]));
				++argv[i];
			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::cout << std::endl;

	return 0;
}
