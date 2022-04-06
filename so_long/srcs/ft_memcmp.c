/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:03:50 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/28 15:20:30 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (((unsigned char *)src1)[i] == ((unsigned char *)src2)[i]
		&& i < size - 1)
		i++;
	return (((unsigned char *)src1)[i] - ((unsigned char *)src2)[i]);
}
