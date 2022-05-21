/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 17:31:22 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*life_is_hard(void *data)
{
	t_philosophe *barbu;
	barbu = (t_philosophe *) data;
	
	barbu->last_eat_ptr = timestamp();

	while (barbu->p_must_eat != 0)
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
		usleep (60);
		if (barbu->p_must_eat > 0)
			barbu->p_must_eat --;
	}
	return (NULL);
}

int	main(int argc, char ** argv)
{
	if (argc != 6 && argc != 5)
	{
		printf ("error");
		return (0);
	} 
	int input;
	int counter = 1;
	int kasseur_floter = 1;
	t_rules		rules;
	
	rules.time_to_sleep = atoi(argv[4]);
	input = atoi(argv[1]) + 1;
	rules.time_to_die = atoi(argv[2]);
	rules.time_to_eat = atoi(argv[3]);

	if (argc == 6)
		rules.must_eat = atoi(argv[5]);
	else 
		rules.must_eat = -1;
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
	launcher(&rules, input, &kasseur_floter);
	

	while(kasseur_floter)
	{
		counter = 1;
		while (counter < input)
		{
			//sleep (1);
			//printf("Barbu %d lasteat = %ld\n",counter,rules.phi[counter].last_eat_ptr);
			if (timestamp() - rules.phi[counter].last_eat_ptr  > rules.time_to_die )
				{
					printf("Macron Exploooooosion\n");
					breaker(fourchettes, input);
				}
			printf("%d- tddr = %lld, time_to_die = %d\n",rules.phi[counter].id,  timestamp() - rules.phi[counter].last_eat_ptr, rules.time_to_die);
			counter ++;
		}
		//printf("\n----------------------------\n\n");
	}

	printf("Les philosophes se sont biens ralass\n");
	return (0);
}

