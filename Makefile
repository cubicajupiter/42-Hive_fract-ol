NAME		:= fractol

SRCDIR		:= srcs
VPATH		:= $(SRCDIR)
SRCS		:=	event_handler.c \
				fractal_generator.c \
				initiator.c \
				zoomer.c \
				main.c \
				parser.c

OBJDIR		:= objs
OBJS		:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INC_DIR		:= includes

LIBFT_PATH	:= $(INC_DIR)/libft
LIBFT_A		:= $(LIBFT_PATH)/libft.a

MLX_PATH	:= $(INC_DIR)/mlx_linux
MLX_A		:= $(MLX_PATH)/libmlx_Linux.a

COMPILER	:= cc
CFLAGS		:= -Wall -Wextra -Werror -O3 -march=native

INCLUDES	:= -I. -I $(LIBFT_PATH) -I $(MLX_PATH) -I includes
LIBS		:= -L $(LIBFT_PATH) -lft -L $(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm

HEADER		:= $(INC_DIR)/fractol.h

DEBUG		:= -g

RM			:= rm -f

all:		$(NAME)

$(LIBFT_PATH):
						git clone https://github.com/cubicajupiter/42Hive-Libft.git $(LIBFT_PATH)

$(LIBFT_A):			| $(LIBFT_PATH)
						@if [ ! -f $(LIBFT_A) ]; then \
							echo "Building libft..."; \
							make -C $(LIBFT_PATH); \
						fi

$(MLX_PATH):
						git clone https://github.com/42paris/minilibx-linux.git $(MLX_PATH)

$(MLX_A):			| $(MLX_PATH)
						@if [ ! -f $(MLX_A) ]; then \
							echo "Building MLX..."; \
							make -C $(MLX_PATH); \
						fi

$(OBJDIR):
						mkdir -p $(OBJDIR)

$(NAME):			$(OBJS) $(MLX_A) $(LIBFT_A)
						@echo "linking $@"
						$(COMPILER) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o:		$(SRCDIR)/%.c $(HEADER) | $(OBJDIR) $(MLX_PATH) $(LIBFT_PATH)
						@echo "Compiling $<"
						$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
						@echo "Cleaning object files in parent and libft"
						@$(RM) $(OBJS)
						make clean -C $(LIBFT_PATH)
						make clean -C $(MLX_PATH)

fclean:				clean
						@echo "Cleaning all, including libft and mlx"
						@$(RM) $(NAME)
						@$(RM) -rf $(OBJDIR)
						@$(RM) -rf $(LIBFT_PATH)
						@$(RM) -rf $(MLX_PATH)

re:					fclean all

.PHONY: all clean fclean re
