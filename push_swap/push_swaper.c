/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/06 16:51:07 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sa(t_node **head, int natif)
{
	int		counter;
	t_node	*search;
	t_node	*node_temp;

	if (natif)
		ft_printf("sa\n");
	if (!*head)
		return ;
	if ((*head)->next)
	{
		counter = 0;
		search = *head;
		node_temp = (*head)-> next;
		if ((*head)->next->next)
			search -> next = search -> next -> next;
		else
			search -> next = NULL;
		(*node_temp).next = *head ;
		*head = node_temp;
	}
}

void	sb(t_node **head, int natif)
{
	int		counter;
	t_node	*search;
	t_node	*node_temp;

	if (natif)
		ft_printf("sb\n");
	if (!*head)
		return ;
	if ((*head)->next)
	{
		counter = 0;
		search = *head;
		node_temp = (*head)-> next;
		if ((*head)->next->next)
			search -> next = search -> next -> next;
		else
			search -> next = NULL;
		(*node_temp).next = *head ;
		*head = node_temp;
	}
}

void	ss(t_node **head, t_node **head2)
{
	sa(head, 0);
	sb(head2, 0);
	ft_printf("ss\n");
}

void	pa(t_node **head, t_node **head2)
{
	t_node	*temp;

	if (*head2)
	{
		temp = (*head2)-> next;
		newnode(head, (*head2)-> data);
		free(*head2);
		*head2 = temp;
		rra(head, 0);
	}
	ft_printf("pa\n");
}

void	pb(t_node **head, t_node **head2)
{
	t_node	*temp;

	if (*head)
	{
		temp = (*head)-> next;
		newnode(head2, (*head)-> data);
		free(*head);
		*head = temp;
		rrb(head2, 0);
	}
	ft_printf("pb\n");
}