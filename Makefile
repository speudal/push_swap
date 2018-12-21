# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:10:02 by tduval            #+#    #+#              #
#    Updated: 2018/12/20 00:35:11 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	gcc

CFLAGS				=	-Wall -Werror -Wextra 

INCLUDES			=	-I libft/ -I .

LIBFT				=	libft/libft.a

NAME_CHECKER		=	checker

NAME_PUSH_SWAP		=	push_swap

SRCS_CHECKER		=	./srcs/checker.c			\
						./srcs/parser.c				\
						./liblst/lst_free.c			\
						./liblst/lst_new.c			\
						./liblst/lst_pushback.c		\
						./moves/pushs.c				\
						./moves/reverse_rotates.c	\
						./moves/rotates.c			\
						./moves/swaps.c

SRCS_PUSH_SWAP		=	./srcs/push_swap.c			\
						./srcs/lst_len.c			\
						./liblst/print_stacks.c		\
						./srcs/parser.c				\
						./liblst/lst_free.c			\
						./liblst/lst_new.c			\
						./liblst/stacks_sorted.c	\
						./liblst/lst_pushback.c		\
						./moves/pushs.c				\
						./moves/reverse_rotates.c	\
						./moves/rotates.c			\
						./moves/swaps.c				\
						./algs/opti/opti.c			\
						./algs/short_sort.c

OBJ_CHECKER			=	$(SRCS_CHECKER:.c=.o)

OBJ_PUSH_SWAP		=	$(SRCS_PUSH_SWAP:.c=.o)

all	:	$(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER)	: $(OBJ_CHECKER)
	@$(MAKE) -C libft/
	@$(CC) $(OBJ_CHECKER) $(INCLUDES) $(LIBFT) -o $(NAME_CHECKER) 
	@echo "\x1b[36m[CHECKER COMPILED]\x1b[0m"

$(NAME_PUSH_SWAP) : $(OBJ_PUSH_SWAP)
	@$(MAKE) -C libft/
	@$(CC) $(OBJ_PUSH_SWAP) $(INCLUDES) $(LIBFT) -o $(NAME_PUSH_SWAP)
	@echo "\x1b[36m[PUSH_SWAP COMPILED]\x1b[0m"

%.o : %.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean	:
	@$(MAKE) -C libft/ clean
	@echo "\x1b[33;01mchecker : cleaning...\x1b[0m"
	@rm -f $(OBJ_CHECKER)
	@echo "\x1b[32;01m[CHECKER CLEANED]\x1b[0m"
	@echo "\x1b[33;01mpush_swap : cleaning...\x1b[0m"
	@rm -f $(OBJ_PUSH_SWAP)
	@echo "\x1b[32;01m[PUSH_SWAP CLEANED]\x1b[0m"

fclean	:	clean
	@$(MAKE) -C libft/ fclean
	@echo "\x1b[33;01mchecker : fcleaning...\x1b[0m"
	@rm -f $(NAME_CHECKER)
	@echo "\x1b[32;01m[CHECKER FCLEANED]\x1b[0m"
	@echo "\x1b[33;01mpush_swap : fcleaning...\x1b[0m"
	@rm -f $(NAME_PUSH_SWAP)
	@echo "\x1b[32;01m[PUSH_SWAP FCLEANED]\x1b[0m"

re		:	fclean all

.PHONY : all clean fclean re
