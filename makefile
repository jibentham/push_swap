# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 15:25:00 by jibentham         #+#    #+#              #
#    Updated: 2026/02/13 15:31:32 by jbentham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =   costs_utils.c \
		costs.c \
		instruction_set.c \
		list_creation.c \
		main_utils.c \
		main.c \
		instruction_utils.c \
		instruction_execution.c \
		ft_atoi.c \
		small_sorts.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking library $@"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
  
%.o: %.c push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@echo "Removing object files..."
	rm -f $(OBJS)

fclean: clean	
	@echo "Removing library archive $(NAME)..."
	rm  -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	