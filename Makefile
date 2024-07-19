# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 08:48:03 by gude-jes          #+#    #+#              #
#    Updated: 2024/07/04 11:17:06 by gude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
MLXFLAGS 	= -L ./lib/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
NAME		= so_long
NAME_BONUS	= so_long_bonus

INC			= -I./includes
RM			= rm -rf

GENERAL		= main init dead
RENDER		= render_map render_window
MOVEMENT	= movement movement_utils
MAP			= check_map1 check_map2 checker map_utils

BONUS_GENERAL	= main_bonus init_bonus dead_bonus
BONUS_RENDER	= render_map_bonus render_window_bonus
BONUS_MOVEMENT	= movement_bonus movement_utils_bonus render_moves_bonus
BONUS_MAP		= check_map1_bonus check_map2_bonus checker_bonus map_utils_bonus
BONUS_ATTACK	= attack_bonus lightsaber_bonus attack_checker_bonus attack_boss_bonus
BONUS_ENEMY		= enemy_bonus boss_bonus boss_health_bonus

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#
VPATH 		= src src/map\
				src/movement\
				src/renders\
				src_bonus src_bonus/map\
				src_bonus/movement\
				src_bonus/renders\
				src_bonus/attack\
				src_bonus/enemy

LIBS_PATH	= lib

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT 		= $(LIBFT_PATH)/libft.a
MLX_PATH	= $(LIBS_PATH)/minilibx-linux
MLX			= $(MLX_PATH)/libmlx_Linux.a

SRC			= $(addsuffix .c, $(GENERAL))\
			 $(addsuffix .c, $(RENDER))\
			 $(addsuffix .c, $(MOVEMENT))\
			 $(addsuffix .c, $(MAP))\

BONUS_SRC	= $(addsuffix .c, $(BONUS_GENERAL))\
			 $(addsuffix .c, $(BONUS_RENDER))\
			 $(addsuffix .c, $(BONUS_MOVEMENT))\
			 $(addsuffix .c, $(BONUS_MAP))\
			 $(addsuffix .c, $(BONUS_ATTACK))\
			 $(addsuffix .c, $(BONUS_ENEMY))\

OBJ_DIR		= obj

OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	= $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: deps $(NAME)

deps: 
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR) $(BONUS_OBJS) $(DEPS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(OBJS)

clean_bonus:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(BONUS_OBJS)
	@$(RM) $(NAME_BONUS)

fclean: clean clean_bonus
	@$(MAKE) fclean -C $(LIBFT_PATH) 
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(NAME) $(OBJ_DIR)
	@$(RM) $(NAME_BONUS) $(OBJ_DIR)

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C lib
	@rm minilibx-linux.tgz
