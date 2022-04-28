/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/04/28 12:11:35 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void) const;

	private:
		int		count;
		Contact	contact[8];
		void	print_all(void) const;
		void	print_col(std::string str, int mode) const;
		void	print_contact(int index) const;
		void	print_header(void) const;
		int		index_check(std::string inp) const;
};
#endif
