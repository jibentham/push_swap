/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/27 04:50:53 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_max(struct node **head_a, struct node **head_b)
{
	push_node(head_a, head_b);
	push_node(head_a, head_b);
	if ((*head_b)->element < (*head_b)->next->element)
		swap_node(head_b);
}

void sort_three(struct node **head_ref)
{
	if ((*head_ref)->element < (*head_ref)->next->element && (*head_ref)->element > (*head_ref)->next->next->element)
		swap_node(head_ref);
	if ((*head_ref)->element < (*head_ref)->next->element && (*head_ref)->element < (*head_ref)->next->next->element)
		rotate_list(head_ref);
}

void to_top_cost(struct node **head_ref)
{
	int size;
	int i;
	struct node *tail;
	struct node *parser;

	size = 0;
	i = 0;
	tail = *head_ref;
	parser = *head_ref;
	while (tail != NULL)
	{
		tail = tail->next;
		size++;
	}
	while (parser != NULL)
	{
		if (i <= size / 2)
			parser->to_top_cost = i;
		else
			parser->to_top_cost = i - size;
		parser = parser->next;
		i++;
	}
}
