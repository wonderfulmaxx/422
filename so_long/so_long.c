/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:10:10 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/10 16:36:42 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	theosucemonbeat(int keycode, t_vars *vars)
{
	ft_printf("keycode = %d\n",keycode);
//	if (keycode == 53)
//		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, theosucemonbeat, &vars);
	mlx_loop(vars.mlx);
}