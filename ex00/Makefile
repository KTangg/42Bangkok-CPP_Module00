# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:45:40 by spoolpra          #+#    #+#              #
#    Updated: 2022/04/27 14:54:54 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

OBJ_DIR = objs/

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJS))
		$(CC) $^ -o $@
$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJ_DIR)
fclean: clean
		$(RM) $(NAME)
re: fclean all
