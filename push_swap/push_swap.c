/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:39:13 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/10 12:54:19 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*head2;
	int		*int_input;

	head = NULL;
	head2 = NULL;
	
	int_input = easy_number(argc, argv);
	parsing (argc, int_input, &head, &head2);
	free(int_input);
	a_is_sorted(&head);
	//if(ft_lstsize(&head) <= 5)
//		sort_small_stack();
//	else
//		sort_big_stack();
	
	printer(&head, &head2);
	return (0);
}

///////////////////////////////////////////////

int	*easy_number(int argc, char **argv)
{
	int		*sorted;
	int		counter;
	int		argv_counter;
	int		*new_argv_int;

	counter = 0;
	sorted = malloc(sizeof(int) * argc-1);
	new_argv_int = malloc(sizeof(int) * argc-1);
	while (counter < argc -1)     //new_arg = argv
	{
		new_argv_int[counter] = ft_atoi(argv[counter + 1]);
		counter ++;
	}
	counter = 0;
	while (counter < argc -1) // sorted = (new_argv et argv)
	{
		sorted[counter] = new_argv_int[counter];
		counter ++;
	}
	ft_sort_int_tab(sorted, argc-1);  // sorted est trier
	counter = 0;
	argv_counter = 0;
	while (counter < argc -1)
	{
		while (sorted[counter] != new_argv_int[argv_counter])
			argv_counter ++;
		new_argv_int[argv_counter] = counter;
		argv_counter = 0;
		counter ++;
	}
	free(sorted);
	return (new_argv_int);
}


void	a_is_sorted(t_node **head)
{
	t_node	*search;
	int		is_sorted;
	int		checker;

	is_sorted = 1;
	if (*head)
	{
		checker	= (*head) ->data; 
		search = *head;
		while (search != NULL)
		{
			if (checker > search -> data)
				is_sorted = 0;
			checker = search -> data;
			search = search ->next;
		}
	}
	if (is_sorted)
		exit(0);
}

void	parsing(int argc, int *argv, t_node **head, t_node **head2)
{
	int		counter;

	counter = 0;

	while (counter < argc-1)
	{
		newnode(head, (argv[counter]));
		counter ++;
	}
}

/////////////////////////////////////////////////////////
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
