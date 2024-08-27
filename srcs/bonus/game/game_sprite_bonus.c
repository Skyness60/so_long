/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:47:20 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 10:35:37 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	spritespd(t_data *data)
{
	if (data->alt_frame == 0)
	{
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"assets/images/PD.xpm", &data->img_w, &data->img_h);
		data->alt_frame = 1;
	}
	else
	{
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"assets/images/PD2.xpm", &data->img_w, &data->img_h);
		data->alt_frame = 0;
	}
}

static void	spritespa(t_data *data)
{
	if (data->alt_frame == 0)
	{
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"assets/images/PA.xpm", &data->img_w, &data->img_h);
		data->alt_frame = 1;
	}
	else
	{
		data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				"assets/images/PA2.xpm", &data->img_w, &data->img_h);
		data->alt_frame = 0;
	}
}

int	sprites(t_data *data)
{
	if (data->loop < 20000)
		return (data->loop++, 0);
	data->loop = 0;
	mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->player_state == 1)
		spritespd(data);
	else if (data->player_state == 2)
		spritespa(data);
	return (map_draw(data), 0);
}
