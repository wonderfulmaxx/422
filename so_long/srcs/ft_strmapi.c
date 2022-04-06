/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:25:20 by tbrissia          #+#    #+#             */
/*   Updated: 2022/03/01 11:13:09 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_new;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str_new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str_new)
		return (NULL);
	while (s[i])
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
