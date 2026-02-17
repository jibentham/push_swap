/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:30:29 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/17 22:01:01 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

void	sort_small_stack(t_node **head_a, t_node **head_b, int size)
{
	if (size == 5)
		sort_five(head_a, head_b);
	else if (size == 4)
		sort_four(head_a, head_b);
	else if (size == 3)
	{
		sort_three_1(head_a);
		sort_three_2(head_a);
	}
	else if (size == 2)
		sort_two(head_a);
}

void	sort_large_stack(t_node **head_a, t_node **head_b)
{
	t_node	*cheapest;

	cheapest = NULL;
	while (stack_size(*head_a) > 0)
	{
		to_top_cost(*head_a);
		to_top_cost(*head_b);
		add_target(*head_a, *head_b);
		to_target_cost(*head_a);
		total_cost(*head_a);
		cheapest = find_cheapest(*head_a);
		execute_instructions(head_a, head_b, cheapest);
	}
	while (stack_size(*head_b) > 0)
	{
		push_node(head_b, head_a);
		ft_printf("pa\n");
	}
	while (*head_a != NULL
		&& (*head_a)-> element > find_smallest_element(*head_a)->element)
	{
		rotate_list(head_a);
		ft_printf("ra\n");
	}
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (create_stack(argc, argv, &head_a) == 0)
		return (1);
	if (is_list_ordered(head_a) == 1)
	{
		free_list(head_a);
		return (0);
	}
	if (stack_size(head_a) <= 5)
	{
		sort_small_stack(&head_a, &head_b, stack_size(head_a));
		free_list(head_a);
		free_list(head_b);
		return (0);
	}
	else
		sort_large_stack(&head_a, &head_b);
	free_list(head_a);
	free_list(head_b);
	return (0);
}
