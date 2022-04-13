# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:37:14 by mreymond          #+#    #+#              #
#    Updated: 2022/04/13 16:15:33 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/pipex.c

OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= pipex
RM			= rm -f
PRINTF_PATH	= src/printf
LIBFT_PATH	= src/libft

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) --silent -C $(PRINTF_PATH)
			@$(MAKE) --silent -C $(LIBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf -o $(NAME)

run:	
			./$(NAME) infile "ls -l" "wc -l" outfile

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(MAKE) -C $(PRINTF_PATH) clean

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run
