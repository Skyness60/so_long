/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:47:16 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 17:12:13 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	player_update_image(char key, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (key == 'w')
		data->img_player = mlx_xpm_file_to_image
			(data->mlx_ptr, "assets/images/PD.xpm", &data->img_w, &data->img_h);
	else if (key == 's')
		data->img_player = mlx_xpm_file_to_image
			(data->mlx_ptr, "assets/images/PA.xpm", &data->img_w, &data->img_h);
	else if (key == 'd')
		data->img_player = mlx_xpm_file_to_image
			(data->mlx_ptr, "assets/images/PD.xpm", &data->img_w, &data->img_h);
	else if (key == 'a')
		data->img_player = mlx_xpm_file_to_image
			(data->mlx_ptr, "assets/images/PA.xpm", &data->img_w, &data->img_h);
	if (data->img_player == NULL)
	{
		ft_printf("%RError images\n%r");
		close_game(data);
	}
}

void	player_w(t_data *data)
{
	player_update_image('w', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->n_colect == 0)
	{
		data->map[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->y_player += 1;
	else
	{
		if (data->map[data->y_player][data->x_player] == 'C')
			data->n_colect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_s(t_data *data)
{
	player_update_image('s', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->n_colect == 0)
	{
		data->map[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->y_player -= 1;
	else
	{
		if (data->map[data->y_player][data->x_player] == 'C')
			data->n_colect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_d(t_data *data)
{
	player_update_image('d', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->n_colect == 0)
	{
		data->map[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->x_player -= 1;
	else
	{
		if (data->map[data->y_player][data->x_player] == 'C')
			data->n_colect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_a(t_data *data)
{
	player_update_image('a', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->n_colect == 0)
	{
		data->map[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->x_player += 1;
	else
	{
		if (data->map[data->y_player][data->x_player] == 'C')
			data->n_colect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		map_draw(data);
	}
}
