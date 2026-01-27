#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

struct node 
{
	int element;
	int to_top_cost;
	int target;
	struct node *next;
};

struct node *create_node(char *element);
void end_insert(struct node **head_ref, char *element);
void head_insert(struct node **head_ref, char *element);
void print_list(struct node *head);
int	is_numeric(char *element);
int no_duplicates(struct node **head);
void push_node(struct node **src_ref, struct node **dest_ref);
void swap_node(struct node **head);
void rotate_list(struct node **head);
void reverse_rotate_list(struct node **head);
void min_max(struct node **head_a, struct node **head_b);
void sort_three(struct node **head_ref);
void to_top_cost(struct node **head_ref);

#endif