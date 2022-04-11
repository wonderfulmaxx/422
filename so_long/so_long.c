/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:10:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/11 16:32:48 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"
#include "header/get_next_line.h"

int		moove(int keycode,t_data *lol)
{
	static int pos_x;							//satic!!!!!!!!!!!!!!!!!!!!!!
	static int pos_y;							//satic!!!!!!!!!!!!!!!!!!!!!!

	// if (pos_x == 0)
	// 	pos_x = 20;
	// if (pos_y == 0)
	// 	pos_y = 20;
	//mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, 500, 500);
	//ft_printf("mlx = %d\n",lol->mlx);
	ft_printf("%d",keycode);

	if (keycode == 2)
	{
		mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, pos_x, pos_y);
		pos_x += 10;
	}
	else if (keycode == 1)
	{
		mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, pos_x, pos_y);
		pos_y += 10;
	}
	return (0);
}

int	main(void)
{
	t_data lol;
	void	*buff;


	buff = malloc((3*sizeof(char)));
	lol.relative_path = "./test.xpm";
	lol.img_width = 5;
	lol.img_height = 5;

	get_next_line(open("map",O_RDONLY));
	

	ft_printf("---%s---",buff);

	lol.mlx = mlx_init();
	ft_printf("mlx = %d\n",lol.mlx);
	lol.mlx_win = mlx_new_window(lol.mlx, 1920, 1080, "Hello world!");
	lol.img = mlx_xpm_file_to_image(lol.mlx, lol.relative_path, &lol.img_width, &lol.img_height);
	//mlx_put_image_to_window(lol.mlx, lol.mlx_win, lol.img, 0, 0);
	mlx_hook(lol.mlx_win, 2, 1L << 0, moove, &lol);
	mlx_loop(lol.mlx);
}