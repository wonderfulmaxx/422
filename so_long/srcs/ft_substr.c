/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:34:18 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/01 09:53:37 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t size)
{
	char	*dst;
	size_t	i;

	if (!src)
		return (NULL);
	if ((int)start >= (int)ft_strlen(src))
	{
		dst = (char *)malloc(start - ft_strlen(src));
		if (!dst)
			return (NULL);
		return (dst);
	}
	dst = (char *)malloc(size + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
		dst[i++] = src[start++];
	dst[i] = '\0';
	return (dst);
}
