/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_for_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:18 by sminna            #+#    #+#             */
/*   Updated: 2021/11/03 21:03:15 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_for_game(const char *c)
{
	int	x;

	if (!c)
		return (0);
	x = 0;
	while (c[x] && (c[x] != '\n'))
		x++;
	return (x);
}

int	game_close_light(t_game *game)
{
	write(1, "Window closed!\n", 15);
	free (game);
	exit(0);
	return (0);
}

void	counter_for_step(t_game *game)
{
	char	*str;

	printf("Step №%d\n", game->count);
	draw_the_element(*game, game->element.wall, 0, 0);
	str = ft_itoa(game->count);
	if (str)
		mlx_string_put(game->mlx, game->win, 10, 10, -1, str);
	if (str)
		free (str);
}
