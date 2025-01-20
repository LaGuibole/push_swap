# Standard
NAME                = push_swap

# Directories
LIBFT               = ./LIBFT/libft.a
INC                 = includes/
SRC_DIR             = src/
OBJ_DIR             = obj/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra -g -I$(INC)
RM                  = rm -f

# Source Files
COMMANDS_DIR        =   $(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stack.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

ERRORS_DIR          =   $(SRC_DIR)push_swap/errors/handle_errors.c

INIT_DIR            =   $(SRC_DIR)push_swap/init/init_a_to_b.c \
						$(SRC_DIR)push_swap/init/init_b_to_a.c \
						$(SRC_DIR)push_swap/init/stack_init.c

MAIN_DIR            =   $(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/stack_utils.c

# Concatenate all source files
SRCS                = $(COMMANDS_DIR) $(ERRORS_DIR) $(INIT_DIR) $(MAIN_DIR)

# Object files
OBJ                 = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Build rules
start:
					@make all

$(LIBFT):
					@make -C ./LIBFT

all:                $(NAME)

$(NAME):            $(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:      $(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./LIBFT

fclean:             clean
					@$(RM) $(NAME)
					@make fclean -C ./LIBFT

re:                 fclean all

# Phony targets
.PHONY:             start all clean fclean re
