/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:54:37 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 18:00:10 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../export/skyness.h"
# include <fcntl.h>

# include <stdlib.h>
# include <stdio.h>

typedef struct s_check {
	int		pl_row;
	int		pl_col;
	int		e_access;
	int		c_blocked;
	int		p_blocked;
}			t_check;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_copy;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}			t_data;

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1080
# define ESC_KEY 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

void	game_init(t_data *data);
int		close_game(t_data *data);
int		key_hook(int keycode, t_data *data);
int		bad_message(const char *message);
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);
int		bad_message(const char *message);
char	**read_map(char *path);
int		argv_checker(char *argv);
int		map_draw(t_data *data);
void	img_draw(t_data *data, void *image, int x, int y);
void	gameplay(t_data *data);
int		map_checker(t_data *data);
void	player_w(t_data *data);
void	player_s(t_data *data);
void	player_d(t_data *data);
void	player_a(t_data *data);
void	free_map(char **map);
void	flood_fill(t_data *data, int move_x, int move_y);
void	ft_to_fill(t_data *data, int move_x, int move_y);
void	ft_player_position(t_data *data, int *pl_row, int *pl_colun);
int		verify_win(t_data *data);
void	puterror(const char *message);
#endif