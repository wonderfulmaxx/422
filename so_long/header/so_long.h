/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:04:21 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/10 16:35:21 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include <mlx.h>
//#include <unistd.h>
#include "../srcs/libft.h"

typedef struct s_data {

void	*img;
char	*addr;
int		bits_per_pixel;
int		line_lenght;
int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif