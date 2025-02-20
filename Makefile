# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 17:17:46 by guphilip          #+#    #+#              #
#    Updated: 2025/02/20 17:27:19 by guphilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

BLUE				= 		\033[1;34m
GREEN				= 		\033[1;32m
YELLOW				=		\033[1;33m
CYAN				=		\033[1;36m
RESET				= 		\033[0m

# COMMANDS

RM					=		/usr/bin/rm -fr
ECHO				=		/usr/bin/echo
RM_LINE 			= 		@tput cuu1 && tput el

# FLAGS && COMPIL

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = -I$(INC_DIR)

# DIRECTORIES

SRC_DIR 			=		src
INC_DIR				=		includes
LIB_DIR				=		libs
OBJ_DIR				= 		obj

# SO_LONG

SRC_FILES 			=		push_swap/push_swap \
							push_swap/stack_utils \
							commands/push \
							commands/rev_rotate \
							commands/rotate \
							commands/sort_three \
							commands/sort_stack \
							commands/swap \
							push_swap/errors/handle_errors \
							push_swap/init/init_a_to_b \
							push_swap/init/init_b_to_a \
							push_swap/init/stack_init \

SRCS				=		$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS				=		$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

#TARGET

NAME				=		push_swap
LIB_TARGET			=		$(LIBFT_TARGET)

# LIBFT COMPILATION

LIBFT_GIT			= 		https://github.com/LaGuibole/Libft_Boosted.git
LIBFT_DIR			= 		Libft_Boosted
LIBFT_PATH			= 		$(LIB_DIR)/$(LIBFT_DIR)
LIBFT_H				= 		libft.h
LIBFT_H_PATH		= 		$(LIBFT_PATH)/includes/$(LIBFT_H)
LIBFT_INC_H			= 		$(INC_DIR)/$(LIBFT_H)
LIBFT_TARGET		= 		libft.a
LIBFT_TARGET_PATH	= 		$(LIBFT_PATH)/$(LIBFT_TARGET)

all:						$(NAME)

clean:
							@$(RM) -r $(OBJ_DIR)

fclean: clean
							@$(RM) $(NAME)
							@$(RM) $(LIBFT_TARGET)
							@$(RM) $(LIBFT_INC_H)

re: fclean all

cleanlibs:
							@$(MAKE) clean --no-print-directory -C $(LIBFT_PATH)

fcleanlibs: fclean
							@$(RM) -r $(LIBFT_PATH)

relibs: fcleanlibs $(LIBFT_INC_H)

norminette:
							@norminette $(SRC_DIR) $(BONUS_SRC) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
							&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
							|| $(ECHO) -e '\033[1;32mNorminette OK!'

.PHONY: all re clean fclean cleanlibs fcleanlibs relibs norminette fr

$(LIBFT_INC_H): $(LIBFT_TARGET)
							@cp $(LIBFT_H_PATH) $@

$(LIBFT_TARGET):
							@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
								printf "Cloning lib \"%s\" into \"%s\"..." $(LIBFT_GIT) $(LIBFT_PATH);\
								git clone $(LIBFT_GIT) $(LIBFT_PATH);\
							fi
							@printf "\nMaking \"%s\"..." $@
							@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
							@cp $(LIBFT_TARGET_PATH) ./
							@printf "\n✅ Done copying archive $(GREEN) \"%s\" $(RESET)... \n\n" $@

# SO_LONG TARGET

$(NAME): $(LIBFT_INC_H) $(OBJS)
							@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT_TARGET) $(LIBFLAGS)
							@echo "🎉 Executable$(BLUE) $(NAME) $(RESET)created. \n"

# OBJ DIR

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)

# .O FILE COMPILATION

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
							@echo "⚙️ Compiling $< into $@ ...\n"
							@${RM_LINE}
							@mkdir -p $(dir $@)
							@$(CC) -I$(IFLAGS) $(CFLAGS) -c $< -o $@
							@${RM_LINE}


# # Standard
# NAME                = push_swap

# # Directories
# LIBFT               = ./LIBFT/libft.a
# INC                 = includes/
# SRC_DIR             = src/
# OBJ_DIR             = obj/

# # Compiler and CFlags
# CC                  = gcc
# CFLAGS              = -Wall -Werror -Wextra -g -I$(INC)
# RM                  = rm -f

# # Source Files
# COMMANDS_DIR        =   $(SRC_DIR)commands/push.c \
# 						$(SRC_DIR)commands/rev_rotate.c \
# 						$(SRC_DIR)commands/rotate.c \
# 						$(SRC_DIR)commands/sort_stack.c \
# 						$(SRC_DIR)commands/sort_three.c \
# 						$(SRC_DIR)commands/swap.c

# ERRORS_DIR          =   $(SRC_DIR)push_swap/errors/handle_errors.c

# INIT_DIR            =   $(SRC_DIR)push_swap/init/init_a_to_b.c \
# 						$(SRC_DIR)push_swap/init/init_b_to_a.c \
# 						$(SRC_DIR)push_swap/init/stack_init.c

# MAIN_DIR            =   $(SRC_DIR)push_swap/push_swap.c \
# 						$(SRC_DIR)push_swap/stack_utils.c

# # Concatenate all source files
# SRCS                = $(COMMANDS_DIR) $(ERRORS_DIR) $(INIT_DIR) $(MAIN_DIR)

# # Object files
# OBJ                 = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


# # Phony targets

# .PHONY:             start all clean fclean re

# # Build rules
# start:
# 					@make all

# $(LIBFT):
# 					@make -C ./LIBFT

# all:                $(NAME)

# $(NAME):            $(OBJ) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# # Compile object files from source files
# $(OBJ_DIR)%.o:      $(SRC_DIR)%.c
# 					@mkdir -p $(@D)
# 					@$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 					@$(RM) -r $(OBJ_DIR)
# 					@make clean -C ./LIBFT

# fclean:             clean
# 					@$(RM) $(NAME)
# 					@make fclean -C ./LIBFT

# re:                 fclean all

