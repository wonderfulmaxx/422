/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:47:54 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/22 14:47:20 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	is_equal(std::string s1, std::string s2)
{
	if(s1 == s2)
		return(1);
	return(0);
}

int	main(int argc, char *argv[])
{
	Harl	_Harl;
	if (argc != 2)
	{
		std::cout << "Bad number of args" << std::endl;
		return (0);
	}

	if (!(is_equal(argv[1],"DEBUG") || is_equal(argv[1],"INFO") || is_equal(argv[1], "WARNING") || is_equal(argv[1], "ERROR")))
	{
		std::cout << "Please, enter \"DEBUG\",\"INFO\",\"WARNING\" or \"ERROR\"" << std::endl;
		return (0);
	}
	
	_Harl.complain(argv[1]);

	return (0);
}