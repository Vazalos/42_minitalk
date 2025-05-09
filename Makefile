# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 11:17:44 by david-fe          #+#    #+#              #
#    Updated: 2025/04/22 11:31:50 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME_1 = server
NAME_2 = client

# COMPILE & FLAGS
CC = cc
#CC = cc -fsanitize=address -fno-omit-frame-pointer
RM = rm -rf
CC_FLAGS = -Wall -Wextra -Werror -g

# SOURCE FILES
OBJ_PATH = .obj
SERVER_OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SERVER_SRC:.c=.o)))
CLIENT_OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(CLIENT_SRC:.c=.o)))
OBJ = $(SERVER_OBJ) $(CLIENT_OBJ)
SRC_PATH = src
SERVER_SRC = $(addprefix $(SRC_PATH)/, server.c )
CLIENT_SRC = $(addprefix $(SRC_PATH)/, client.c )

# LIBRARIES
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# RULES
all: $(LIBFT) $(NAME_1) $(NAME_2)
	@touch $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_PATH) $(SERVER_OBJ)
	$(CC) $(CC_FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_1)

$(NAME_2): $(OBJ_PATH) $(CLIENT_OBJ)
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_2)

$(LIBFT):
	@ git clone git@github.com:Vazalos/my_libft.git $(LIBFT_PATH)
	@ echo my_libft cloned
	$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)
	if [ -d "$(LIBFT_PATH)" ]; \
		then $(MAKE) -C $(LIBFT_PATH) clean; \
	fi

fclean: clean
	$(RM) $(NAME_1) $(NAME_2)
	if [ -d "$(LIBFT_PATH)" ]; \
		then $(MAKE) -C $(LIBFT_PATH) fclean; \
	fi
	if [ -d "$(LIBFT_PATH)" ]; \
		then $(RM) $(LIBFT_PATH); \
	fi

re: fclean all

.Phony: all clean fclean re
