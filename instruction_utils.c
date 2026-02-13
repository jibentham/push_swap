/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:59:37 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/13 15:22:50 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_node **head_a, t_node **head_b)
{
	rotate_list(head_a);
	rotate_list(head_b);
}

void	reverse_rotate_both(t_node **head_a, t_node **head_b)
{
	reverse_rotate_list(head_a);
	reverse_rotate_list(head_b);
}

t_node	*find_cheapest(t_node *head_ref)
{
	t_node	*cheapest;
	t_node	*parser;

	if (head_ref == NULL)
		return (NULL);
	cheapest = head_ref;
	parser = head_ref;
	while (parser != NULL)
	{
		if (parser->total_cost < cheapest->total_cost)
			cheapest = parser;
		parser = parser->next;
	}
	return (cheapest);
}

int	stack_size(t_node *head_ref)
{
	int		size;
	t_node	*parser;

	size = 0;
	parser = head_ref;
	while (parser != NULL)
	{
		size++;
		parser = parser->next;
	}
	return (size);
}

t_node	*find_last_node(t_node *head_ref)
{
	t_node	*parser;

	parser = head_ref;
	while (parser != NULL)
		parser = parser->next;
	return (parser);
}
