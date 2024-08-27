/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:32:32 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 13:33:42 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	close_game(t_data *data)
{
	if (data->map != NULL)
		free_map(data->map);
	if (data->map_copy != NULL)
		free_map(data->map_copy);
	if (data->img_backg != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_backg);
	if (data->img_wall != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
	if (data->img_player != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->img_colect != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_colect);
	if (data->img_exit != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
