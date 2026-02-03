/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:59:37 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/02 16:11:48 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_both(struct s_node **head_a, struct s_node **head_b)
{
    rotate_list(head_a);
    rotate_list(head_b);
}

void reverse_rotate_both(struct s_node **head_a, struct s_node **head_b)
{
    reverse_rotate_list(head_a);
    reverse_rotate_list(head_b);
}

struct s_node *find_cheapest(struct s_node *head_ref)
{
    struct s_node *cheapest;
    struct s_node *parser;

    if (head_ref == NULL)
        return (NULL);
    cheapest = head_ref;
    parser = head_ref;
    while (parser!= NULL)
    {
        if (parser->total_cost < cheapest->total_cost)
            cheapest = parser;
        parser = parser->next;
    }
    return (cheapest);
}

int stack_size(struct s_node *head_ref)
{
    int size;
    struct s_node *parser;

    size = 0;
    parser = head_ref;
    while (parser != NULL)
    {
        size++;
        parser = parser->next;
    }
    return (size);
}