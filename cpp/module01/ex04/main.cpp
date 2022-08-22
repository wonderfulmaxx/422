/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:16:14 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/22 11:59:13 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	is_empty(std::string s)
{
	if(s.empty())
		return (1);
	return (0);
}

std::string	ft_replace(std::string s, std::string target, std::string	replace)
{
	int start;

	start = s.find(target);
	if (start != -1)
	{
		s.erase(start, (target.size()));
		s.insert(start,replace);
	}
	return (s);
}

int	main(int argc, char *argv[])
{
	std::string	file_name;
	std::string	file_replace;
	std::string buff;

	if (argc != 4 || is_empty(argv[1]) || is_empty(argv[2]) || is_empty(argv[3]))
	{
		std::cout	<< "Invalid parameters" << std::endl;
		return (0);
	}

	file_name = argv[1];
	file_replace = file_name + ".replace";
	

	std::ifstream	ifs(file_name.c_str());
	std::ofstream  monFlux(file_replace.c_str());
	
	if (!ifs || !monFlux)
	{		
		std::cout	<< "Impossible douvrir le fichier" << std::endl;
		return (0);
	}
	while(getline(ifs,buff))
	{
		buff = ft_replace(buff,argv[2],argv[3]);
		monFlux << buff;
		monFlux << "\n";
	}
}