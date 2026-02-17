/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:58:27 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/17 22:09:05 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

void	rotate_fwd(t_node **head, int *cost, char *fwd,
		void (*rotate)(t_node **))
{
	while (*cost > 0)
	{
		rotate(head);
		(*cost)--;
		ft_printf("%s\n", fwd);
	}
}

void	rotate_rev(t_node **head, int *cost, char *rev,
		void (*rev_rotate)(t_node **))
{
	while (*cost < 0)
	{
		rev_rotate(head);
		(*cost)++;
		ft_printf("%s\n", rev);
	}
}

void	execute_instructions(t_node **head_a, t_node **head_b, t_node *cheapest)
{
	int	a;
	int	b;

	a = cheapest->to_top_cost;
	b = cheapest->to_target_cost;
	while (a > 0 && b > 0)
	{
		rotate_both(head_a, head_b);
		a--;
		b--;
		ft_printf("rr\n");
	}
	while (a < 0 && b < 0)
	{
		reverse_rotate_both(head_a, head_b);
		a++;
		b++;
		ft_printf("rrr\n");
	}
	rotate_fwd(head_a, &a, "ra", rotate_list);
	rotate_rev(head_a, &a, "rra", reverse_rotate_list);
	rotate_fwd(head_b, &b, "rb", rotate_list);
	rotate_rev(head_b, &b, "rrb", reverse_rotate_list);
	push_node(head_a, head_b);
	ft_printf("pb\n");
}
