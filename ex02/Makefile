# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:45:40 by spoolpra          #+#    #+#              #
#    Updated: 2022/04/28 14:20:32 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

OBJ_DIR = objs/

NAME = tests
MY_LOG = my_log.log
OLD_LOG = 19920104_091532.log
SRCS = tests.cpp Account.cpp
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

compare: all
		./$(NAME) | awk '{print $$2}' > $(MY_LOG)
		cat $(OLD_LOG) | awk '{print $$2}' > no_ts.log
		diff $(MY_LOG) no_ts.log
