/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:08:43 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/01 09:46:36 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *dest, const char *src)
{
	int	curs;

	curs = 0;
	while (src[curs])
	{
		dest[curs] = src[curs];
		curs++;
	}
	dest[curs] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(src)) + 1);
	if (!copy)
		return (NULL);
	copy = ft_copy(copy, src);
	return (copy);
}
