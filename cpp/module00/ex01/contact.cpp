/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:27:03 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/17 15:09:38 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::add(void)
{
	int counter = 0;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (counter <= 4)
	{
		if (counter == 0)
			std::cout << "First Name: ";
		if (counter == 1)
			std::cout << "Last Name: ";
		if (counter == 2)
			std::cout << "Nickname: ";
		if (counter == 3)
			std::cout << "Phone Number: ";
		if (counter == 4)
			std::cout << "Darkest Secret: ";
		std::getline(std::cin, this->info[counter]);
		if (!white(this->info[counter]))
			counter ++;
		else 
			std::cout << "This line is empty, try again" << std::endl;
	} 
	return;
}

void	Contact::search(void)
{
	if (this -> info[0].length() < 10)
		std::cout << std::setw(10) << info[0] << "|";
	else 
		std::cout << info[0].substr(0,9) << "." << "|";
	if (this -> info[1].length() < 10)
		std::cout << std::setw(10) << info[1] << "|";
	else 
		std::cout << info[1].substr(0,9) << "." <<"|";
	if (this -> info[2].length() < 10)
		std::cout << std::setw(10) << info[2] << "|";
	else 
		std::cout << info[2].substr(0,9) << "." <<"|";
}

void	Contact::full_print(void)
{
	std::cout << "First Name: " << this->info[0] << std::endl;
	std::cout << "Last Name: " << this->info[1] << std::endl;
	std::cout << "Nickname: " << this->info[2] << std::endl;
	std::cout << "Phone Number: " << this->info[3] << std::endl;
	std::cout << "Darkest Secret: " << this->info[4] << std::endl << std::endl;
}