/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:26:53 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/01 17:27:00 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	if (power < 0)
		return (0);
	i = 0;
	res = 1;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
