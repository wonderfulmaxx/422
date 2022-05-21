/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 07:00:45 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*life_is_hard(void *data)
{
	t_philosophe *barbu;
	barbu = (t_philosophe *) data;
	
	barbu->last_eat_ptr = timestamp();

	while (1)
	{
	//	printf ("%d-J'ai besoin de la fourchette %d et %d\n",barbu -> id, barbu -> left_fork ,barbu -> right_fork);
		pthread_mutex_lock ( barbu->left_mutex);
		pthread_mutex_lock (barbu ->right_mutex);
	//	printf("%d-Cool elles sont dispos!\n",barbu -> id);
		smart_sleep(barbu->p_time_to_eat);
		printf("%d- trop manger.. go dodo\n",barbu -> id);
		barbu->last_eat_ptr = timestamp();
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
	//printf("%d\n",input);


	pthread_mutex_t	fourchettes[250];

	rules = init_philo(rules, input);
	
	long long last_eat[250];
	while (counter < input)
	{
		rules.phi[counter].last_eat_ptr = last_eat[counter];
		counter ++;
	}
	rules = init_forks(rules, fourchettes, input);
	rules = launcher(rules, input);
	

	while(1)
	{
		counter = 1;
		while (counter < (input))
		{
			sleep (1);
			printf("Barbu %d lasteat = %ld\n",counter,rules.phi[counter].last_eat_ptr);
			counter ++;
		}
		printf("\n----------------------------\n\n");
	}

	return (0);
}

