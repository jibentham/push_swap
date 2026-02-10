/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:30:29 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/10 17:14:53 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_node	*head_a;
	struct s_node	*head_b;
	struct s_node	*cheapest;
	int				i;

	head_a = NULL;
	head_b = NULL;
	cheapest = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_numeric(argv[i]))
			end_insert(&head_a, argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	if (no_duplicates(head_a) == 0)
	{
		printf("Error\n");
		return (1);
	}
	if (head_a == NULL)
		return (1);
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
	while (head_a-> element > find_smallest_element(head_a)->element)
	{
		rotate_list(&head_a);
		printf("ra\n");
	}
	// print_list(head_a);
	while (head_a != NULL)
	{
		free(head_a);
		head_a = head_a->next;
	}
	return (0);
}
