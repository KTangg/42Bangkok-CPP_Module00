/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:00:31 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/27 14:51:55 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	std::string	word;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			word = argv[i];
			for (size_t j = 0; j < word.length(); j++)
			{
				std::cout << (char) std::toupper(word[j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
