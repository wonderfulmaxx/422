/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:26:15 by mwinter-          #+#    #+#             */
/*   Updated: 2022/08/02 11:28:59 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;

	if (argc == 1)
	{
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	}
	else 
	{
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout << char (toupper(argv[j][i]));
				i ++;
			}
			j++;
		}
	}
}