/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:10:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/13 18:32:49 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"
//#include "header/get_next_line.h"

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

int		put_map(t_data *lol)
{
	//mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, pos_x, pos_y);
	
	return(0);
}

int	main(void)
{
	t_data lol;
	char	*buff;
	char	*old;
	char	*oneDTab = NULL;
	int		counter;
	int		line_size;
	char	**tab;
	int		verif;

	
	lol.img_width = 5;
	lol.img_height = 500;
	counter = 0;
	int second_counter = 0;
	line_size = 0;
	
	int pouet = open("map",O_RDONLY);

	ft_printf("pouet = %d\n", pouet);

	if (pouet == -1)
	{
		ft_printf("Pas de map a ce nom");
		exit(0);
	}
	
	buff = get_next_line(pouet);

	while (buff)
	{
		old = strdup(buff);
		buff = get_next_line(pouet);
		oneDTab = ft_strjoin(oneDTab, old);
	}
	if (!oneDTab)
	{
		ft_printf("Pas de map dans le fichier");
		exit(0);
	}

	tab = ft_split(oneDTab, '\n');
	
	
	verif = ft_strlen(tab[0]);
	ft_printf ("\nnb caractere =%d\n",verif);


	while (tab[counter])
	{
		if (ft_strlen(tab[counter++]) != verif)
		{
			ft_printf("lignes pas a la meme taille");
			exit(0);
		}
	}

	lol.mlx = mlx_init();
	//ft_printf("mlx = %d\n",lol.mlx);
	lol.mlx_win = mlx_new_window(lol.mlx, 1920, 1080, "Hello world!");
	lol.relative_path = "./yellow.xpm";/////// ICI MEC !!!!!!!!!!!!!!!!!!!!!!!!
	lol.relative_path2 = "sprite/exit.xpm";
	lol.img = mlx_xpm_file_to_image(lol.mlx, lol.relative_path, &lol.img_width, &lol.img_height);
	lol.img2 = mlx_xpm_file_to_image(lol.mlx, lol.relative_path2, &lol.img_width, &lol.img_height);
	counter = 0;
	second_counter = 0;

	while(tab[counter])
	{
		while (tab[counter][second_counter])
		{
			if(tab[counter][second_counter] == '1')
				mlx_put_image_to_window(lol.mlx, lol.mlx_win, lol.img, (second_counter * 32), (counter * 32));
			if(tab[counter][second_counter] == '0')
				mlx_put_image_to_window(lol.mlx, lol.mlx_win, lol.img2, (second_counter * 32), (counter * 32));
			second_counter ++;
		}
		second_counter = 0;
		counter ++;
	}

	//mlx_hook(lol.mlx_win, 2, 1L << 0, moove, &lol);
	mlx_loop(lol.mlx);
}