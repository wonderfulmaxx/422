/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:08:40 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/28 12:23:24 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	compt_int(int n)
{
	int		compt;

	compt = 0;
	while (n > 9)
	{
		n = n / 10;
		compt++;
	}
	return (compt);
}

static	void	ft_save_my_life(int	*n, int	*compt_bool)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			*n += 1;
			compt_bool[1] = 1;
		}
		*n *= -1;
		compt_bool[0] = compt_bool[0] + 1;
		compt_bool[2] = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		compt_bool[3];
	int		duo;

	compt_bool[0] = 1;
	compt_bool[1] = 0;
	compt_bool[2] = 0;
	ft_save_my_life(&n, compt_bool);
	duo = n;
	compt_bool[0] += compt_int(duo);
	nbr = (char *)malloc(sizeof(char) * (compt_bool[0] + 1));
	if (! nbr)
		return (NULL);
	nbr[compt_bool[0]] = '\0';
	compt_bool[0]--;
	while (compt_bool[0] >= 0)
	{
		nbr[compt_bool[0]--] = (n % 10) + 48;
		n = n / 10;
	}
	if (compt_bool[1] == 1)
		nbr[10] = '8';
	if (compt_bool[2] == 1)
		nbr[0] = '-';
	return (nbr);
}
