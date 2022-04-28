/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:28:07 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/28 10:09:56 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << "Enter Command(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break ;
		if (std::cin.eof())
			break ;
	}
	return (0);
}
