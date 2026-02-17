/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:17:59 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/17 22:02:07 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

void	sort_two(t_node **head_ref)
{
	int	first;
	int	second;

	first = (*head_ref)->element;
	second = (*head_ref)->next->element;
	if (first > second)
		swap_node(head_ref);
	ft_printf("sa\n");
}

void	sort_three_1(t_node **head_ref)
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
		ft_printf("sa\n");
		ft_printf("rra\n");
	}
	else if (first < second && second > third && first < third)
	{
		swap_node(head_ref);
		rotate_list(head_ref);
		ft_printf("sa\n");
		ft_printf("ra\n");
	}
}

void	sort_three_2(t_node **head_ref)
{
	int	first;
	int	second;
	int	third;

	first = (*head_ref)->element;
	second = (*head_ref)->next->element;
	third = (*head_ref)->next->next->element;
	if (first < second && second > third && first > third)
	{
		reverse_rotate_list(head_ref);
		ft_printf("rra\n");
	}
	else if (first > second && second < third && first < third)
	{
		swap_node(head_ref);
		ft_printf("sa\n");
	}
	else if (first > second && second < third && first > third)
	{
		rotate_list(head_ref);
		ft_printf("ra\n");
	}
}

void	sort_four(t_node **head_a, t_node **head_b)
{
	t_node	*smallest;

	smallest = find_smallest_element(*head_a);
	while (*head_a != smallest)
	{
		to_top_cost(*head_a);
		if (smallest->to_top_cost < 0)
		{
			reverse_rotate_list(head_a);
			ft_printf("rra\n");
		}
		else if (smallest->to_top_cost > 0)
		{
			rotate_list(head_a);
			ft_printf("ra\n");
		}
	}
	push_node(head_a, head_b);
	ft_printf("pb\n");
	sort_three_1(head_a);
	sort_three_2(head_a);
	push_node(head_b, head_a);
	ft_printf("pa\n");
}

void	sort_five(t_node **head_a, t_node **head_b)
{
	t_node	*smallest;

	smallest = find_smallest_element(*head_a);
	while (*head_a != smallest)
	{
		to_top_cost(*head_a);
		if (smallest->to_top_cost < 0)
		{
			reverse_rotate_list(head_a);
			ft_printf("rra\n");
		}
		else if (smallest->to_top_cost > 0)
		{
			rotate_list(head_a);
			ft_printf("ra\n");
		}
	}
	push_node(head_a, head_b);
	ft_printf("pb\n");
	sort_four(head_a, head_b);
	push_node(head_b, head_a);
	ft_printf("pa\n");
}
