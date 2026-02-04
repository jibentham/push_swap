/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:50:54 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/04 13:44:35 by jbentham         ###   ########.fr       */
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
	int				element;
	int				to_top_cost;
	int				to_target_cost;
	int				total_cost;
	struct s_node	*target;
	struct s_node	*next;
};

struct s_node	*create_node(char *element);
void			end_insert(struct s_node **head_ref, char *element);
void			print_list(struct s_node *head);
int				is_numeric(char *element);
int				no_duplicates(struct s_node *head);
void			push_node(struct s_node **src_ref, struct s_node **dest_ref);
void			swap_node(struct s_node **head);
void			rotate_list(struct s_node **head);
void			reverse_rotate_list(struct s_node **head);
void			sort_two(struct s_node **head_ref);
void			sort_three(struct s_node **head_ref);
void			sort_five(struct s_node **head_a, struct s_node **head_b);
void			to_top_cost(struct s_node *head_ref);
struct s_node	*find_largest_element(struct s_node *head_ref);
struct s_node	*find_target(struct s_node *head_a, struct s_node *head_b);
void			add_target(struct s_node *head_a, struct s_node *head_b);
int				get_absolute(int nb);
int				get_max(int a, int b);
void			to_target_cost(struct s_node *head_a, struct s_node *head_b);
void			total_cost(struct s_node *head_ref);
void			execute_operations(struct s_node **head_a, struct s_node **head_b, struct s_node *cheapest);
void			rotate_both(struct s_node **head_a, struct s_node **head_b);
void			reverse_rotate_both(struct s_node **head_a, struct s_node **head_b);
struct s_node	*find_cheapest(struct s_node *head_ref);
int				stack_size(struct s_node *head_ref);

#endif