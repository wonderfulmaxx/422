/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:26:09 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/28 16:38:17 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	cut;
	size_t			i;

	i = ft_strlen(dest);
	counter = 0;
	cut = 0;
	if (size == 0)
		return (ft_strlen(src) + size);
	while (dest[counter])
		counter++;
	while (counter < size - 1 && src[cut])
		dest[counter++] = src[cut++];
	dest[counter] = '\0';
	if (size > i)
		return (i + (ft_strlen(src)));
	else
		return (ft_strlen(src) + size);
}
