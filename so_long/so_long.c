/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:10:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/19 17:42:40 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	print_error(char *msg)
{
	ft_printf("Error : %s", msg);
	exit(0);
}

void	put_sprite(t_data *lol, char letter, int i, int second_i)
{
	if (letter == 'E')
		lol->relative_path = "sprite/exit.xpm";
	else if (letter == 'W')
		lol->relative_path = "sprite/wall.xpm";
	else if (letter == 'F')
		lol->relative_path = "sprite/floor3.xpm";
	else if (letter == 'P')
	{
		lol->relative_path = "sprite/player_r.xpm";
		lol->p_x = second_i;
		lol->p_y = i;
		lol->tab[i][second_i] = 'F';
	}
	else if (letter == 'C')
	{
		lol->relative_path = "sprite/collect.xpm";
	}
	else
		print_error("Caractere indefinis");
	lol->img = mlx_xpm_file_to_image(lol->mlx, lol->relative_path,
			&lol->img_width, &lol->img_height);
	mlx_put_image_to_window(lol->mlx, lol->mlx_win, lol->img, (second_i * 32),
		(i * 32));
	mlx_destroy_image(lol->mlx, lol->img);
}

void	map_reader(t_data *lol)
{
	int	i;
	int	second_i;

	i = 0;
	while (lol->tab[i])
	{
		second_i = 0;
		while (lol->tab[i][second_i])
		{
			put_sprite(lol, lol->tab[i][second_i], i, second_i);
			second_i++;
		}
		i++;
	}
}

int	moove_allower(t_data *lol, int keycode)
{
	if (keycode == 2 && (lol->tab[lol->p_y][lol->p_x + 1] == 'F'
		|| lol->tab[lol->p_y][lol->p_x + 1] == 'C'))
		return (1);
	else if (keycode == 13 && (lol->tab[lol->p_y - 1][lol->p_x] == 'F'
		|| lol->tab[lol->p_y - 1][lol->p_x] == 'C'))
		return (1);
	else if (keycode == 0 && (lol->tab[lol->p_y][lol->p_x - 1] == 'F'
		|| lol->tab[lol->p_y][lol->p_x - 1] == 'C'))
		return (1);
	else if (keycode == 1 && (lol->tab[lol->p_y + 1][lol->p_x] == 'F'
		|| lol->tab[lol->p_y + 1][lol->p_x] == 'C'))
		return (1);
	else if (keycode == 2 && (lol->tab[lol->p_y][lol->p_x + 1] == 'E'))
		return (2);
	else if (keycode == 13 && (lol->tab[lol->p_y - 1][lol->p_x] == 'E'))
		return (2);
	else if (keycode == 0 && (lol->tab[lol->p_y][lol->p_x - 1] == 'E'))
		return (2);
	else if (keycode == 1 && (lol->tab[lol->p_y + 1][lol->p_x] == 'E'))
		return (2);
	return (0);
}

int	end_checker(char **tab)
{
	int	i;
	int	second_i;

	i = 0;
	while (tab[i])
	{
		second_i = 0;
		while (tab[i][second_i])
		{
			if (tab[i][second_i] == 'C')
				return (0);
			second_i++;
		}
		i++;
	}
	return (1);
}

void	succes(t_data *lol)
{
	int	i;

	mlx_destroy_window(lol->mlx, lol->mlx_win);
	i = 0;
	while (lol->tab[i])
	{
		free(lol->tab[i]);
		i++;
	}
	free(lol->tab);
	ft_printf("GG trop fort le mec enft");
	exit(0);
}

int	moove(int keycode, t_data *lol)
{
	if (keycode == 2 && moove_allower(lol, keycode) == 1)
	{
		put_sprite(lol, 'F', lol->p_y, lol->p_x);
		put_sprite(lol, 'P', lol->p_y, ++lol->p_x);
	}
	else if (keycode == 13 && moove_allower(lol, keycode) == 1)
	{
		put_sprite(lol, 'F', lol->p_y, lol->p_x);
		put_sprite(lol, 'P', --lol->p_y, lol->p_x);
	}
	else if (keycode == 0 && moove_allower(lol, keycode) == 1)
	{
		put_sprite(lol, 'F', lol->p_y, lol->p_x);
		put_sprite(lol, 'P', lol->p_y, --lol->p_x);
	}
	else if (keycode == 1 && moove_allower(lol, keycode) == 1)
	{
		put_sprite(lol, 'F', lol->p_y, lol->p_x);
		put_sprite(lol, 'P', ++lol->p_y, lol->p_x);
	}
	else if (moove_allower(lol, keycode) == 2 && end_checker(lol->tab))
		succes(lol);
	return (0);
}

char	*one_line_parsing(int fd, int *nb_line)
{
	char	*buff;
	char	*old;
	char	*one_d_tab;

	buff = NULL;
	old = NULL;
	one_d_tab = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		old = strdup(buff);
		buff = get_next_line(fd);
		one_d_tab = ft_strjoin(one_d_tab, old);
		*nb_line = *nb_line + 1;
	}
	if (!one_d_tab)
		print_error("Pas de map dans le fichier");
	return (one_d_tab);
}

int	main(void)
{
	t_data	lol;
	int		i;
	int		line_size;
	int		nb_line;
	int		fd;

	nb_line = 0;
	i = 0;
	fd = open("map", O_RDONLY);
	if (fd == -1)
		print_error("Pas de map a ce nom");
	lol.tab = ft_split(one_line_parsing(fd, &nb_line), '\n');
	line_size = ft_strlen(lol.tab[0]);
	while (lol.tab[i])
		if (ft_strlen(lol.tab[i++]) != ((size_t)line_size))
			print_error("lignes pas a la meme taille");
	lol.mlx = mlx_init();
	lol.mlx_win = mlx_new_window(lol.mlx, (line_size * 32 + 1), (nb_line * 32
				+ 1), "Pacman_42");
	i = 0;
	map_reader(&lol);
	mlx_hook(lol.mlx_win, 2, 1L << 0, moove, &lol);
	mlx_loop(lol.mlx);
	return (0);
}
