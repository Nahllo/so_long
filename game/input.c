/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:16:18 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:16:19 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	pick_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

void	effect_anim(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
