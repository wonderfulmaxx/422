/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:07:45 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/30 15:42:58 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuns_fd(unsigned int n, int fd, int *count)
{
	if (n > 9)
	{
		ft_putuns_fd((n / 10), fd, count);
		ft_putchar_fd(((n % 10) + '0'), fd);
		*count += 1;
	}
	else
	{
		ft_putchar_fd((n + '0'), fd);
		*count += 1;
	}
}
