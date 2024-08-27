/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_win_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:14:56 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 14:24:27 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

void	flood_fill(t_data *data, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0
		|| data->map_copy[move_x][move_y] == '1'
				|| data->map_copy[move_x][move_y] == 'X'
					|| data->map_copy[move_x][move_y] == 'E')
		return ;
	data->map_copy[move_x][move_y] = 'X';
	flood_fill(data, move_x - 1, move_y);
	flood_fill(data, move_x + 1, move_y);
	flood_fill(data, move_x, move_y - 1);
	flood_fill(data, move_x, move_y + 1);
}

static int	b(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map_copy[row])
	{
		col = 0;
		while (data->map_copy[row][col])
		{
			if (data->map_copy[row][col] == 'E')
			{
				if ((row == 0 || data->map_copy[row - 1][col] == '1') &&
						(col == 0 || data->map_copy[row][col - 1] == '1') &&
							(data->map_copy[row + 1] == NULL ||
								data->map_copy[row + 1][col] == '1') &&
									(data->map_copy[row][col + 1] == '1'))
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	ft_to_fill(t_data *data, int move_x, int move_y)
{
	flood_fill(data, move_x, move_y);
}

void	ft_player_position(t_data *data, int *pl_row, int *pl_colun)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_copy[i])
	{
		j = 0;
		while (data->map_copy[i][j])
		{
			if (data->map_copy[i][j] == 'P')
			{
				*pl_row = i;
				*pl_colun = j;
			}
			j++;
		}
		i++;
	}
}

int	verify_win(t_data *data)
{
	int		pl_row;
	int		pl_colun;
	int		can_row;
	int		can_colun;

	pl_colun = 0;
	pl_row = 0;
	can_row = 0;
	ft_player_position(data, &pl_row, &pl_colun);
	ft_to_fill(data, pl_row, pl_colun);
	while (data->map_copy[can_row])
	{
		can_colun = 0;
		while (data->map_copy[can_row][can_colun])
		{
			if (b(data) || (data->map_copy[can_row][can_colun] == 'C'
				|| (data->map_copy[can_row][can_colun] == 'E'
				&& data->map_copy[can_row][can_colun] == 'X'
						&& data->n_colect == 0)))
				return (1);
			can_colun++;
		}
		can_row++;
	}
	return (0);
}
