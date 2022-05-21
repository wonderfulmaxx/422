/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 20:55:50 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*life_is_hard(void *data)
{
	t_philosophe	*b;

	b = (t_philosophe *) data;
	b->last_eat_ptr = timestamp();
	while (b->p_must_eat != 0)
	{
		pthread_mutex_lock (b->left_mutex);
		pthread_mutex_lock (b ->right_mutex);
		printf ("%d has taken a fork\n%d has taken a fork\n%d is eating\n",
			b -> id, b -> id, b -> id);
		smart_sleep(b->p_time_to_eat);
		b->last_eat_ptr = timestamp();
		pthread_mutex_unlock (b -> left_mutex);
		pthread_mutex_unlock (b -> right_mutex);
		printf("%d is sleeping\n", b -> id);
		smart_sleep(b->p_time_to_sleep);
		usleep (600);
		if (b->p_must_eat > 0)
			b->p_must_eat --;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int				counter;
	t_rules			rules;
	pthread_mutex_t	fourchettes[250];
	long long		last_eat[250];

	counter = 1;
	if (argc != 6 && argc != 5)
	{
		printf ("Bad number of args");
		return (0);
	}
	rules = init_input(argv, rules);
	if (argc == 6)
		rules.must_eat = atoi(argv[5]);
	else
		rules.must_eat = -1;
	rules = init_philo(rules, rules.input);
	while (counter < rules.input)
	{
		rules.phi[counter].last_eat_ptr = last_eat[counter];
		counter ++;
	}
	rules = init_forks(rules, fourchettes, rules.input);
	launcher(&rules, rules.input);
	death_checker(&rules, fourchettes);
	return (0);
}
