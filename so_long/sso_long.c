/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sso_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:25:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/10 16:16:56 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int 	f(int keycode, t_data *img)
{

int pos_x = 5;
int	pos_y = 5;

while (pos_y < 100)
	{
		while (pos_x++ < 100)
		{
			my_mlx_pixel_put(img->img, 200 + pos_x, 200 + pos_y, 0x0FF666F0);
			//usleep(120);
		}
		pos_x = 5;
		pos_y ++;
	}
	return (0);
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char *title = "Hello World!";
	int		size_x = 1920;
	int		size_y = 1080;
	int pos_x = 5;
	int	pos_y=5;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, size_x, size_y, title);

	img.img = mlx_new_image(mlx, size_x, size_y);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	
	while (pos_y < 100)
	{
		while (pos_x++ < 100)
		{
			my_mlx_pixel_put(&img, pos_x, pos_y, 0x00FF6FF0);
			//usleep(120);
		}
		pos_x = 5;
		pos_y ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	mlx_hook(mlx_win, 2, 1L << 0, f, &img);

	mlx_loop(mlx);
	
	// int     mlx_clear_window(void *mlx_ptr, void *win_ptr);


//	int     mlx_destroy_window(void *mlx_ptr, void *win_ptr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	
}