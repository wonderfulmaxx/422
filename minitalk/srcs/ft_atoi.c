/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:34:35 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/01 09:42:08 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		nbr;
	int		negative;
	char	*str2;

	nbr = 0;
	negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' && negative++ == 0)
		str++;
	else if (*str == '+')
		str++;
	str2 = (char *)str;
	while (*str2 >= '0' && *str2 <= '9')
		str2++;
	if ((str2 - str) > 10 && negative == 0)
		return (-1);
	else if ((str2 - str) > 10 && negative == 1)
		return (0);
	while ((*str >= '0' && *str <= '9'))
		nbr = nbr * 10 + *str++ - 48;
	if (negative != 0)
		nbr -= (nbr * 2);
	return (nbr);
}
