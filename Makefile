# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:10:02 by tduval            #+#    #+#              #
#    Updated: 2018/12/03 22:59:46 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER		=	checker

NAME_PUSH_SWAP		=	push_swap

FLAGS				=	-Wall -Werror -Wextra

MAKE_LIBFT			=	$(MAKE) ./libft

SRCS_CHECKER		=	./srcs/checker.c				\
						./srcs/free_all.c			\
						./srcs/parser.c				\
						./moves/pushs.c				\
						./moves/reverse_rotates.c	\
						./moves/rotates.c			\
						./moves/swaps.c


OBJS_CHECKER		=	$(SRCS_CHECKER:.c=.o)

all		:	$(NAME_CHECKER) #$(NAME_PUSH_SWAP)

$(NAME_CHECKER)	:
	$(MAKE) -C libft/
	gcc -c $(SRCS_CHECKER) $(FLAGS) -I libft/ -I.
	gcc -o $(NAME_CHECKER) *.o libft/libft.a

$(NAME_PUSH_SWAP) :
	$(OBJS)
	$(CC) $(OBJS) -o $(NAME_PUSH_SWAP)

clean	:
	$(MAKE) -C libft/ clean
	rm -f $(OBJS)

fclean	:	clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_PUSH_SWAP)

re		:	fclean all
