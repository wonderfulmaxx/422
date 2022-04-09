/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:50:30 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/06 16:52:35 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ra(t_node **head)
{
	t_node	*temp;

	temp = (*head)-> next;
	newnode (head, (*head)-> data);
	free(*head);
	*head = temp;
	ft_printf("ra\n");
}

void	rb(t_node **head)
{
	t_node	*temp;

	temp = (*head)-> next;
	newnode (head, (*head)-> data);
	free(*head);
	*head = temp;
	ft_printf("rb\n");
}

void	rra(t_node **head, int natif)
{
	t_node	*temp;
	t_node	*search;

	if (!head)
	{
		if (natif)
			ft_printf("rra\n");
		return ;
	}
	else if ((*head)-> next-> next == NULL)
		sa(head, 0);
	else if ((*head)->next->next)
	{
		temp = (*head);
		search = temp;
		while (search -> next -> next != NULL)
			search = search -> next;
		*head = search -> next;
		search -> next -> next = temp;
		search -> next = NULL;
	}
	if (natif)
		ft_printf("rra\n");
}

void	rrb(t_node **head, int natif)
{
	t_node	*temp;
	t_node	*search;

	if (!*head || (*head)-> next == NULL)
	{
		if (natif)
			ft_printf("rrb\n");
		return ;
	}
	if ((*head)-> next-> next == NULL)
		sb(head, 0);
	else if ((*head)->next->next)
	{
		temp = (*head);
		search = temp;
		while (search -> next -> next != NULL)
			search = search -> next;
		*head = search -> next;
		search -> next -> next = temp;
		search -> next = NULL;
	}
	if (natif)
		ft_printf("rrb\n");
}

void	rrr(t_node **head, t_node **head2)
{
	rra(head, 0);
	rrb(head2, 0);
	ft_printf("rrr\n");
}
