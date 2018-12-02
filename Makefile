# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:10:02 by tduval            #+#    #+#              #
#    Updated: 2018/12/02 17:39:22 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER		=	checker

NAME_PUSH_SWAP		=	push_swap

CFLAGS				=	-Wall -Werror -Wextra ./libft/libft.a -I ./libft

MAKE_LIBFT			=	$(MAKE) -C ./libft

SRCS				=	./checker.c

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc $(OBJS)

all		:	$(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER)	:	$(MAKE_LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $(NAME_CHECKER)

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
