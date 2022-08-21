/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:09:04 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/21 13:58:34 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_Weapon = NULL;
	return;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack()
{
	if (this->_Weapon != NULL)
		std::cout << this->_name << " attacks with their " << _Weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack !"  << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_Weapon = &Weapon;
	return;
}