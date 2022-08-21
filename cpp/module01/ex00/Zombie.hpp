/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:29:59 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/18 13:29:03 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Zombie
{
	public:
	void	announce( void );
	Zombie(std::string name);
	~Zombie();

	private:
	std::string	name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );