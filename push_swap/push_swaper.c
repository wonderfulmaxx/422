/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/04 16:32:51 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sa(t_node **head)
{
	int		counter;
	t_node	*search;
	t_node	*node_temp;

	counter = 0;
	search = *head;
	node_temp = (*head)-> next;
	search -> next = search -> next -> next;
	(*node_temp).next = *head ;
	*head = node_temp;
}

void	sb(t_node **head)
{
	int		counter;
	t_node	*search;
	t_node	*node_temp;

	counter = 0;
	search = *head;
	node_temp = (*head)-> next;
	search -> next = search -> next -> next;
	(*node_temp).next = *head ;
	*head = node_temp;
}

void	ss(t_node **head, t_node **head2)
{
	sa(head);
	sb(head2);
}

void	pa(t_node **head, t_node **head2)
{
	t_node	*temp;

	temp = (*head2)-> next;
	newnode(head, (*head2)-> data);
	free(*head2);
	*head2 = temp;
}

void	pb(t_node **head, t_node **head2)
{
	t_node	*temp;

	temp = (*head)-> next;
	newnode(head2, (*head)-> data);
	free(*head);
	*head = temp;
}

void	ra(t_node **head)
{
	t_node	*temp;

	temp = (*head)-> next;
	newnode (head, (*head)-> data);
	free(*head);
	*head = temp;
}

void	rb(t_node **head)
{
	t_node	*temp;

	temp = (*head)-> next;
	newnode (head, (*head)-> data);
	free(*head);
	*head = temp;
}

void	rra(t_node **head)
{
	t_node	*temp;
	t_node	*search;

	temp = (*head);
	search = temp;
	while (search -> next -> next != NULL)
		search = search -> next;
	*head = search -> next;
	search -> next -> next = temp;
	search -> next = NULL;
}

void	rrb(t_node **head)
{
	t_node	*temp;
	t_node	*search;

	temp = (*head);
	search = temp;
	while (search -> next -> next != NULL)
		search = search -> next;
	*head = search -> next;
	search -> next -> next = temp;
	search -> next = NULL;
}

void	rrr(t_node **head, t_node **head2)
{
	rra(head);
	rrb(head2);
}

