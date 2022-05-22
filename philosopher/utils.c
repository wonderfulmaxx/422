/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:25:34 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/22 15:04:56 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	smart_sleep(int time)
{
	usleep(time * 1000);
}

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	breaker(pthread_mutex_t *fourchettes, int input)
{
	int	counter;

	counter = 1;
	while (counter < input)
		pthread_mutex_destroy(&fourchettes[counter++]);
	exit(0);
}

void	error_msg(char *msg)
{
	printf("%s", msg);
	exit (0);
}
