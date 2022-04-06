/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:25:07 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/30 15:40:26 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bin_hex(unsigned long int add, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (add >= 16)
	{
		ft_bin_hex(add / 16, count);
		ft_bin_hex(add % 16, count);
	}
	else
	{
		ft_putchar_fd(base[add], 1);
		*count += 1;
	}
}
