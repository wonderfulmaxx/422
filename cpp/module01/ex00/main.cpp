/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:04:53 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/18 13:37:16 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *ptr;
	Zombie Zombie("Richard");
	randomChump("Lucien");

	ptr = newZombie("Yvette");
	delete ptr;
	return (0);
}