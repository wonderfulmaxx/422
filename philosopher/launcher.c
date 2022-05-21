/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:03:35 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 21:00:48 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//lance les threads dans le bon ordre puis attend leur fin
void	launcher(t_rules *rules, int input)
{
	int	counter;
	int	wait;

	counter = 1;
	wait = 0;
	if (input % 2 == 0)
	{
		wait = 1;
	}
	while (counter < input)
	{
		if (wait == 1)
		{
			counter ++;
			wait = 2;
		}
		rules->phi[counter].last_eat_ptr = timestamp();
		pthread_create(&rules->phi[counter].life, NULL , life_is_hard, &rules->phi[counter]);
		counter ++;
	}
	usleep(120);
	if (wait == 2)
	{
		rules->phi[1].last_eat_ptr = timestamp();
		pthread_create(&rules->phi[1].life, NULL , life_is_hard, &rules->phi[1]);
	}
}

void	death_checker(t_rules *r, pthread_mutex_t *fourchettes)
{
	int	c;
	int	a_manger;

	a_manger = 0;
	while (42)
	{
		c = 1;
		while (c < r->input)
		{
			if (timestamp() - r->phi[c].last_eat_ptr > (r->time_to_die + 66))
			{
				printf("%lld %d died\n", timestamp(), r->phi[c].id);
				breaker(fourchettes, r->input);
			}
			if (r->phi[c].p_must_eat == 0)
				a_manger ++;
			if (a_manger == r->input)
			{
				usleep(30);
				printf("Les philosophes se sont biens ralass\n");
				breaker(fourchettes, r->input);
			}
			c ++;
		}
	}
}
