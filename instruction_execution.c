/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:58:27 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/04 23:23:19 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations(struct s_node **head_a, struct s_node **head_b, struct s_node *cheapest)
{
	int a;
	int b;
	
	a = cheapest->to_top_cost;
	b = cheapest->to_target_cost;
	while (a > 0 && b > 0)
	{
		rotate_both(head_a, head_b);
		a--;
		b--;
		printf("rr\n");
	}
	while (a < 0 && b < 0)
	{
		reverse_rotate_both(head_a, head_b);
		a++;
		b++;
		printf("rrr\n");
	}
	while (a > 0)
	{
		rotate_list(head_a);
		a--;
		printf("ra\n");
	}
	while (a < 0)
	{
		reverse_rotate_list(head_a);
		a++;
		printf("rra\n");
	}
	while (b > 0)
	{
		rotate_list(head_b);
		b--;
		printf("rb\n");
	}
	while (b < 0)
	{
		reverse_rotate_list(head_b);
		b++;
		printf("rrb\n");
	}
	push_node(head_a, head_b);
	printf("pb\n");
}
