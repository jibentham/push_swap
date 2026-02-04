/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:58:27 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/04 12:36:59 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations(struct s_node **head_a, struct s_node **head_b, struct s_node *cheapest)
{
	while (cheapest->to_top_cost > 0 && cheapest->to_target_cost > 0)
	{
		rotate_both(head_a, head_b);
		cheapest->to_top_cost--;
		cheapest->to_target_cost--;
	}
	while (cheapest->to_top_cost < 0 && cheapest->to_target_cost < 0)
	{
		reverse_rotate_both(head_a, head_b);
		cheapest->to_top_cost++;
		cheapest->to_target_cost++;
	}
	while (cheapest->to_top_cost > 0)
	{
		rotate_list(head_a);
		cheapest->to_top_cost--;
	}
	while (cheapest->to_top_cost < 0)
	{
		reverse_rotate_list(head_a);
		cheapest->to_top_cost++;
	}
	while (cheapest->to_target_cost > 0)
	{
		rotate_list(head_b);
		cheapest->to_target_cost--;
	}
	while (cheapest->to_target_cost < 0)
	{
		reverse_rotate_list(head_b);
		cheapest->to_target_cost++;
	}
	push_node(head_a, head_b);
}
