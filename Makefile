NAME = so_long

CC = cc -g3

SOURCES =	srcs/project/so_long.c \
			srcs/project/hooks/key_hooks.c \
			srcs/project/hooks/play_hooks.c \
			srcs/project/hooks/window_hooks.c \
			srcs/project/game/game_exit.c \
			srcs/project/game/game_init.c \
			srcs/project/game/game_map.c \
			srcs/project/game/game_draw.c \
			srcs/project/game/game_player.c \
			srcs/project/utils/error_handling.c \
			srcs/project/utils/arguments.c \
			srcs/project/maps/checkers/map.c \
			srcs/project/maps/checkers/is_win.c \
			srcs/project/maps/free/free_map.c \
			export/gnl/get_next_line.c \
			export/gnl/get_next_line_utils.c \
			export/essential/ft_itoa.c \
			export/essential/ft_split.c \
			export/essential/ft_intstrlen.c \
			export/essential/ft_strdup.c \
			export/printf/libft/ft_putchar.c \
			export/printf/libft/ft_puthexa.c \
			export/printf/libft/ft_putstr.c \
			export/printf/libft/ft_putpointer.c \
			export/printf/libft/ft_putnbr.c \
			export/printf/libft/ft_putnbr_unsigned.c \
			export/printf/srcs/ft_printf.c \

MLX_PATH = ./mlx/

MINI_LIBX = MiniLibX

MLX_FLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm

OBJECTS = $(SOURCES:.c=.o)
D_FILES = $(SOURCES:.c=.d)

BONUS_SOURCES =	srcs/bonus/so_long_bonus.c \
				srcs/bonus/hooks/key_hooks_bonus.c \
				srcs/bonus/hooks/play_hooks_bonus.c \
				srcs/bonus/hooks/window_hooks_bonus.c \
				srcs/bonus/game/game_exit_bonus.c \
				srcs/bonus/game/game_init_bonus.c \
				srcs/bonus/game/game_map_bonus.c \
				srcs/bonus/game/game_lose_bonus.c \
				srcs/bonus/game/game_draw_bonus.c \
				srcs/bonus/game/game_display_bonus.c \
				srcs/bonus/game/game_player_bonus.c \
				srcs/bonus/game/game_sprite_bonus.c \
				srcs/bonus/utils/error_handling_bonus.c \
				srcs/bonus/utils/arguments_bonus.c \
				srcs/bonus/maps/checkers/map_bonus.c \
				srcs/bonus/maps/checkers/is_win_bonus.c \
				srcs/bonus/maps/free/free_map_bonus.c \
				export/gnl/get_next_line.c \
				export/gnl/get_next_line_utils.c \
				export/essential/ft_itoa.c \
				export/essential/ft_split.c \
				export/essential/ft_intstrlen.c \
				export/essential/ft_strdup.c \
				export/printf/libft/ft_putchar.c \
				export/printf/libft/ft_puthexa.c \
				export/printf/libft/ft_putstr.c \
				export/printf/libft/ft_putpointer.c \
				export/printf/libft/ft_putnbr.c \
				export/printf/libft/ft_putnbr_unsigned.c \
				export/printf/srcs/ft_printf.c \

D_FILES_BONUS = $(BONUS_SOURCES:.c=.d)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

FLAGS = -Wall -Wextra -Werror -MMD -MP
OPTIONS = -c

#################################################################################

RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
PURPLE = '\033[0;35m'
NC = '\033[0m'

#################################################################################

%.o: %.c
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo $(GREEN)✅ $< compiled! $(NC)

$(NAME): $(OBJECTS) 
	@echo "$(BLUE)Building $(MINI_LIBX)..."
	@make -C $(MLX_PATH) --no-print-directory
	@echo $(GREEN)✅ MiniLibX built successfully!$(NC)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -L$(MLX_PATH) $(MLX_FLAGS)
	@echo $(BLUE)✅ $@ built! $(NC)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	@echo "$(BLUE)Building $(MINI_LIBX)..."
	make -C $(MLX_PATH) --no-print-directory
	@echo $(GREEN)✅ MiniLibX built successfully!$(NC)
	@$(CC) $(FLAGS) $(BONUS_OBJECTS) -o $(NAME) -L$(MLX_PATH) $(MLX_FLAGS)
	@echo $(PURPLE)✅ $(NAME) with bonus built! $(NC)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(D_FILES) $(D_FILES_BONUS)
	@make clean -C ${MLX_PATH} --no-print-directory
	@echo $(YELLOW)🗑️ $(OBJECTS) $(BONUS_OBJECTS) deleted! $(NC)

fclean: clean
	@rm -f $(NAME) $(BONUS) $(D_FILES) $(D_FILES_BONUS)
	@echo $(RED)🗑️ $(NAME) and $(BONUS) deleted! $(NC)

re: fclean all

sinclude $(D_FILES) $(D_FILES_BONUS)

.PHONY: all clean fclean re
