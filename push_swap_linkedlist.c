/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:42:04 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/20 18:27:41 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	char *element;
	struct node *next;
};

struct node *create_node(char *element)
{
	struct  node *new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL)
		return (free(new_node), NULL);
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

void head_insert(struct node **head_ref, char *element)
{
	struct node *new_node = create_node(element);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print_list(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%s\n", temp->element);
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

int no_duplicates(struct node **head)
{
	int count;
	struct node *temp1;
	struct node *temp2;
		
	count = 0;
	temp1 = *head;
	while (temp1 != NULL)
	{
		temp2 = *head;
		while (temp2 != NULL && temp2 != temp1)
		{
			if (strcmp(temp1->element, temp2->element) == 0)
				count++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (count >= 1)
		return (0);
	return (1);
}

int main (int argc, char **argv)
{
	struct node *head_a;
	struct node *head_b;
	int i;

	head_a = NULL;
	head_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_numeric(argv[i]))
			end_insert(&head_a, argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	if (no_duplicates(&head_a) == 0)
	{
		printf("Error\n");
		return (1);
	}
	print_list(head_a);
	
	return (0);
}

