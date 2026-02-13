/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:42:04 by jbentham          #+#    #+#             */
/*   Updated: 2026/02/13 15:37:00 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(char *element)
{
	t_node	*new_node;

	new_node = (struct s_node *)calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (free(new_node), NULL);
	new_node->element = ft_atoi(element);
	new_node->next = NULL;
	return (new_node);
}

void	end_insert(t_node **head_ref, char *element)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(element);
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
	{
		temp = *head_ref;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->element);
		temp = temp->next;
	}
}

int	is_numeric(char *element)
{
	int	i;

	i = 0;
	while (element[i] != '\0')
	{
		if (!((element[i] >= 48 && element[i] <= 57) || element[0] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	no_duplicates(t_node *head)
{
	int		count;
	t_node	*temp1;
	t_node	*temp2;

	count = 0;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp2 = head;
		while (temp2 != NULL && temp2 != temp1)
		{
			if (temp1->element == temp2->element)
				count++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (count >= 1)
		return (0);
	return (1);
}
