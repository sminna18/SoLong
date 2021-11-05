/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:05:31 by sminna            #+#    #+#             */
/*   Updated: 2021/11/04 20:13:12 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_movew_patr(t_game *game)
{
	if (game->map[game->enemy_w.y][game->enemy_w.x + 1] == '1')
		game->enemy_ww.x = 1;
	if (game->map[game->enemy_w.y][game->enemy_w.x - 1] == '1')
		game->enemy_ww.x = 0;
}

void	enemy_movew(t_game *game)
{
	enemy_movew_patr(game);
	if (game->enemy_ww.x == 0)
	{
		draw_the_element(*game, game->element.grass, \
		game->enemy_w.y, game->enemy_w.x);
		game->enemy_w.x++;
		draw_the_element(*game, game->element.enemy, \
		game->enemy_w.y, game->enemy_w.x);
		if (game->enemy_w.y == game->position.y && \
		game->enemy_w.x == game->position.x)
			game_close(game);
	}
	if (game->enemy_ww.x == 1)
	{
		draw_the_element(*game, game->element.grass, \
		game->enemy_w.y, game->enemy_w.x);
		game->enemy_w.x--;
		draw_the_element(*game, game->element.enemy, \
		game->enemy_w.y, game->enemy_w.x);
		if (game->enemy_w.y == game->position.y && \
		game->enemy_w.x == game->position.x)
			game_close(game);
	}	
}

void	enemy_movez_part(t_game *game)
{
	if (game->map[game->enemy_z.y + 1][game->enemy_z.x] == '1')
		game->enemy_ww.y = 1;
	if (game->map[game->enemy_z.y - 1][game->enemy_z.x] == '1')
		game->enemy_ww.y = 0;
}

void	enemy_movez(t_game *game)
{
	enemy_movez_part(game);
	if (game->enemy_ww.y == 0)
	{
		draw_the_element(*game, game->element.grass, \
		game->enemy_z.y, game->enemy_z.x);
		game->enemy_z.y++;
		draw_the_element(*game, game->element.enemy, \
		game->enemy_z.y, game->enemy_z.x);
		if (game->enemy_z.y == game->position.y && \
		game->enemy_z.x == game->position.x)
			game_close(game);
	}
	if (game->enemy_ww.y == 1)
	{
		draw_the_element(*game, game->element.grass, \
		game->enemy_z.y, game->enemy_z.x);
		game->enemy_z.y--;
		draw_the_element(*game, game->element.enemy, \
		game->enemy_z.y, game->enemy_z.x);
		if (game->enemy_z.y == game->position.y && \
		game->enemy_z.x == game->position.x)
			game_close(game);
	}	
}

int	render_pers(t_game *game)
{
	game->frame++;
	if (game->frame == 1000)
	{
		if (game->enemy_w.x != -1)
			enemy_movew(game);
		if (game->enemy_z.x != -1)
			enemy_movez(game);
		game->frame = 0;
		draw_the_element(*game, game->element.grass, \
		game->position.y, game->position.x);
		if (game->sit == 0)
		{
			draw_the_element(*game, game->element.man_sit, \
			game->position.y, game->position.x);
			game->sit++;
		}
		else
		{
			draw_the_element(*game, game->element.man, \
			game->position.y, game->position.x);
			game->sit--;
		}
	}
	return (0);
}
