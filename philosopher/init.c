/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:27:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 06:58:23 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//init mutex + fork id et associe un philo a ses fourchette
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

//donne un id a chaque philo et ses p_times
t_rules	init_philo(t_rules rules, int input)
{
	int counter = 1;
	while (counter < input)
	{
		rules.phi[counter].id = counter;
		rules.phi[counter].p_time_to_sleep = rules.time_to_sleep;
		rules.phi[counter].p_time_to_die = rules.time_to_die;
		rules.phi[counter].p_time_to_eat = rules.time_to_eat;
		rules.phi[counter].p_must_eat = rules.must_eat;
		counter ++;
	}
	return (rules);
}	



