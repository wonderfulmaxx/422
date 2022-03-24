/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:03:11 by mwinter-          #+#    #+#             */
/*   Updated: 2022/03/23 18:57:32 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	struct node		*next;
	int				data;
}	t_node;

void	newnode(t_node **head, int value);
void	printer(t_node **head);
void	sa(t_node **head);
int		ft_lstsize(t_node **head);
void	pa(t_node **head);

#endif
