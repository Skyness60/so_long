/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:32:29 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 16:17:57 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	img_init(t_data *data)
{
	data->img_backg = mlx_xpm_file_to_image
		(data->mlx_ptr, "assets/images/0.xpm", &data->img_w, &data->img_h);
	if (data->img_backg == NULL)
		close_game(data);
	data->img_wall = mlx_xpm_file_to_image
		(data->mlx_ptr, "assets/images/1.xpm", &data->img_w, &data->img_h);
	if (data->img_wall == NULL)
		close_game(data);
	data->img_player = mlx_xpm_file_to_image
		(data->mlx_ptr, "assets/images/PD.xpm", &data->img_w, &data->img_h);
	if (data->img_player == NULL)
		close_game(data);
	data->img_colect = mlx_xpm_file_to_image
		(data->mlx_ptr, "assets/images/C.xpm", &data->img_w, &data->img_h);
	if (data->img_colect == NULL)
		close_game(data);
	data->img_exit = mlx_xpm_file_to_image
		(data->mlx_ptr, "assets/images/E1.xpm", &data->img_w, &data->img_h);
	if (data->img_exit == NULL)
		close_game(data);
}

static void	size_window_init(t_data *data)
{
	int	i;

	data->map_w = ft_strlen(data->map[0]) * 32;
	i = 0;
	while (data->map[i] != NULL)
		i++;
	data->map_h = i * 32;
}

void	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		close_game(data);
	size_window_init(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_w, data->map_h, "so_long");
	if (!data->win_ptr)
		close_game(data);
	data->moves = 0;
	data->endgame = 0;
	img_init(data);
	map_draw(data);
}
