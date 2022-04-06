/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:08 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/22 16:34:07 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *tab, int value, size_t count)
{
	unsigned int	i;
	unsigned char	*tab_work;

	tab_work = (unsigned char *)tab;
	i = 0;
	while (i < count)
		tab_work[i++] = (unsigned char)value;
	tab = (void *)tab_work;
	return (tab);
}
