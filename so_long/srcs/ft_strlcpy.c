/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:11:15 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/28 17:58:15 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	curs;

	curs = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (curs < size - 1 && src[curs])
	{
		dst[curs] = src[curs];
		curs++;
	}
	dst[curs] = '\0';
	return (ft_strlen(src));
}
