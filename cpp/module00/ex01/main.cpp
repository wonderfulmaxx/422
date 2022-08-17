/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:27:01 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/17 15:05:06 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int PhoneBook::nb_contacts = 0;

int white(std::string input)
{
	int counter = 0;

	while (input[counter])
	{
		if (!isblank(input[counter++]))
		return (0);
	}
	return(1);
}

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
			pagesJaunes.tab_contact[pagesJaunes.get_n_contact()%9 - 1].add();
		}
		else if (msg == "SEARCH")
		{
			if (pagesJaunes.get_n_contact() == 0)
				std::cout << "FILL THE PHONEBOOK FIRST" << std::endl;
			else
			{
				counter = 0;
				std::cout<< std::endl << "     INDEX|FIRST-NAME| LAST-NAME| NICKNAME" << std::endl;
				std::cout << "--------------------------------------------";
				while (counter < pagesJaunes.get_n_contact() && counter < 8)
				{
					std::cout << std::endl;
					std::cout << std::setw(10) << counter + 1<< "|";
					pagesJaunes.tab_contact[counter].search();
					counter ++;
				}
				std::cout << std::endl;
				pagesJaunes.tab_contact[pagesJaunes.input_number()].full_print();
			}
		}
		else if (msg == "EXIT")
			exist = 0;
		else 
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter a valid syntax" << std::endl;
		}
	}
	return 0;
}