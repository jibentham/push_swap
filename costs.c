/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/30 20:19:44 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void to_top_cost(struct s_node *head_ref)
{
	int size;
	int i;
	struct s_node *tail;
	struct s_node *parser;

	size = 0;
	i = 0;
	tail = head_ref;
	parser = head_ref;
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

void to_target_cost(struct s_node *head_a, struct s_node *head_b)
{
	to_top_cost(head_b);
	while (head_a != NULL)
	{
		if (head_a->target != NULL)
			head_a->to_target_cost = head_a->target->to_top_cost;
		head_a = head_a->next;
	}
}

void total_cost(struct s_node *head_ref)
{
	while (head_ref != NULL)
	{
		head_ref->total_cost = head_ref->to_top_cost + head_ref->to_target_cost;
		head_ref = head_ref->next;
	}
}