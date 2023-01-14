# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 18:28:25 by kfergani          #+#    #+#              #
#    Updated: 2022/07/25 13:40:44 by kfergani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	./libft/
GNL		= 	./get_next_line
GNL_OBJDIR	=	./get_next_line/objs
INCLUDE	=	./includes/
SRCDIR	=	./src/
OBJDIR	=	./objs

GNL_SOURCES	=	get_next_line.c get_next_line_utils.c
SOURCES	=	ft_printf.c ft_printf_utils.c ft_print_conv.c print_conv.c hex_stuff.c ft_itoa_u.c\

GNL_SRC = $(addprefix $(GNL)/, $(GNL_SOURCES))
GNL_OBJ	=	$(addprefix $(GNL_OBJDIR)/, $(GNL_SOURCES:.c=.o))
SRCS	=	$(addprefix $(SRCDIR)/, $(SOURCES))
OBJS	=	$(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))



all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@ar rcs $(NAME) $(GNL_OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDE)/ft_printf.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(GNL_OBJDIR)/%.o: $(GNL)/%.c 
	@mkdir -p $(GNL_OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $<
 
clean:
	@rm -rf $(OBJS)
	@rm -rf $(GNL_OBJ)
	@rm -rf $(OBJDIR)
	@rm -rf $(GNL_OBJDIR)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
