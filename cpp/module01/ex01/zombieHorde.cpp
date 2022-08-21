/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:20:15 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/18 15:02:53 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int counter = 0;
	Zombie	*ptr_to_horde;
	
	ptr_to_horde = new Zombie[N];
	for(counter = 0; counter < N; counter ++)
	{
		ptr_to_horde[counter].setname(name);
		ptr_to_horde[counter].annonce();
	}
	return (ptr_to_horde);
}