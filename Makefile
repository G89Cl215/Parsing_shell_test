# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/08/22 14:52:11 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra
#-fsanitize=address

NAME		=	parsing_test

LIB_PATH	=	libft
LIB			=	libft.a

LIBS		=	$(LIB_PATH)/$(LIB) \

OBJ_DIR		=	obj

SRC_DIR	=	sources
SOURCES		=	main.c \
				termcaps.c \
				reprint_line.c \
				term_mode.c \
				prompt.c \
				cursor_tools.c \
				get_term_size.c \
				history.c \
				line_edit.c \
				ctrl_keys.c \
				word_tools.c \
				cursor_moves.c \
				fast_cursor_moves.c \

SRCS		=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJS		=	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))


HEADERS		=	includes/cursor.h \
				includes/dispatcher.h \

HDR_PATH	=	includes \
				libft/includes \

HDR_FLAG	=	$(addprefix -I ,$(HDR_PATH))

RM			=	rm -f

CLEAN		=	clean

all			:	libs
	@(($(MAKE) -q $(NAME) && echo "Your $(NAME) is up to date") || $(MAKE) $(NAME))

libs	:
	@cd $(LIB_PATH) && $(MAKE)

$(NAME)		:	$(LIBS) $(OBJS) Makefile
	@$(CC) $(CFLAGS) -ltermcap $(OBJS) $(LIBS) $(HDR_FLAG) -o $@
	@echo "$@ has been successfully created."

$(OBJS)		: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HDR_FLAG) -o $@ -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)	:
	@mkdir -p $@

clean		:
	@$(RM) $(OBJS)
	@rm -Rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean		:	clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME) exectutable and libft.a have been deleted."

re			:	fclean all

.PHONY: all libs clean fclean re
