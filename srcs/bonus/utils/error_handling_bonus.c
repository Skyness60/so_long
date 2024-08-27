/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:50:24 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 00:12:40 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	bad_message(const char *message)
{
	ft_printf("%R %s %r", message);
	return (EXIT_FAILURE);
}

void	puterror(t_data *data, const char *message)
{
	ft_printf("%R%s%r", message);
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
	if (data->img_bad != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_bad);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	exit(0);
}
