/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:21:28 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/28 20:43:00 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char	*s, int fd)
{
	int		count;

	count = 0;
	if (!s)
		ft_putchar_fd('\n', fd);
	else
		while (s[count])
			ft_putchar_fd(s[count++], fd);
}
