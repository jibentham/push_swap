# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jibentham <jibentham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 15:25:00 by jibentham         #+#    #+#              #
#    Updated: 2026/02/04 10:27:04 by jibentham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRC =   costs_utils.c \
		costs.c \
		instruction_set.c \
		list_creation.c \
		main.c \
		instruction_utils.c \
		instruction_execution.c \
		small_sorts.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking library $@"
	$(AR) $@ $^
  
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