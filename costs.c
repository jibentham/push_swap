/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/02/04 23:23:17 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top_cost(struct s_node *head_ref)
{
	int				size;
	int				i;
	struct s_node	*tail;
	struct s_node	*parser;

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

void	to_target_cost(struct s_node *head_ref)
{
	struct s_node	*parser;

	parser = head_ref;
	while (parser != NULL)
	{
		if (parser->target != NULL)
			parser->to_target_cost = parser->target->to_top_cost;
		parser = parser->next;
	}
}

void	total_cost(struct s_node *head_ref)
{
	struct s_node	*parser;

	parser = head_ref;
	while (parser != NULL)
	{
		if (parser->to_top_cost >= 0 && parser->to_target_cost >= 0)
			parser->total_cost = get_max(get_absolute(parser->to_top_cost),
					get_absolute(parser->to_target_cost));
		else if (parser->to_top_cost < 0 && parser->to_target_cost < 0)
			parser->total_cost = get_max(get_absolute(parser->to_top_cost),
					get_absolute(parser->to_target_cost));
		else
			parser->total_cost = get_absolute(parser->to_top_cost)
				+ get_absolute(parser->to_target_cost);
		parser->total_cost += 1;
		parser = parser->next;
	}
}
