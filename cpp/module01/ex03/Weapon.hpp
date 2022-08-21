/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:08:23 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/21 13:13:29 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define	WEAPON

#include <iostream>

class	Weapon
{
public:
	Weapon(std::string	type);
	~Weapon();
	std::string	const&	getType();
	void				setType(std::string	_type);

private:
	std::string	type;
};

#endif