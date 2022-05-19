/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:27:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/19 12:01:59 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_rules	init_forks(t_rules rules, pthread_mutex_t *fourchettes, int input)
{
	int counter = 1;
	pthread_mutex_init(&fourchettes[counter], NULL);
	while (counter < input)
	{
		pthread_mutex_init( &fourchettes[counter] , NULL);
		if (counter != 1)
		{
			rules.phi[counter].left_fork = counter - 1;
			rules.phi[counter].left_mutex = &fourchettes[counter - 1];
		}
		else
		{
			rules.phi[counter].left_fork = input-1;
			rules.phi[counter].left_mutex = &fourchettes[input - 1];
		}
		rules.phi[counter].right_fork =counter;
		rules.phi[counter].right_mutex = &fourchettes[counter];
		counter ++;
	}
	return (rules);
}

t_rules	init_philo(t_rules rules, int input)
{
	int counter = 1;
	while (counter < input)
	{
		rules.phi[counter].id = counter;
		counter ++;
	}
	return (rules);
}	



