/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:01:54 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/21 21:06:01 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int etat;
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

	long long last_eat_ptr;

}	t_philosophe;

typedef struct s_rules
{
	t_philosophe	phi[250];
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				must_eat;
	int				input;
}	t_rules;

void			*life_is_hard(void *data);
t_rules			init_forks(t_rules rules, pthread_mutex_t *fourchettes, int input);
t_rules			init_philo(t_rules rules, int input);
void			launcher(t_rules *rules, int input);
void    		smart_sleep(int time);
long long		timestamp(void);
void    		breaker(pthread_mutex_t *fourchettes, int input);
t_rules			init_input(char **argv, t_rules rules);
void			death_checker(t_rules *rules, pthread_mutex_t *fourchettes);

#endif