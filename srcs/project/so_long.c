/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:42:19 by sperron           #+#    #+#             */
/*   Updated: 2024/08/24 17:21:07 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (bad_message("Error"), ft_printf("\n"), 1);
	data.img_backg = NULL;
	data.img_colect = NULL;
	data.img_exit = NULL;
	data.img_wall = NULL;
	data.img_player = NULL;
	data.win_ptr = NULL;
	data.map = read_map(av[1]);
	data.map_copy = read_map(av[1]);
	if (map_checker(&data) && !verify_win(&data) && argv_checker(av[1]))
		return (game_init(&data), gameplay(&data), mlx_loop(data.mlx_ptr), 0);
	else if (data.map)
		return (free_map(data.map), free_map(data.map_copy),
			bad_message("Error"), ft_printf("\n"), 1);
	else
		return (bad_message("Error"), ft_printf("\n"), 1);
}
