/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:15:41 by sminna            #+#    #+#             */
/*   Updated: 2021/11/03 20:38:13 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_for_init_game(t_game *game)
{
	game->size = 64;
	game->sit = 0;
	game->frame = 0;
	game->enemy_ww.x = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_size.x * game->size, \
	game->map_size.y * game->size, "./so-long");
	game->img = mlx_new_image(game->mlx, game->map_size.x * game->size, \
	game->map_size.y * game->size);
	game->element.grass = mlx_xpm_file_to_image(game->mlx, "texture/grass.xpm", \
	&game->size, &game->size);
	game->element.wall = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", \
	&game->size, &game->size);
	game->element.exit = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", \
	&game->size, &game->size);
	game->element.coin = mlx_xpm_file_to_image(game->mlx, "texture/coin.xpm", \
	&game->size, &game->size);
	game->element.man = mlx_xpm_file_to_image(game->mlx, "texture/man1.xpm", \
	&game->size, &game->size);
	game->element.man_sit = mlx_xpm_file_to_image(game->mlx, \
	"texture/man2.xpm", &game->size, &game->size);
	game->element.enemy = mlx_xpm_file_to_image(game->mlx, "texture/enemy.xpm", \
	&game->size, &game->size);
	ft_check_enemyw(game, 0, 0, 0);
	ft_check_enemyz(game, 0, 0, 0);
}

int	game_close(t_game *game)
{
	int	y;

	y = 0;
	write(1, "Window closed!\n", 15);
	while (y < game->map_size.y)
	{
		free(game->map[y]);
		y++;
	}
	free (game->map);
	free (game);
	exit(0);
	return (0);
}

void	move(t_game *game, int y, int x)
{
	int	xx;
	int	yy;

	xx = game->position.x + x;
	yy = game->position.y + y;
	if (game->map[yy][xx] == '1')
		return ;
	if (game->map[yy][xx] == 'C')
	{
		game->coin_count.x++;
		game->map[yy][xx] = '0';
	}
	if (game->map[yy][xx] == 'E' && game->coin_count.x == game->coin_count.y)
		game_close(game);
	if ((game->map[yy][xx] == 'E' && game->coin_count.x != game->coin_count.y))
		return ;
	if (game->map[yy][xx] == 'X')
		game_close(game);
	draw_the_element(*game, game->element.grass, game->position.y, \
	game->position.x);
	game->position.x = xx;
	game->position.y = yy;
	game->count++;
	counter_for_step(game);
}

int	key_press_cheker(int keycode, t_game *game)
{
	if (keycode == 53)
		game_close(game);
	if (keycode == 13)
		move(game, -1, 0);
	if (keycode == 1)
		move(game, 1, 0);
	if (keycode == 0)
		move(game, 0, -1);
	if (keycode == 2)
		move(game, 0, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;

	i = 0;
	if (argc == 1)
		write (1, "Map name pls)\n", 14);
	if (argc == 1)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		exit(0);
	read_map(argv[1], game);
	if (!(check_map(game)))
		game_close(game);
	ft_for_init_game(game);
	draw_the_map(*game, 0, 0);
	mlx_hook(game->win, 2, 1L << 0, key_press_cheker, game);
	mlx_hook(game->win, 17, 1L << 0, game_close, game);
	mlx_loop_hook(game->mlx, render_pers, game);
	mlx_loop(game->mlx);
}
