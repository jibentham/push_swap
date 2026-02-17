# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 15:25:00 by jibentham         #+#    #+#              #
#    Updated: 2026/02/17 22:04:51 by jbentham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB_DIR = libftprintf
LIB = $(LIB_DIR)/libftprintf.a

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

$(NAME): $(LIB) $(OBJS)
	@echo "Linking library $@"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lftprintf -o $(NAME)

$(LIB):
	@echo "Building library..."
	$(MAKE) -C $(LIB_DIR)
  
%.o: %.c push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@
	
clean:
	@echo "Removing object files..."
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean	
	@echo "Removing library archive $(NAME)..."
	rm  -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re	