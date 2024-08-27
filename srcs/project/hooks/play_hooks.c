/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:39:43 by sperron           #+#    #+#             */
/*   Updated: 2024/08/06 20:07:28 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	game_events(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		data->y_player -= 1;
		player_w(data);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		data->y_player += 1;
		player_s(data);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->x_player += 1;
		player_d(data);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		data->x_player -= 1;
		player_a(data);
	}
}

static int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY || keycode == KEY_Q)
		close_game(data);
	else if (!data->endgame)
	{
		game_events(keycode, data);
		ft_printf("%MMoves: %d%r\n", data->moves);
	}
	if (data->endgame)
		return (ft_printf("%GYOU WIN !%r\n%YMoves total : %d%r\n", data->moves),
			close_game(data), 0);
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_game, data);
	mlx_hook(data->win_ptr, 9, 1L << 21, map_draw, data);
}
