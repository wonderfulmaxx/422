/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/03/24 15:42:41 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	int		counter;
	t_node	*search;
	t_node	*node_temp;

	counter = 0;
	search = *head;

		printf("head->value = %d, head->next->value = %d , head->next->next->value =%d\n",(*head)->data, (*head)->next->data, (*head)->next->next->data);
		node_temp  = (*head) -> next; 
		search -> next = search -> next -> next;
		(*node_temp) . next  = *head ;
		*head = node_temp;
		
		printf("head->value = %d, head->next->value = %d , head->next->next->value =%d",(*head)->data, (*head)->next->data, (*head)->next->next->data);

}

void	pa(t_node **head, t_node **head2)
{
	t_node *temp;

	temp = (*head) -> next;
	newnode(head2, (*head) -> data);
	free(*head);
	*head = temp;
}

void	ra(t_node **head)
{
	t_node *temp;

	temp = (*head) -> next;
	newnode (head,(*head) -> data);
	free(*head);
	*head = temp;
}

void	rra(t_node **head)
{
	t_node	*temp;
	t_node	*search;

	temp = (*head) -> next;
	while(temp -> next -> next != NULL)
	{
		temp = temp -> next;
	}
}