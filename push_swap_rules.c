/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:25:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/22 17:45:08 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_node(struct node **src_ref, struct node **dest_ref)
{
	struct node *new_node;
	
	if (*src_ref == NULL)
		return;
	new_node = *src_ref;
	*src_ref = (*src_ref)->next;
	new_node->next = *dest_ref;
	*dest_ref = new_node;
}

void swap_node(struct node **head)
{
	struct node *first;
	struct node *second;

	if (*head == NULL || (*head)->next == NULL)
		return;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void rotate_list(struct node **head)
{
	struct node *tail;

	if (*head == NULL || (*head)->next == NULL)
		return;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	tail = tail->next;
	*head = tail->next;
	tail->next = NULL;
}

void reverse_rotate_list(struct node **head)
{
	struct node *tail;

	if (*head == NULL || (*head)->next == NULL)
		return;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = tail;
	tail = tail->next;
	while (tail->next != *head)
		tail = tail->next;
	tail->next = NULL;
}