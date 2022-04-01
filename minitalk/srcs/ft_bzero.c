/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:18:37 by tbrissia          #+#    #+#             */
/*   Updated: 2022/01/18 17:19:19 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *tab, size_t count)
{
	unsigned char	*tab_work;

	tab_work = (unsigned char *)tab;
	while (count > 0)
	{
		*tab_work++ = '\0';
		count--;
	}
}
