/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:25:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/14 13:42:32 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

do_rule(char *rule, int *stack_a, int *stack_b)
{
	int i;
	int j;
	int *temp;
	
	i = 0;
	j = 0;
	while (stack_a)
		i++;
	while (stack_b)
		j++;
	if (rule == "sa" && i >= 1)
	{
		temp[0] == stack_a[0];
		stack_a[0] == stack_a[1];
		stack_a[1] == temp[0];
	}

	if (rule == "sb" && j >= 1)
	{
		temp[0] == stack_b[0];
		stack_b[0] == stack_b[1];
		stack_b[1] == temp[0];
	}

	
		
}