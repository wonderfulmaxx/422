/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:39:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/04 16:33:21 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head2;
	int		value;
	int		counter;

	counter = 1;
	value = 666;
	head = NULL;
	head2 = NULL;
	while (counter < argc)
	{
		newnode(&head, atoi(argv[counter])); // atoi
		counter ++;
	}
	printer(&head);
	pb(&head, &head2);
	pb(&head, &head2);
	pb(&head, &head2);
	printf("---------------pb pb pb-------------------\n");
	printer(&head);
	ft_printf("\n\n");
	printer(&head2);
	rrr(&head, &head2);
	printf("------------------rrr----------------\n");
	//pa(&head,&head2);
	//rra(&head);
	printer(&head);
	printf("\n\n");
	printer(&head2);
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

void	printer(t_node **head)
{
	t_node	*search;

	search = *head;
	while (search != NULL)
	{
		printf("%d\n", search->data);
		search = search ->next;
	}
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
