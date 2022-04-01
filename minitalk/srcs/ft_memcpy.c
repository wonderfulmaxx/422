/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:46:57 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/26 17:47:42 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	void	*destinations;

	if (!dest && !src)
		return (NULL);
	destinations = dest;
	while (count--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (destinations);
}
