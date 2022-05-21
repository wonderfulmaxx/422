/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:25:34 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 00:56:57 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define CHATTE 10000

struct	t_rules;		// ca fait kwa si jenleve ca?

typedef struct s_philo
{
	int etat; // 0 = penser ; 1 = dormir ; 2 = manger ; 3 = mort
	pthread_t	life;
	int	id;
	int	left_fork;
	int right_fork;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;

	int p_time_to_sleep;
	int p_time_to_die;
	int p_time_to_eat;
	int p_must_eat;

	//pthread_t	fatboy;
	//struct timeval end;
	//struct timeval *start_ptr;
	//struct timeval *end_ptr;
} t_philosophe;

typedef struct s_rules
{
	t_philosophe phi[250];
	int time_to_sleep;
	int time_to_die;
	int time_to_eat;
	int must_eat;
} t_rules;


void	*life_is_hard(void *data);
t_rules	init_forks(t_rules rules, pthread_mutex_t *fourchettes, int input);
t_rules	init_philo(t_rules rules, int input);
void	launcher(t_rules rules, int input);
void    smart_sleep(int time);