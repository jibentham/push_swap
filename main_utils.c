/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:58:59 by jbentham          #+#    #+#             */
/*   Updated: 2026/02/17 22:09:46 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

t_node	*find_smallest_element(t_node *head_ref)
{
	t_node	*temp;

	if (head_ref == NULL)
		return (NULL);
	temp = head_ref;
	while (head_ref != NULL)
	{
		if (head_ref->element < temp->element)
			temp = head_ref;
		head_ref = head_ref->next;
	}
	return (temp);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

int	create_stack(int argc, char**argv, t_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_numeric(argv[i]) == 1)
			end_insert(head, argv[i]);
		else
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	if (no_duplicates(*head) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (head == NULL)
		return (0);
	return (1);
}

int	is_list_ordered(t_node *head)
{
	t_node	*parser;

	parser = head;
	while (parser != NULL && parser->next != NULL)
	{
		if (parser->element > parser->next->element)
			return (0);
		parser = parser->next;
	}
	return (1);
}
