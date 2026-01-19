/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:42:04 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/19 14:24:01 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	char *element;
	struct node *next;
};

struct node *create_node(char *element)
{
	struct  node *new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL)
		return (NULL);
	new_node->element = element;
	new_node->next = NULL;
	return (new_node);
}

void end_insert(struct node **head_ref, char *element)
{
	struct node *new_node = create_node(element);
	if (*head_ref == NULL)
		*head_ref = new_node;
	else 
	{
		struct node *temp = *head_ref;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void print_list(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%s\n", temp->element);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main (int argc, char **argv)
{
	struct node *head;
	int i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		end_insert(&head, argv[i]);
		i++;
	}
	print_list(head);
	return (0);
}