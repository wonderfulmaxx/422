/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:20:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/18 14:57:22 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::~Zombie()
{
	std::cout << this->name << " : HaaAAarGhh..." << std::endl;
	return;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

void	Zombie::annonce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}