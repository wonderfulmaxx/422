/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:25 by mwinter-          #+#    #+#             */
/*   Updated: 2022/03/24 15:17:31 by mwinter-         ###   ########.fr       */
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
//	if (ft_lstsize(head) < 2)
//		return ;
//	else if (ft_lstsize == 2)
//	{
//		*head = search
//	}
//	else
//	{
//		while (counter < ft_lstsize(head) - 3)
//		{
//			printf ("counter = %d , value = %d\n", counter, search->data);
//			search = search ->next;
//			counter ++;
//		}
		printf("head->value = %d, head->next->value = %d , head->next->next->value =%d\n",(*head)->data, (*head)->next->data, (*head)->next->next->data);
		node_temp  = (*head) -> next; //-> next;
		search -> next = search -> next -> next;
		//////////////
//		search -> next -> next = *head; ca marche mais ca boucle
		//////////////
		(*node_temp) . next  = *head ;
		*head = node_temp;
		
		printf("head->value = %d, head->next->value = %d , head->next->next->value =%d",(*head)->data, (*head)->next->data, (*head)->next->next->data);
//	}
}

void	pa(t_node **head)
{
	int		counter;
	t_node	*search;

	counter = 0;
	search = *head;
	while (counter < ft_lstsize(head))
	{
		printf ("counter = %d , value = %d\n", counter, search->data);
		search = search ->next;
		counter ++;
	}
}