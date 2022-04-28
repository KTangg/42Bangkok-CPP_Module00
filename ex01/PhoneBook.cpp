/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:11:01 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/28 11:45:03 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : count(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(void)
{
	int			index;
	std::string	info[5];

	index = this->count % 8;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Contact " << info_words[i] << ": ";
		std::getline(std::cin, info[i]);
		if (std::cin.eof())
			break ;
	}
	for (int i = 0; i < 5; i++)
	{
		if (info[i] == "")
		{
			std::cout << "Error: Empty Field" << std::endl;
			return ;
		}
	}
	this->contact[index].set_info(info);
	std::cout << "Contact Added" << std::endl;
	this->count++;
}

void	PhoneBook::print_col(std::string str, int mode) const
{
	std::cout << "|";
	if (str.length() > 10)
	{
		std::string trunc_str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << trunc_str;
	}
	else
		std::cout << std::setw(10) << str;
	if (mode == 1)
		std::cout << "|" << std::endl;
}

void	PhoneBook::print_header(void) const
{
	std::cout << " __________ __________ __________ __________" << std::endl;
	PhoneBook::print_col("Index", 0);
	PhoneBook::print_col(info_words[firstname], 0);
	PhoneBook::print_col(info_words[lastname], 0);
	PhoneBook::print_col(info_words[nickname], 1);
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void	PhoneBook::print_all(void) const
{
	int		times;
	char	index[2];
	Contact	cursor;

	index[1] = '\0';
	PhoneBook::print_header();
	times = 8;
	if (count < 8)
		times = count;
	for (int i = 0; i < times; i++)
	{
		index[0] = i + '0';
		cursor = this->contact[i];
		print_col(index, 0);
		print_col(cursor.get_info(firstname), 0);
		print_col(cursor.get_info(lastname), 0);
		print_col(cursor.get_info(nickname), 1);
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

int	PhoneBook::index_check(std::string inp) const
{
	int	len;
	int	index;

	len = inp.length();
	std::string::iterator	cursor = inp.begin();
	if (len != 1)
		return (-1);
	if (!isdigit(*cursor))
		return (-1);
	index = atoi(inp.c_str());
	if (index > 7 || index < 0)
		return (-1);
	else if (index + 1 > this->count)
		return (-1);
	return (index);
}

void	PhoneBook::print_contact(int index) const
{
	for (int i = firstname; i <= secret; i++)
	{
		std::cout << info_words[i] << ": ";
		std::cout << this->contact[index].get_info(i) << std::endl;
	}
}

void	PhoneBook::search_contact(void) const
{
	int			index;
	std::string	inp;

	if (this->count == 0)
	{
		std::cout << "Empty PhoneBook" << std::endl;
		return ;
	}
	PhoneBook::print_all();
	std::cout << "Enter Contact index: ";
	std::getline(std::cin, inp);
	index = index_check(inp);
	if (index == -1)
	{
		std::cout << "Error: Invalid Index" << std::endl;
		return ;
	}
	PhoneBook::print_contact(index);
}
