/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:03:11 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/06 16:51:38 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "../lib42/libft.h"

typedef struct node
{
	struct node		*next;
	int				data;
}	t_node;

void	newnode(t_node **head, int value);
void	printer(t_node **head, t_node **head2);
void	sa(t_node **head, int natif);
int		ft_lstsize(t_node **head);
void	pa(t_node **head, t_node **head2);
void	ra(t_node **head);
void	rra(t_node **head, int natif);
void	ss(t_node **head, t_node **head2);
void	pb(t_node **head, t_node **head2);
void	rb(t_node **head);
void	rrb(t_node **head, int natif);
void	rrr(t_node **head, t_node **head2);
void	sb(t_node **head, int natif);

#endif
