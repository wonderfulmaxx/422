/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:04:21 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/19 17:10:21 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <mlx.h>
# include "../header/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		p_x;
	int		p_y;
	char	**tab;

}	t_data;

#endif