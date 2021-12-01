NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

NAME = so_long.out

SRC = $(MAIN_SRC) $(SRC_GNL) $(SRC_MAP) $(SRC_GAME)

OBJ = $(SRC:.c=.o)


MAIN_SRC = main.c errors.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))

MAP =		map_reader.c \
			map_checker.c \
			tilemap_generator.c \
			enemy_generator.c
SRC_MAP = $(addprefix map/, $(MAP))

NOBONUS = map_checker_utils.c
SRC_NOBONUS = $(addprefix map/, $(NOBONUS))
NOBONUS_OBJS = $(SRC_NOBONUS:.c=.o)

BONUS =	map_checker_utils_bonus.c
SRC_BONUS = $(addprefix map/, $(BONUS))
BONUS_OBJS = $(SRC_BONUS:.c=.o)

GAME =	game_init.c \
		open_images.c \
		open_wall_images.c open_panel.c \
		input.c \
		player_movement.c \
		player_end.c \
		update.c \
		enemy_behaviour.c \
		follower_behaviour.c \
		render.c draw_wall.c \
		reset.c end_program.c
SRC_GAME = $(addprefix game/, $(GAME))

FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit


$(NAME): $(OBJ) $(NOBONUS_OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making minilibx..." $(NONE)
	@cd minilibx/ && make
	@cp minilibx/libmlx.dylib ./libmlx.dylib
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(NOBONUS_OBJS) $(LIBFT) $(INCLUDE) -L./minilibx -lmlx -L./minilibx -lmlx -o  $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making minilibx..." $(NONE)
	@cd minilibx/ && make
	@cp minilibx/libmlx.dylib ./libmlx.dylib
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(BONUS_OBJS) $(LIBFT) $(INCLUDE) -L./minilibx -lmlx -L./minilibx -lmlx -o  $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)


clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@cd minilibx/ && make clean && cd ../
	@rm -rf $(OBJ)
	@rm -rf $(NOBONUS_OBJS)
	@rm -rf $(BONUS_OBJS)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - Removing minilibx..." $(NONE)
	@rm -rf libmlx.dylib
	@make -C $(LIBF_DIR) fclean

re: fclean all

.PHONY: all re fclean clean bonus

.SILENT: $(OBJ) $(NOBONUS_OBJS) $(BONUS_OBJS)
