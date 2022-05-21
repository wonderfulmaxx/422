/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 01:04:31 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*life_is_hard(void *data)
{
	t_philosophe *barbu;
	barbu = (t_philosophe *) data;

	while (1)
	{
		printf ("%d-J'ai besoin de la fourchette %d et %d\n",barbu -> id, barbu -> left_fork ,barbu -> right_fork);
		pthread_mutex_lock ( barbu->left_mutex);
		pthread_mutex_lock (barbu ->right_mutex);
		printf("%d-Cool elles sont dispos!\n",barbu -> id);
		smart_sleep(barbu->p_time_to_eat);
		printf("%d- trop manger.. go dodo\n",barbu -> id);
		pthread_mutex_unlock( barbu -> left_mutex);
		pthread_mutex_unlock ( barbu -> right_mutex);
		smart_sleep(barbu->p_time_to_sleep);
		usleep (200);
	}
	return (NULL);
}

int	main(int argc, char ** argv)
{
	if (argc != 6)
	{
		printf ("error");
		return (0);
	} 
	int input;
	int counter = 1;
	t_rules		rules;
	
	rules.time_to_sleep = atoi(argv[4]);
	input = atoi(argv[1]) + 1;
	rules.time_to_die = atoi(argv[2]);
	rules.time_to_eat = atoi(argv[3]);
	rules.must_eat = atoi(argv[5]);
	printf("%d\n",input);

	pthread_mutex_t	fourchettes[250];

	rules = init_philo(rules, input);
	rules = init_forks(rules, fourchettes, input);
	launcher(rules, input);
	counter = 1;

	while (1)
	{
		printf("lol");
	}

	return (0);
}

