/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:47:52 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 17:34:06 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

static int	is_rect(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 1;
	height = 0;
	if (!map)
		return (0);
	width = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	while (map[height] != NULL)
		height++;
	if (width > 60 || height > 31)
		return (0);
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_pec(t_data *data)
{
	int	i;
	int	j;

	data->n_colect = 0;
	data->n_player = 0;
	data->n_exit = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				data->n_player++;
			else if (data->map[i][j] == 'E')
				data->n_exit++;
			else if (data->map[i][j] == 'C')
				data->n_colect++;
			j++;
		}
		i++;
	}
	if (data->n_player != 1 || data->n_exit != 1 || data->n_colect == 0)
		return (0);
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'K')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_data *data)
{
	if (is_rect(data->map) && is_wall(data->map) && is_pec(data)
		&& is_validate(data->map))
		return (verify_win(data), 1);
	return (0);
}
