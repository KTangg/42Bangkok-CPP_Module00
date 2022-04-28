/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:31 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/27 21:33:01 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

const std::string	info_words[5] =
{
	"Firstname",
	"Lastname",
	"Nickname",
	"Phonenumber",
	"Darkest Secret"
};

enum
{
	firstname,
	lastname,
	nickname,
	phonenumber,
	secret
};

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		set_info(std::string str[5]);
		std::string	get_info(int info) const;

	private:
		std::string	contact_info[5];
};

#endif
