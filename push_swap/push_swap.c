/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:39:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/06 16:52:34 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head2;
	int		counter;

	counter = 1;
	head = NULL;
	head2 = NULL;
	while (counter < argc)
	{
		newnode(&head, ft_atoi(argv[counter]));
		counter ++;
	}
	return (0);
}

void	newnode(t_node **head, int value)
{
	t_node	*newnode;
	t_node	*lastnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = value;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		lastnode = *head;
		while (lastnode -> next != NULL)
				lastnode = lastnode -> next;
		lastnode -> next = newnode;
	}
}

void	printer(t_node **head, t_node **head2)
{
	t_node	*search;
	t_node	*search2;

	search = *head;
	search2 = *head2;
	ft_printf("\n--------list a-------\n");
	while (search != NULL)
	{
		ft_printf("%d\n", search->data);
		search = search ->next;
	}
	ft_printf("--------list b-------\n");
	while (search2 != NULL)
	{
		ft_printf("%d\n", search2->data);
		search2 = search2 ->next;
	}
	ft_printf("\n##############\n\n");
}

int	ft_lstsize(t_node **head)
{
	int		counter;
	t_node	*search;

	counter = 1;
	search = *head;
	if (*head == NULL)
		return (0);
	while (search -> next != NULL)
	{
		search = search -> next;
		counter ++;
	}
	return (counter);
}
