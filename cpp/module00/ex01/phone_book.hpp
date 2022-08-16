/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:26:56 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/16 12:11:35 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
public:

	Contact();
	~Contact();
	
	void	add();
	void	search();
	void	full_print();

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

class PhoneBook
{
public:

	PhoneBook();
	~PhoneBook();
	
	int		input_number();
	int	get_n_contact();
	void	add_contact();
	void	afficher();
	Contact tab_contact[8];
	
private:

	static int nb_contacts;
	
};
