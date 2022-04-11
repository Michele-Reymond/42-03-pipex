# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:37:14 by mreymond          #+#    #+#              #
#    Updated: 2022/04/11 19:08:08 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/pipex.c

OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= pipex
RM			= rm -f
PRINTF_PATH	= src/printf

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) --silent -C $(PRINTF_PATH)
			$(CC) $(CFLAGS) $(OBJS) -L $(PRINTF_PATH) -lftprintf -o $(NAME)

run:	
			./$(NAME) infile "ls -l" "wc -l" outfile

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(PRINTF_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C $(PRINTF_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run
