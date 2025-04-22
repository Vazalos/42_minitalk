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
NAME =  server
NAME2 = client

# COMPILE & FLAGS
CC = cc
RM = rm -rf
CC_FLAGS = -Wall -Wextra -Werror -g

# SOURCE FILES
OBJ_PATH = .obj
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, server.c \
								client.c \

# LIBRARIES
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# RULES
all: $(NAME)

$(NAME): LIBFT

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

