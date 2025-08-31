NAME		:= fractol
SRCDIR		:= srcs
SRCS		:=	$(SRCDIR)/event_hooks.c \
				$(SRCDIR)/fractal_generator.c \
				$(SRCDIR)/inits.c \
				$(SRCDIR)/main.c \
				$(SRCDIR)/renderer.c \
				$(SRCDIR)/utils.c
OBJS		:=	$(SRCDIR)/event_hooks.o \
				$(SRCDIR)/fractal_generator.o \
				$(SRCDIR)/inits.o \
				$(SRCDIR)/main.o \
				$(SRCDIR)/renderer.o \
				$(SRCDIR)/utils.o
INC_DIR		:= includes
LIBFT_PATH	:= $(INC_DIR)/libft
LIBFT_A		:= $(LIBFT_PATH)/libft.a
MLX_PATH	:= $(INC_DIR)/mlx_linux
MLX_A		:= $(MLX_PATH)/libmlx_Linux.a
COMPILER	:= cc
CFLAGS		:= -Wall -Wextra -Werror -O3 -march=native
INCLUDES	:= -I. -I $(LIBFT_PATH) -I $(MLX_PATH) -I includes
LIBS		:= -L $(LIBFT_PATH) -lft -L $(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm
RM			:= rm -f

all:		$(NAME)

$(LIBFT_PATH):
			git clone https://github.com/cubicajupiter/42Hive-Libft.git $(LIBFT_PATH)

$(LIBFT_A):	| $(LIBFT_PATH)
			@if [ ! -f $(LIBFT_A) ]; then \
				echo "Building libft..."; \
				make -C $(LIBFT_PATH); \
			fi

$(MLX_PATH):
			git clone https://github.com/42paris/minilibx-linux.git $(MLX_PATH)

$(MLX_A):	| $(MLX_PATH)
			@if [ ! -f $(MLX_A) ]; then \
				echo "Building MLX..."; \
				make -C $(MLX_PATH); \
			fi

$(NAME):	$(OBJS) $(MLX_A) $(LIBFT_A)
			@echo "linking $@"
			$(COMPILER) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o:		%.c | $(MLX_PATH) $(LIBFT_PATH)
			@echo "Compiling $<"
			$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			@echo "Cleaning object files in parent and libft"
			@$(RM) $(OBJS)
			make clean -C $(LIBFT_PATH)
			make clean -C $(MLX_PATH)

fclean:		clean
			@echo "Cleaning library in parent and libft"
			@$(RM) $(NAME)
			make fclean -C $(LIBFT_PATH)

fclean-all:	fclean
			@echo "Removing libft and mlx"
			@$(RM) -rf $(LIBFT_PATH)
			@$(RM) -rf $(MLX_PATH)

re:			fclean all

.PHONY: all clean fclean re
