/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:30:29 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/13 17:41:47 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*cheapest;
	int		stack_created;

	head_a = NULL;
	head_b = NULL;
	cheapest = NULL;
	
	stack_created = create_stack(argc, argv, &head_a);
	if (stack_created == 0)
		return(1);
	while (stack_size(head_a) > 0)
	{
		to_top_cost(head_a);
		to_top_cost(head_b);
		add_target(head_a, head_b);
		to_target_cost(head_a);
		total_cost(head_a);
		cheapest = find_cheapest(head_a);
		execute_operations(&head_a, &head_b, cheapest);
	}
	while (stack_size(head_b) > 0)
	{
		push_node(&head_b, &head_a);
		printf("pa\n");
	}
	if (head_a != NULL)
	{
		while (head_a-> element > find_smallest_element(head_a)->element)
		{
			rotate_list(&head_a);
			printf("ra\n");
		}
	}
	free_list(head_a);
	free_list(head_b);
	return (0);
}
