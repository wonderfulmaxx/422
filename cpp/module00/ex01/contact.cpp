/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:27:03 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/16 12:38:38 by mwinter-         ###   ########.fr       */
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
	std::cout << "First Name: ";
	std::cin >> this->first_name;
	std::cout << "Last Name: ";
	std::cin >> this->last_name;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Phone Number: ";
	std::cin >> this->phone_number;
	std::cout << "Darkest Secret: ";
	std::cin >> this->darkest_secret;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	Contact::search(void)
{
	if (this -> first_name.length() < 10)
		std::cout << std::setw(10) << first_name << "|";
	else 
		std::cout << first_name.substr(0,9) << "." << "|";
	if (this -> last_name.length() < 10)
		std::cout << std::setw(10) << last_name << "|";
	else 
		std::cout << last_name.substr(0,9) << "." <<"|";
	if (this -> nickname.length() < 10)
		std::cout << std::setw(10) << nickname << "|";
	else 
		std::cout << nickname.substr(0,9) << "." <<"|";
}

void	Contact::full_print(void)
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl << std::endl;
}