/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:50:54 by jibentham         #+#    #+#             */
/*   Updated: 2026/02/13 17:39:14 by jbentham         ###   ########.fr       */
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

typedef struct s_node
{
	int				element;
	int				to_top_cost;
	int				to_target_cost;
	int				total_cost;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

int		ft_atoi(const char *nptr);
t_node	*create_node(char *element);
void	end_insert(t_node **head_ref, char *element);
void	print_list(t_node *head);
int		is_numeric(char *element);
int		no_duplicates(t_node *head);
void	push_node(t_node **src_ref, t_node **dest_ref);
void	swap_node(t_node **head);
void	rotate_list(t_node **head);
void	reverse_rotate_list(t_node **head);
void	sort_two(t_node **head_ref);
void	sort_three(t_node **head_ref);
void	sort_four(t_node **head_a, t_node **head_b);
void	sort_five(t_node **head_a, t_node **head_b);
void	to_top_cost(t_node *head_ref);
t_node	*find_largest_element(t_node *head_ref);
t_node	*find_target(t_node *head_a, t_node *head_b);
void	add_target(t_node *head_a, t_node *head_b);
t_node	*find_last_node(t_node *head_ref);
int		get_absolute(int nb);
int		get_max(int a, int b);
void	to_target_cost(t_node *head_ref);
void	total_cost(t_node *head_ref);
void	execute_operations(t_node **head_a, t_node **head_b, t_node *cheapest);
void	rotate_both(t_node **head_a, t_node **head_b);
void	reverse_rotate_both(t_node **head_a, t_node **head_b);
t_node	*find_cheapest(t_node *head_ref);
int		stack_size(t_node *head_ref);
t_node	*find_tail(t_node **head_ref);
t_node	*find_smallest_element(t_node *head_ref);
void	free_list(t_node *head);
int	create_stack(int argc, char**argv, t_node **head);

#endif