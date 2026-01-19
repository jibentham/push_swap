/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linkedlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:42:04 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/19 14:07:40 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int number;
	struct node *next;
};

struct node *create_node(int number)
{
	struct  node *new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void end_insert(struct node **head_ref, int number)
{
	struct node *new_node = create_node(number);
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

int main (int argc, char **argv)
{
	return (0);
}