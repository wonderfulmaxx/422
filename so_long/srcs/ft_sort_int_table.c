/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:05:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/09 20:27:49 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	pivot;
	int	i;
	int	j;

	if (size < 2)
		return ;
	pivot = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (tab[j] < pivot)
			ft_swap(&tab[i++], &tab[j]);
	if (tab[i] > tab[size])
		ft_swap(&tab[i], &tab[size]);
	ft_sort_int_tab(tab, i);
	ft_sort_int_tab(tab + i + 1, size - i);
}
