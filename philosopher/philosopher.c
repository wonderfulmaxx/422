/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/18 13:58:59 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_PHILO 6

struct	t_rules;		// ca fait kwa si jenleve ca?

typedef struct s_philo
{
	int etat; // 0 = penser ; 1 = dormir ; 2 = manger ; 3 = mort
	pthread_t	life;
	int	id;
	struct t_rules		*rules;
} t_philosophe;

typedef struct s_rules
{
	t_philosophe phi[NB_PHILO];
	pthread_mutex_t fourchette[NB_PHILO];
} t_rules;


void	*life_is_hard(void *data)
{
	t_philosophe *barbu;
	barbu = (t_philosophe *) data;

	//static int test;
	//printf ("test = %d\n",test);
	printf ("Bonjour , je suis philosophe %d\n", barbu->id);
	//sleep(3);
	//printf ("%d-J'ai besoin de la fourchette %d et %d\n",barbu -> id, barbu -> id ,barbu -> id + 1);
	// pthread_mutex_lock ( & barbu->fourchette[0]);
	// printf("%d-Cool elles sont dispos!\n brugmugnum\n",barbu -> id);
	// sleep(2);
	// printf("%dJ'ai manger mon caca jme sens pas bien\n",barbu -> id);
	// pthread_mutex_unlock( & barbu -> fourchette[0]);
	return (NULL);
}

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		printf ("error");
		return (0);
	} 
	int counter = 0;
	t_rules		rules;
	//t_philosophe barbu;

	while (counter < NB_PHILO)
	{
		rules.phi[counter].id = counter;
		counter ++;
	}
	counter = 0;
	while (counter < NB_PHILO)
	{
		pthread_mutex_init( &rules.fourchette[counter] , NULL);
		counter ++;
	}
	counter = 0;
	while (counter < NB_PHILO)
	{
		pthread_create(&rules.phi[counter].life, NULL , life_is_hard, &rules.phi[counter]);
		sleep (1);
		counter ++;
	}
	counter = 0;
	while (counter < NB_PHILO)
	{
		pthread_join(rules.phi[counter].life, NULL);
		counter ++;
	}

	return (0);
}

/* le plan:
chaque philosophe a son id et son etat, il faut donc une struct philo
la struct doit etre un tableau



les philo sont une boucle while
{
	si tddr > alors etat = mort
	si fourchette dispo alors manger et tddr = 0
}
une autre boucle while verifie les philo etat (elle se situe pas dans le thread)
si mort -> exit
*/