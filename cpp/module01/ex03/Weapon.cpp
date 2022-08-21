/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:00:33 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/21 13:58:44 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	Weapon::setType(type);
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string	const& Weapon::getType()
{
	return(this->type);
}

void	Weapon::setType(std::string	_type)
{
	this->type = _type;
	return;
}
