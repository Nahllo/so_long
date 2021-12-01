/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:13:16 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:07:25 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "basics.h"
# include "minilibx/mlx.h"

# define IMG_SIZE 64

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F',
	NORMAL_ENEM = 'M'
}	t_enemyytpe;

typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_img;

typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

t_bool	start(t_game *game, int argc, char **argv);

t_color	new_color(int r, int g, int b, int a);
void	*new_panel(t_game *game, t_color color);

int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);

void	effect_anim(t_effect *effect, t_vector pos);
void	action_anim(t_player *player);

void	remove_player(t_game *game);
void	kill_player(t_game *game, t_vector pos);
int		reset(t_game *game);
int		end_program(t_game *game);

#endif
