/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:25:01 by jbentham          #+#    #+#             */
/*   Updated: 2026/01/14 14:53:19 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	push_swap_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char *do_rule(char *rule, char *stack)
{
	int i;
	
	i = 0;
	while (stack[i] != '\0')
		i++;
	if ((push_swap_strcmp(rule, "sa") || push_swap_strcmp(rule, "sb")) && i >= 1)
	{
		swap(&stack[0], &stack[1]);
		return (stack);
	}
	return (NULL);
}

int main(void)
{
	char stack_a[] = "10234";
	// char stack_b[] = "10234";

	do_rule("sa", stack_a);
	printf("%s", stack_a);
	return (0);
}