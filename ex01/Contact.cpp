/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:12:35 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/28 11:45:17 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_info(std::string info[5])
{
	for (int i = 0; i < 5; i++)
	{
		this->contact_info[i] = info[i];
	}
}

std::string	Contact::get_info(int info) const
{
	return (this->contact_info[info]);
}
