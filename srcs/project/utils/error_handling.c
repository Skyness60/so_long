/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:50:24 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 00:35:09 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	bad_message(const char *message)
{
	ft_printf("%R%s%r", message);
	return (EXIT_FAILURE);
}

void	puterror(const char *message)
{
	ft_printf("%R%s%r", message);
	exit(EXIT_FAILURE);
}
