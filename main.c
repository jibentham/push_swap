/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:30:29 by jibentham         #+#    #+#             */
/*   Updated: 2026/01/30 14:55:32 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	struct s_node *head_a;
	//struct s_node *head_b;
	int i;

	head_a = NULL;
	//head_b = NULL;
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
	print_list(head_a);
	return (0);
}
