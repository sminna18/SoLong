/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:19:18 by sminna            #+#    #+#             */
/*   Updated: 2021/11/01 18:12:36 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	game->map_size.x = ft_strlen_for_game(game->map[0]);
	while (i < game->map_size.y)
	{
		if (game->map_size.x != ft_strlen_for_game(game->map[i]))
		{	
			write(1, "Error - map not rectangle\n", 26);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_hole(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if ((y == 0 || y == (game->map_size.y - 1) || x == 0 \
			|| x == (game->map_size.x - 1)) && game->map[y][x] != '1')
			{
				write(1, "Error - map with hole\n", 22);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_characters(t_game *game, int x, int y)
{
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' && \
			game->map[y][x] != 'C' && game->map[y][x] != 'E' && game->map[y][x] \
			!= 'P' && game->map[y][x] != 'X' && game->map[y][x] != 'W' \
			&& game->map[y][x] != 'Z')
			{
				write(1, "Error - map with other characters\n", 35);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_exit(t_game *game, int x, int y, int c)
{
	int	e;

	e = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			if (game->map[y][x] == 'C')
				c++;
			if (game->map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	game->coin_count.y = c;
	if (c < 1 || e < 1)
	{
		write(1, "Error - exit or coin\n", 21);
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!(ft_check_rectangle(game)))
		return (0);
	if (game->map_size.y < 3 || game->map_size.x < 3)
	{
		write(1, "Error - small map\n", 18);
		return (0);
	}
	if (!(ft_check_hole(game)))
		return (0);
	if (!(ft_check_characters(game, 0, 0)))
		return (0);
	if (!(ft_check_exit(game, 0, 0, 0)))
		return (0);
	if (!(ft_check_pers(game, 0, 0, 0)))
		return (0);
	return (1);
}
