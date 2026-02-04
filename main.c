/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:30:29 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/04 12:26:06 by jbentham         ###   ########.fr       */
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
		add_target(head_a, head_b);
		to_target_cost(head_a, head_b);
		total_cost(head_a);
		cheapest = find_cheapest(head_a);
		execute_operations(&head_a, &head_b, cheapest);
	}
	while (head_b->element < head_b->next->element)
		rotate_list(&head_b);
	while (stack_size(head_b) > 0)
		push_node(&head_b, &head_a);
	while (head_a-> element < find_largest_element(head_a)->element)
		rotate_list(&head_a);
	rotate_list(&head_a);
	print_list(head_a);
	return (0);
}
