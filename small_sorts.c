/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:17:59 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/13 15:29:24 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **head_ref)
{
	int	first;
	int	second;

	first = (*head_ref)->element;
	second = (*head_ref)->next->element;
	if (first > second)
		swap_node(head_ref);
	printf("sa\n");
}

void	sort_three(t_node **head_ref)
{
	int	first;
	int	second;
	int	third;

	first = (*head_ref)->element;
	second = (*head_ref)->next->element;
	third = (*head_ref)->next->next->element;
	if (first > second && second > third)
	{
		swap_node(head_ref);
		reverse_rotate_list(head_ref);
		printf("sa\n");
		printf("rra\n");
	}
	else if (first < second && second > third && first < third)
	{
		swap_node(head_ref);
		rotate_list(head_ref);
		printf("sa\n");
		printf("ra\n");
	}
	else if (first < second && second > third && first > third)
	{
		reverse_rotate_list(head_ref);
		printf("rra\n");
	}
	else if (first > second && second < third && first < third)
	{
		swap_node(head_ref);
		printf("sa\n");
	}
	else if (first > second && second < third && first > third)
	{
		rotate_list(head_ref);
		printf("ra\n");
	}
}

void	sort_four(t_node **head_a, t_node **head_b)
{
	while (*head_a != find_smallest_element(*head_a))
	{
		rotate_list(head_a);
		printf("ra\n");
	}
	push_node(head_a, head_b);
	printf("pb\n");
	sort_three(head_a);
	push_node(head_b, head_a);
	printf("pa\n");
}

void	sort_five(t_node **head_a, t_node **head_b)
{
	while (*head_a != find_smallest_element(*head_a))
	{
		rotate_list(head_a);
		printf("ra\n");
	}
	push_node(head_a, head_b);
	sort_four(head_a, head_b);
	push_node(head_b, head_a);
	printf("pa\n");
}
