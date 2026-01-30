/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:32:40 by jibentham         #+#    #+#             */
/*   Updated: 2026/01/30 20:38:25 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	struct s_node *current;
	struct s_node *closest_node;
	int closest_element;

	closest_node = NULL;
	closest_element = INT_MIN;
	current = head_b;
	while (current != NULL)
	{
		if (current->element < head_a->element 
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

void add_target(struct s_node *head_a, struct s_node *head_b)
{
	struct s_node *parser;

	parser = head_a;
	while (parser != NULL)
	{
		parser->target = find_target(head_a, head_b);
		parser = parser->next;
	}
}

int get_absolute(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int get_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}