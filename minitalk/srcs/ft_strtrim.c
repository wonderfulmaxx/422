/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:16:41 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/01 09:53:14 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_verif(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

static	char	*ft_result_malloc(int	*startop, char	*s1)
{
	char	*result;

	if (startop[0] == (int)ft_strlen(s1))
	{
		result = (char *)malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
	}
	else
	{
		result = (char *)malloc((startop[1] - startop[0]) + 1);
		if (!result)
			return (NULL);
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			curs[2];
	int			startop[2];
	char		*result;

	curs[0] = 0;
	curs[1] = 0;
	if (!s1)
		return ((char *)s1);
	while (ft_verif(s1[curs[0]], set) == 1)
		curs[0]++;
	startop[0] = curs[0];
	while (s1[curs[0]])
		curs[0]++;
	curs[0] -= 1;
	while (ft_verif(s1[curs[0]], set) == 1)
		curs[0]--;
	startop[1] = curs[0] + 1;
	result = ft_result_malloc(startop, (char *)s1);
	if (!result)
		return (NULL);
	curs[0] = startop[0];
	while (curs[0] < startop[1])
		result[curs[1]++] = s1[curs[0]++];
	result[curs[1]] = '\0';
	return (result);
}
