/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:50:54 by jibentham         #+#    #+#             */
/*   Updated: 2026/01/30 14:54:58 by jibentham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

struct s_node
{
	int element;
	int to_top_cost;
	int target;
	struct s_node *next;
};

struct s_node *create_node(char *element);
void end_insert(struct s_node **head_ref, char *element);
//void head_insert(struct s_node **head_ref, char *element);
void print_list(struct s_node *head);
int	is_numeric(char *element);
int no_duplicates(struct s_node *head);
void push_node(struct s_node **src_ref, struct s_node **dest_ref);
void swap_node(struct s_node **head);
void rotate_list(struct s_node **head);
void reverse_rotate_list(struct s_node **head);
void min_max(struct s_node **head_a, struct s_node **head_b);
void sort_three(struct s_node **head_ref);
void to_top_cost(struct s_node *head_ref);

#endif