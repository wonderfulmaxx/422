/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:14:16 by tbrissia          #+#    #+#             */
/*   Updated: 2022/02/26 16:27:37 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search)
{
	int	curs;

	curs = ft_strlen(str);
	while (curs >= 0)
	{
		if (str[curs] == search)
			return ((char *)str + curs);
		else
			curs--;
	}
	return (0);
}
