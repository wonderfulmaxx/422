/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:20:24 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/18 14:38:15 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Zombie
{
	public:
	Zombie();
	~Zombie();
	void	annonce(void);
	void	setname(std::string name);

	private:
	std::string	name;
};

Zombie* zombieHorde( int N, std::string name );