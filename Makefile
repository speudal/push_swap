# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:10:02 by tduval            #+#    #+#              #
#    Updated: 2018/12/06 12:03:15 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME_CHECKER		=	checker

NAME_PUSH_SWAP		=	push_swap

CFLAGS				=	-Wall -Werror -Wextra -I libft/ -I.

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
						./liblst/print_stacks.c		\
						./srcs/parser.c				\
						./liblst/lst_free.c			\
						./liblst/lst_new.c			\
						./liblst/lst_pushback.c		\
						./moves/pushs.c				\
						./moves/reverse_rotates.c	\
						./moves/rotates.c			\
						./moves/swaps.c				\
						./algs/sale_sort.c

OBJS_CHECKER		=	$(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP		=	$(SRCS_PUSH_SWAP:.c=.o)

all		:	$(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER)	: $(OBJS_CHECKER)
	$(MAKE) -C libft/
	gcc -o $(NAME_CHECKER) $(OBJS_CHECKER) libft/libft.a

$(NAME_PUSH_SWAP) : $(OBJS_PUSH_SWAP)
	$(MAKE) -C libft/
	gcc -o $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) libft/libft.a

clean	:
	$(MAKE) -C libft/ clean
	rm -f $(OBJS_CHECKER)
	rm -f $(OBJS_PUSH_SWAP)

fclean	:	clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_PUSH_SWAP)

re		:	fclean all
