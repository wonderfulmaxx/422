/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:03:35 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/19 12:05:16 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	launcher(t_rules rules, int input)
{
	int counter = 1;
	int attend_connard = 0;
	
	if (input % 2 == 0)
	{
		attend_connard = 1;
	}

	while (counter < input)
	{
		if (attend_connard == 1)
		{
			counter ++;
			attend_connard =2;
		}
		pthread_create(&rules.phi[counter].life, NULL , life_is_hard, &rules.phi[counter]); 
		counter ++;
	}
	usleep(120);
	if (attend_connard == 2)
		pthread_create(&rules.phi[1].life, NULL , life_is_hard, &rules.phi[1]);
	
	counter = 1;
	while (counter < input)
	{
		pthread_join(rules.phi[counter].life, NULL);
		counter ++;
	}
}