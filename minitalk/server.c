/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/02 16:15:20 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char g_converter[9];

void	printer(int pid)
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
	if (char_value == 10)
	{
		usleep(120);
		kill (pid, SIGUSR1);
	}
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	counter;

	context = NULL;
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
		printer(siginfo->si_pid);
	}
}

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
	return (0);
}
