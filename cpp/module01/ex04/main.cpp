/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:16:14 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/21 16:25:30 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string	file_name;
	std::string	file_replace;
	std::string	s1;
	std::string	buff;
	std::string	s2;

	std::string mot;
	//std::string iss;

	//input
	std::cout << "Enter the source file : " ;
	std::cin >> file_name;
	file_replace = file_name + ".replace";
	std::cout << "You whant to replace :" ;
	std::cin >> s1;
	std::cout << "By :";
	std::cin >> s2;

	//lecture
	std::ifstream	ifs(file_name.c_str());


	while (getline(ifs, buff))
	{
		std::istringstream iss(buff);
		while(iss >> mot)
		{
			std::cout << iss << std::endl;
		}
	}
	
	//ecriture
	std::ofstream  monFlux(file_replace.c_str());
	if (monFlux)
	{
		monFlux << buff << std::endl;
	}
	else
	{
		std::cout	<< "Impossible douvrir le fichier" << std::endl;
	}
}