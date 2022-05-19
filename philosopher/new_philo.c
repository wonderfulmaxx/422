/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:57:28 by mwinter-          #+#    #+#             */
/*   Updated: 2022/05/19 11:24:21 by mwinter-         ###   ########.fr       */
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
	//struct t_rules		*rules;
	int	left_fork;
	int right_fork;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;

	pthread_t	fatboy;
	struct timeval end;
	
	struct timeval *start_ptr;
	struct timeval *end_ptr;
} t_philosophe;

typedef struct s_rules
{
	t_philosophe phi[250];
} t_rules;


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
		gettimeofday (barbu->start_ptr, NULL);				//FO METR UN POINTER
		 //barbu->starto = barbu -> start.tv_sec;
	}
	return (NULL);
}

void	*last_meal(void *data)
{
	t_philosophe *barbu;
	barbu = (t_philosophe *)data;
	while (1)
	{
		sleep(2);
		gettimeofday(&barbu->end, NULL);
		printf("tddr philo[%d] = %ld\n", barbu->id, barbu->end.tv_sec - barbu->start_ptr->tv_sec);
		if(barbu->end.tv_sec - barbu->start_ptr->tv_sec > CHATTE)
	 		printf("BOOOOOOOOOOOM\nBOOOOOOOOOOOM\nBOOOOOOOOOOOM\nBOOOOOOOOOOOM\nBOOOOOOOOOOOM\n");
	}
	sleep(2);
	
//	printf("end philo[%d] = %d\n", barbu->id, barbu->end.tv_sec); //- barbu->start.tv_sec);
//	printf("start philo[%d] = %d\n", barbu->id, barbu->start.tv_sec );
	//printf("tddr philo[%d] = %ld\n", barbu->id, barbu->end.tv_sec - barbu->start.tv_sec);
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
	int attend_connard = 0;


	struct timeval start[250];
	//struct timeval end[250];
	
//	struct timeval start;

	input = atoi(argv[1]) + 1;
	printf("%d\n",input);
	
	pthread_mutex_t	fourchettes[250];

	//gettimeofday (&start, NULL);



	while (counter < input)
	{
		rules.phi[counter].id = counter;
		pthread_mutex_init(&fourchettes[counter], NULL);
		rules.phi[counter].start_ptr=&start[counter];
		gettimeofday(rules.phi[counter].start_ptr, NULL);		//activer apres initialisation
		//printf("----------------------%d",rules.phi[counter].start.tv_sec);
		pthread_create(&rules.phi[counter].fatboy, NULL, last_meal, &rules.phi[counter]);
		counter ++;
	}
	pthread_mutex_init(&fourchettes[counter], NULL);

	counter = 1;


	while (counter < input)
	{
		pthread_mutex_init( &fourchettes[counter] , NULL);
		if (counter != 1)
		{
			rules.phi[counter].left_fork = counter - 1;
			rules.phi[counter].left_mutex = &fourchettes[counter - 1];
		}
		else
		{
			rules.phi[counter].left_fork = input-1;
			rules.phi[counter].left_mutex = &fourchettes[input - 1];
		}
		rules.phi[counter].right_fork =counter;
		rules.phi[counter].right_mutex = &fourchettes[counter];
		counter ++;
	}
	/////////
	counter = 1;

	if (input % 2 == 0)
	{
		attend_connard = 1;
	}

	while (counter < input)
	{
		if (attend_connard == 1)
		{
			counter ++;
			attend_connard =2;
		}
		pthread_create(&rules.phi[counter].life, NULL , life_is_hard, &rules.phi[counter]); 
		//sleep (1);
		counter ++;
	}
	sleep(1);
	if (attend_connard == 2)
		pthread_create(&rules.phi[1].life, NULL , life_is_hard, &rules.phi[1]);
	
	counter = 1;
	while (counter < input)
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