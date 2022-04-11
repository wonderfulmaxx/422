/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:41:55 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/11 16:59:57 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>
# include <string.h>


char	*ft2u_strjoin(char *s1, char *s2);
size_t	ft2_strlen(const char *s);
int		ft2u_strchr(char *str, int c);
char	*ft_read( int fd, char *buff, char *str, int res);
char	*get_next_line(int fd);

#endif