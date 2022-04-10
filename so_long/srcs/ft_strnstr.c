/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:49 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/27 14:12:21 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	counter;
	int		inspector;

	inspector = 0;
	counter = 0;
	if (!(to_find[inspector]))
		return ((char *)str);
	while (counter < size)
	{
		inspector = 0;
		while ((str[counter + inspector])
			&& (to_find[inspector])
			&& (str[counter + inspector] == to_find[inspector])
			&& (counter + inspector) < size)
		{
			inspector++;
			if (!(to_find[inspector]))
				return ((char *)&str[counter]);
		}
		counter++;
	}
	return (NULL);
}
