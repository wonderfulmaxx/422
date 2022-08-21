/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:09:09 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/21 13:22:03 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA
{	
	public:
	HumanA(std::string	name, Weapon &Weapon);
	~HumanA();
	void	attack(void);

	private:
	std::string		_name;
	Weapon			&_Weapon;
};

#endif