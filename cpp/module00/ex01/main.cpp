/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:27:01 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/16 12:58:55 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int PhoneBook::nb_contacts = 0;

int	main()
{
	std::string msg;
	PhoneBook pagesJaunes;
	int exist = 42;
	int counter;

	while (exist)
	{
		std::cout << "ADD // SEARCH // EXIT : " << std::endl; 
		std::cin >> msg;


		if (msg == "ADD")
		{
			pagesJaunes.add_contact();
			pagesJaunes.tab_contact[pagesJaunes.get_n_contact()%8].add();
		}
		else if (msg == "SEARCH")
		{
			if (!pagesJaunes.get_n_contact())
				std::cout << "FILL THE PHONEBOOK FIRST" << std::endl;
			else
			{
				counter = 0;
				std::cout<< std::endl << " INDEX|FIRST-NAME| LAST-NAME| NICKNAME" << std::endl;
				std::cout << "-----------------------------------------";
				while (counter++ < pagesJaunes.get_n_contact() && counter < 9)
				{
					std::cout << std::endl;
					std::cout << std::setw(6) << counter << "|";
					pagesJaunes.tab_contact[counter%8].search();
				}
				std::cout << std::endl;
				pagesJaunes.tab_contact[pagesJaunes.input_number()].full_print();
			}
		}
		else if (msg == "EXIT")
			exist = 0;
		else 
			std::cout << "Please enter a valid syntax" << std::endl;
	}
	return 0;
}