/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:29 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/01 18:31:17 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "srcs/libft.h"

void	char_sender(int pid_server, char letter)
{
	int	binaire_counter;
	int	binaire;

	binaire = 0;
	binaire_counter = 0;
	while (binaire_counter < 8)
	{
		binaire = letter % 2;
		letter /= 2;
		binaire_counter ++;
		if (binaire == 1)
			kill(pid_server, SIGUSR2);
		else if (binaire == 0)
			kill(pid_server, SIGUSR1);
		usleep(120);
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	counter;

	counter = 0;
	pid_server = ft_atoi(argv[1]);
	while (argv[2][counter])
		char_sender(pid_server, argv[2][counter++]);
	char_sender(pid_server, '\n');
	return (0);
}
