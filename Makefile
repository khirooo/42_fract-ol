# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 13:30:03 by kfergani          #+#    #+#              #
#    Updated: 2022/08/04 05:21:30 by kfergani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
BONUS_NAME = fractol_bonus
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -lglfw
INCLUDE	=	includes
MLX_PATH = /Users/kfergani/goinfre/.brew/opt/glfw/lib/
LIBFT	=	libftprintf.a
PRINTF_DIR	=	./ft_printf
MLX	=	libmlx42.a
MLXDIR	=	./MLX42
SRCDIR	=	src
BONUS_DIR = bonus
OBJDIR	=	obj

SOURCES	=	fractol.c fractol_utils.c fractol_utils2.c
BONUS_SOURCES = fractol_bonus.c fractol_utils_bonus.c fractol_utils2_bonus.c

SRCS	=	$(addprefix $(SRCDIR)/, $(SOURCES))
SRCS_BONUS = $(addprefix $(BONUS_DIR)/, $(BONUS_SOURCES))
OBJS	=	$(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
OBJS_BONUS = $(addprefix $(BONUS_DIR)/, $(BONUS_SOURCES:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -L $(MLX_PATH)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) -o $(BONUS_NAME) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -L $(MLX_PATH)

$(OBJDIR)/%.o : $(SRCDIR)/%.c 
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c 
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT) : $(PRINTF_DIR)
	make -C $(PRINTF_DIR)
	cp	$(PRINTF_DIR)/$(LIBFT) ./

$(MLX) : $(MLXDIR)
	make -C $(MLXDIR)
	cp	$(MLXDIR)/$(MLX) ./

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	rm -rf $(OBJDIR)
	rm -rf $(MLX)
	rm -rf $(LIBFT)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(MLXDIR)

re: fclean all

.PHONY: all clean fclean re