/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:25:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/02/04 12:34:14 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(struct s_node **src_ref, struct s_node **dest_ref)
{
	struct s_node	*new_node;

	if (*src_ref == NULL)
		return ;
	new_node = *src_ref;
	*src_ref = (*src_ref)->next;
	new_node->next = *dest_ref;
	*dest_ref = new_node;
}

void	swap_node(struct s_node **head)
{
	struct s_node	*first;
	struct s_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	rotate_list(struct s_node **head)
{
	struct s_node	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	tail = tail->next;
	*head = tail->next;
	tail->next = NULL;
}

void	reverse_rotate_list(struct s_node **head)
{
	struct s_node	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
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
