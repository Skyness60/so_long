/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:55:16 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 17:10:13 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

#define BG_COLOR 0x000000
#define RECT_WIDTH 100
#define RECT_HEIGHT 20
#define TEXT_X 25
#define TEXT_Y 15

static void	draw_rect(void *mlx_ptr, void *win_ptr, int i)
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	img = mlx_new_image(mlx_ptr, RECT_WIDTH, RECT_HEIGHT);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (i < RECT_WIDTH * RECT_HEIGHT)
	{
		((int *)data)[i] = BG_COLOR;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, TEXT_X,
		TEXT_Y - RECT_HEIGHT);
	mlx_destroy_image(mlx_ptr, img);
}

void	display_moves(t_data *data)
{
	char	*moves;
	int		i;

	i = 0;
	draw_rect(data->mlx_ptr, data->win_ptr, i);
	mlx_string_put(data->mlx_ptr, data->win_ptr, TEXT_X,
		TEXT_Y, 0xededed, "Moves: ");
	moves = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		TEXT_X + 45, TEXT_Y, 0xededed, moves);
	free(moves);
}
