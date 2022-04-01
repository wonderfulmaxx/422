/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/01 18:31:21 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "srcs/libft.h"

char g_converter[9];

void	printer(void)
{
	int	counter;
	int	char_value;

	counter = 0;
	char_value = 0;
	while (counter < 8)
	{
		char_value += (g_converter[counter] - '0') * ft_power (2, counter);
		counter ++;
	}
	write(1, &char_value, 1);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	counter;

	if (counter == 8)
		counter = 0;
	if (sig == 30)
		g_converter[counter] = '0';
	else
		g_converter[counter] = '1';
	counter ++;
	if (counter == 8)
	{
		g_converter[counter] = '\0';
		printer();
	}
}

// int	main(void)
// {
// 	struct sigaction	s_action;

// 	s_action.sa_sigaction = handler;
// 	ft_printf("Salut, PID => %d\n", getpid());
// 	while (1)
// 	{
// 		sigaction(SIGUSR1, &s_action, NULL);
// 		sigaction(SIGUSR2, &s_action, NULL);
// 		pause();
// 	}
// 	return (0);
// }

int	main(void)
{
	char				*pid;
	struct sigaction	sa_server;

	sa_server.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	pid = ft_itoa(getpid());
	write (1, pid, ft_strlen(pid));
	write (1, "\n", 1);
	free(pid);
	while (1)
		pause();
	return (1);
}
