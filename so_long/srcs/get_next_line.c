/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:24 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/11 16:59:07 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*get_next_line(int fd)
{
	static int	res;
	static char	buff[1 + 1];
	char		*str;

	str = NULL;
	if (res == 0)
	{
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	if (res > 0 && buff[0] != '\0')
		str = ft_read(fd, buff, str, res);
	else
		return (NULL);
	return (str);
}

char	*ft_read( int fd, char *buff, char *str, int res)
{
	while (res > 0 && ft2u_strchr(str, '\n'))
	{
		str = ft2u_strjoin(str, buff);
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	return (str);
}
