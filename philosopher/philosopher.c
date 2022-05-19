/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/19 12:13:42 by mwinter-         ###   ########.fr       */
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
		sleep(2);
		printf("%d-ma bien ralass\n",barbu -> id);
		sleep(1);
		pthread_mutex_unlock( barbu -> left_mutex);
		pthread_mutex_unlock ( barbu -> right_mutex);
		sleep (2);
	}
	return (NULL);
}

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		printf ("error");
		return (0);
	} 
	int input;
	int counter = 1;
	t_rules		rules;
	
	rules.time_to_sleep = atoi(argv[4]);
	input = atoi(argv[1]) + 1;
	printf("%d\n",input);

	pthread_mutex_t	fourchettes[250];

	rules = init_philo(rules, input);
	rules = init_forks(rules, fourchettes, input);
	launcher(rules, input);
	counter = 1;


	return (0);
}

