/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:32:40 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/13 15:16:13 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_largest_element(t_node *head_ref)
{
	struct s_node	*temp;

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

t_node	*find_target(t_node *node, t_node *head_b)
{
	t_node	*current;
	t_node	*closest_node;
	int		closest_element;

	closest_node = NULL;
	closest_element = INT_MIN;
	current = head_b;
	while (current != NULL)
	{
		if (current->element < node->element
			&& current->element > closest_element)
		{
			closest_element = current->element;
			closest_node = current;
		}
		current = current->next;
	}
	if (closest_node != NULL)
		return (closest_node);
	return (find_largest_element(head_b));
}

void	add_target(t_node *head_a, t_node *head_b)
{
	t_node	*parser;

	parser = head_a;
	while (parser != NULL)
	{
		parser->target = find_target(parser, head_b);
		parser = parser->next;
	}
}

int	get_absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
