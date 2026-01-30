/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sorts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:17:59 by jibentham         #+#    #+#             */
/*   Updated: 2026/01/30 14:24:30 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(struct s_node **head_ref)
{
	if ((*head_ref)->element < (*head_ref)->next->element)
		swap_node(head_ref);
}

void sort_three(struct s_node **head_ref)
{
	if ((*head_ref)->element < (*head_ref)->next->element 
		&& (*head_ref)->element > (*head_ref)->next->next->element)
		swap_node(head_ref);
	if ((*head_ref)->element < (*head_ref)->next->element 
		&& (*head_ref)->element < (*head_ref)->next->next->element)
		rotate_list(head_ref);
}

void sort_five(struct s_node **head_a, struct s_node **head_b)
{
	push_node(head_a, head_b);
    push_node(head_a, head_b);
    sort_three(head_a);
    sort_two(head_b);
   	push_node(head_b, head_a);
    push_node(head_b, head_a); 
}