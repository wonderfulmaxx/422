/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:03:11 by mwinter-          #+#    #+#             */
/*   Updated: 2022/03/28 16:10:11 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "headersupreme.h"

typedef struct node
{
	struct node		*next;
	int				data;
}	t_node;

void	newnode(t_node **head, int value);
void	printer(t_node **head);
void	sa(t_node **head);
int		ft_lstsize(t_node **head);
void	pa(t_node **head, t_node **head2);
void	ra(t_node **head);
void	rra(t_node **head);

#endif
