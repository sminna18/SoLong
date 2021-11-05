/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_pers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:15:00 by sminna            #+#    #+#             */
/*   Updated: 2021/11/01 17:36:10 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_pers(t_game *game, int x, int y, int p)
{
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (game->map[y][x] == 'P')
			{
				p++;
				game->position.x = x;
				game->position.y = y;
			}
			x++;
		}
		y++;
	}
	if (p != 1)
	{
		write(1, "Error - pers\n", 13);
		return (0);
	}
	return (1);
}

void	ft_check_enemyw(t_game *game, int x, int y, int w)
{
	game->enemy_w.x = -1;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (game->map[y][x] == 'W')
			{
				w++;
				game->enemy_w.x = x;
				game->enemy_w.y = y;
			}
			x++;
		}
		y++;
	}
	if (w > 1)
	{
		write(1, "Error - enemy_w\n", 16);
		game_close(game);
	}
}

void	ft_check_enemyz(t_game *game, int x, int y, int z)
{
	game->enemy_z.x = -1;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (game->map[y][x] == 'Z')
			{
				z++;
				game->enemy_z.x = x;
				game->enemy_z.y = y;
			}
			x++;
		}
		y++;
	}
	if (z > 1)
	{
		write(1, "Error - enemy_z\n", 16);
		game_close(game);
	}
}
