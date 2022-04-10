/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:09:37 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/27 15:48:20 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		counter;
	int		curs;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	result = (char *)malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!result)
		return (NULL);
	counter = 0;
	curs = 0;
	while (s1[counter])
		result[curs++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		result[curs++] = s2[counter++];
	result[curs] = '\0';
	return (result);
}
