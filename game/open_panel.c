/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:16:41 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:16:45 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	color_panel(t_panel *panel, t_color color)
{
	int	x;
	int	y;

	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp,
			&panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
			x += 1;
		}
		y += 1;
	}
}

void	*new_panel(t_game *game, t_color color)
{
	t_panel	panel;

	panel.pointer = mlx_new_image(game->mlx,
			game->wndw_size.x, game->wndw_size.y);
	panel.size.x = game->wndw_size.x;
	panel.size.y = game->wndw_size.y;
	color_panel(&panel, color);
	return (panel.pointer);
}
