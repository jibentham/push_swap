/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:42:04 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/30 14:54:50 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node *create_node(char *element)
{
	struct  s_node *new_node = (struct s_node*)malloc(sizeof(struct s_node));
	if (new_node == NULL)
		return (free(new_node), NULL);
	new_node->element = atoi(element);
	new_node->next = NULL;
	return (new_node);
}

void end_insert(struct s_node **head_ref, char *element)
{
	struct s_node *new_node = create_node(element);
	if (*head_ref == NULL)
		*head_ref = new_node;
	else 
	{
		struct s_node *temp = *head_ref;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

// void head_insert(struct s_node **head_ref, char *element)
// {
// 	struct s_node *new_node = create_node(element);
// 	new_node->next = *head_ref;
// 	*head_ref = new_node;
// }

void print_list(struct s_node *head)
{
	struct s_node *temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->element);
		temp = temp->next;
	}
}

int	is_numeric(char *element)
{
	int i;

	i = 0;
	while (element[i] != '\0')
	{
		if (!(element[i] >= 48 && element[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int no_duplicates(struct s_node *head)
{
	int count;
	struct s_node *temp1;
	struct s_node *temp2;
		
	count = 0;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp2 = head;
		while (temp2 != NULL && temp2 != temp1)
		{
			if (temp1->element == temp2->element)
				count++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (count >= 1)
		return (0);
	return (1);
}
