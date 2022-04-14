/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:10:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/14 16:12:29 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"


void	print_error(char * msg)
{
	ft_printf("Error : %s",msg);
	exit(0);
}

void	put_sprite(t_data *lol, char letter, int counter , int second_counter)
{
	if (letter == 'E')
		lol->relative_path = "sprite/exit.xpm";
	else if (letter == 'W')
		lol ->relative_path = "sprite/wall.xpm";
	else if (letter == 'F')
		lol->relative_path = "sprite/floor3.xpm";
	else if (letter == 'P')
		lol ->relative_path = "sprite/player_r.xpm";
	else if (letter == 'C')
		lol ->relative_path = "sprite/collect.xpm";
	else
		print_error("Caractere indefinis");
	lol->img = mlx_xpm_file_to_image(lol->mlx, lol->relative_path, &lol->img_width, &lol->img_height);
	mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, (second_counter * 32), (counter * 32));
	mlx_destroy_image(lol->mlx, lol->img);
}

void	map_reader(char **tab, t_data *lol)
{
	int	counter;
	int	second_counter;

	counter = 0;
	while(tab[counter])
	{
		second_counter = 0;
		while (tab[counter][second_counter])
		{
			put_sprite(lol,tab[counter][second_counter],counter,second_counter);
		second_counter ++;
		}
		counter ++;
	}
}

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

char *one_line_parsing(int fd, int *nb_line)
{
	char *buff;
	char *old;
	char *oneDTab;

	buff = NULL;
	old= NULL;  //3x inutile?
	oneDTab=NULL;
	
	buff = get_next_line(fd);

	while (buff)
	{
		old = strdup(buff);
		buff = get_next_line(fd);
		oneDTab = ft_strjoin(oneDTab, old);
		*nb_line  = *nb_line + 1;
	}
	if (!oneDTab)
		print_error("Pas de map dans le fichier");

	return(oneDTab);

}

int	main(void)
{
	t_data	lol;
	int		counter;
	int		line_size;
	char	**tab;
	int nb_line = 0;
	int fd;

	counter = 0;

	
	fd = open("map",O_RDONLY);
	if (fd == -1)
		print_error("Pas de map a ce nom");

	tab = ft_split(one_line_parsing(fd, &nb_line), '\n'); 
	
	line_size = ft_strlen(tab[0]);

////////////////////////////////////////////////////////error verif
	while (tab[counter])
	{
		//ft_printf("line_size = %d",ft_strlen(tab[counter]));
		if (ft_strlen(tab[counter++]) != ((size_t)line_size))
			print_error("lignes pas a la meme taille");
	}
////////////////////////////////////////////////////
;
	lol.mlx = mlx_init();

	//ft_printf("line_size = %d, nb_line = %d ",line_size,nb_line);
	lol.mlx_win = mlx_new_window(lol.mlx, (line_size * 32 +1), (nb_line * 32+1), "Pacman_42");


	counter = 0;
	
map_reader(tab, &lol);
/////////////////////////////////

	//mlx_hook(lol.mlx_win, 2, 1L << 0, moove, &lol);
	mlx_loop(lol.mlx);
}