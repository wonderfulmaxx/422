/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:26:58 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/17 15:09:35 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add_contact(void)
{
	nb_contacts ++;

	if (nb_contacts % 9 == 0)
		nb_contacts ++;
}

int	PhoneBook::get_n_contact(void)
{
	return (nb_contacts);
}

int	PhoneBook::input_number(void)
{
	int number = 0;
	int counter = 0;

	while (number < 1 || number > 8 || number > nb_contacts)
	{
		if (counter > 0)
			std::cout  << "*UNKNOWN*" << std:: endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout  << "ENTER AN INDEX : ";
		std::cin >> number; 
		counter ++;
	}
	std::cout << std::endl;
	return(number - 1);
}