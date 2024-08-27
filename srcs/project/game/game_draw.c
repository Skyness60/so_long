/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:35 by sperron           #+#    #+#             */
/*   Updated: 2024/08/06 17:19:24 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	img_draw(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window
		(data->mlx_ptr, data->win_ptr, image, x * 32, y * 32);
}

static void	player_draw(t_data *data, void *image, int x, int y)
{
	data->x_player = x;
	data->y_player = y;
	img_draw(data, image, x, y);
}

static void	exit_draw(t_data *data, int x, int y)
{
	if (data->n_colect == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
		data->img_exit = mlx_xpm_file_to_image
			(data->mlx_ptr, "assets/images/E2.xpm", &data->img_w, &data->img_h);
	}
	img_draw(data, data->img_exit, x, y);
}

int	map_draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				img_draw(data, data->img_wall, x, y);
			else if (data->map[y][x] == '0')
				img_draw(data, data->img_backg, x, y);
			else if (data->map[y][x] == 'P')
				player_draw(data, data->img_player, x, y);
			else if (data->map[y][x] == 'C')
				img_draw(data, data->img_colect, x, y);
			else if (data->map[y][x] == 'E')
				exit_draw(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
