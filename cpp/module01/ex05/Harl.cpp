/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:49:30 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/22 15:32:34 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

	Harl::Harl()
	{
		return;
	}

	Harl::~Harl()
	{
		return;
	}

	void	Harl::complain(std::string level)
	{
		void	(Harl::*functptr[])() = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
		
		std::string	tab_s[4];
		int counter = 0;

		tab_s[0] = "DEBUG";
		tab_s[1] = "INFO";
		tab_s[2] = "WARNING";
		tab_s[3] = "ERROR";

		while (counter <= 3)
		{
			if (level == tab_s[counter])
			{
				(*this.*functptr [counter])();
			}
			counter ++;
		}
		return;
	}

	void	Harl::debug()
	{
		std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
		return;
	}

	void	Harl::info()
	{
		std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
		return;
	}

	void	Harl::warning()
	{
		std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
		return;
	}

	void	Harl::error()
	{
		std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
		return;
	}