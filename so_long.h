/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:14:00 by sminna            #+#    #+#             */
/*   Updated: 2021/11/03 20:38:59 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_xy {
	int		x;
	int		y;
}				t_xy;

typedef struct s_elements {
	void	*grass;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*man;
	void	*man_sit;
	void	*enemy;
}				t_elements;

typedef struct s_game {
	int			frame;
	int			sit;
	t_xy		position;
	void		*point;
	void		*mlx;
	void		*win;
	void		*img;
	void		*grass;
	t_elements	element;
	int			size;
	int			count;
	t_xy		map_size;
	char		**map;
	t_xy		coin_count;
	t_xy		enemy_w;
	t_xy		enemy_ww;
	t_xy		enemy_z;
}				t_game;

int		key_press_cheker(int keycode, t_game *game);
void	move(t_game *game, int y, int x);
int		game_close(t_game *game);
void	ft_for_init_game(t_game *game);
void	draw_the_element(t_game game, void *element, int i, int l);
void	draw_the_map(t_game game, int y, int x);
void	read_map(char *argv, t_game *game);
void	enemy_movew(t_game *game);
void	enemy_movez(t_game *game);
int		render_pers(t_game *game);
int		ft_strlen_for_game(const char *c);
int		ft_check_rectangle(t_game *game);
int		ft_check_hole(t_game *game);
int		ft_check_characters(t_game *game, int x, int y);
int		ft_check_exit(t_game *game, int x, int y, int c);
int		check_map(t_game *game);
int		ft_check_pers(t_game *game, int x, int y, int p);
void	ft_check_enemyw(t_game *game, int x, int y, int w);
void	ft_check_enemyz(t_game *game, int x, int y, int z);
void	enemy_movew_patr(t_game *game);
void	enemy_movez_part(t_game *game);
char	*get_next_line(int fd);
void	ft_count_spec_for_solong(t_game *game, char *argv);
int		game_close_light(t_game *game);
char	*ft_itoa(int n);
void	counter_for_step(t_game *game);

#endif
