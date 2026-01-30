/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/30 15:07:29 by jibentham        ###   ########.fr       */
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

struct s_node *find_largest_element(struct s_node *head_ref)
{
	struct s_node *temp;

	if (head_ref == NULL)
		return (NULL);
	temp = head_ref;
	while (head_ref != NULL)
	{
		if (head_ref->element > temp->element)
			temp = head_ref;
		head_ref = head_ref->next;
	}
	return (temp);
}

struct s_node *find_target(struct s_node *head_a, struct s_node *head_b)
{
	
}