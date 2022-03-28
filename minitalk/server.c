/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/03/28 18:18:30 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include <unistd.h>
#include <stdio.h>
#include "headersupreme.h"


void	put_zero()
{
	printf("1");
}

void	put_zer2()
{
	printf("2");
}

int	main()
{
	int lol = 0;
	printf("lol");
	printf("%d",getpid());
	lol = 1;
	while (lol)
	{
		printf("ca");
		//signal(SIGUSR1, &put_zero);
		//signal(SIGUSR2, &put_zer2);
		pause();
	}
	return (0);
}