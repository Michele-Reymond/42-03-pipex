# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:37:14 by mreymond          #+#    #+#              #
#    Updated: 2022/04/20 14:06:53 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	pipex.c \
				pipex_utils.c \
				pipex_errors.c \
				ft_split.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_substr.c \
				ft_strlcpy.c

OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-g -fsanitize=address
NAME		= pipex
RM			= rm -f
PRINTF_PATH	= printf

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

re:			fclean all

.PHONY:		all clean fclean re run
