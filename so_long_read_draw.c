/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:47:16 by sminna            #+#    #+#             */
/*   Updated: 2021/11/04 20:25:49 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_the_element(t_game game, void *element, int i, int l)
{
	i = i * (game.size);
	l = l * (game.size);
	mlx_put_image_to_window(game.mlx, game.win, element, l, i);
}

void	draw_the_map(t_game game, int y, int x)
{
	while (y < game.map_size.y)
	{
		x = 0;
		while (x < game.map_size.x)
		{
			draw_the_element(game, game.element.grass, y, x);
			if (game.map[y][x] == '1')
				draw_the_element(game, game.element.wall, y, x);
			if (game.map[y][x] == 'C')
				draw_the_element(game, game.element.coin, y, x);
			if (game.map[y][x] == 'E')
				draw_the_element(game, game.element.exit, y, x);
			if (game.map[y][x] == 'P')
				draw_the_element(game, game.element.man, y, x);
			if (game.map[y][x] == 'X')
				draw_the_element(game, game.element.enemy, y, x);
			x++;
		}
		y++;
	}
}

int	ft_check_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] != '.')
		i++;
	if (argv[i] == '.' && argv[i + 1] && argv[i + 2] \
	&& argv[i + 3] && !argv[i + 4])
		if (argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i + 3] == 'r')
			return (1);
	return (0);
}

void	ft_count_spec_for_solong(t_game *game, char *argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	fd = open(argv, O_RDONLY);
	while (i)
	{
		str = get_next_line(fd);
		if (str == NULL && game->map_size.y == 0)
		{
			write(1, "Error - empty file\n", 19);
			free (game);
			exit(0);
		}
		if (str)
		{
			game->map_size.y++;
			free (str);
		}
		else
			i = 0;
	}
	close(fd);
}

void	read_map(char *argv, t_game *game)
{
	int	l;
	int	fd;

	game->map_size.y = 0;
	l = 0;
	if (!ft_check_ber(argv))
	{
		write(1, "Error - not ber\n", 16);
		free (game);
		exit(0);
	}
	ft_count_spec_for_solong(game, argv);
	fd = open(argv, O_RDONLY);
	game->map = malloc (game->map_size.y * (sizeof(char **)));
	if (!game->map)
		game_close_light(game);
	while (l < game->map_size.y)
	{
		game->map[l] = get_next_line(fd);
		l++;
	}
	close(fd);
}
