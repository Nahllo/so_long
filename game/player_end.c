/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:16:53 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:16:54 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}
