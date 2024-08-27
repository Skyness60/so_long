/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:43:52 by sperron           #+#    #+#             */
/*   Updated: 2024/07/24 16:04:36 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential_printf.h"

static int	ft_printadress(const unsigned long n)
{
	if (n / 16)
		return (ft_printadress(n / 16) + ft_printadress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}

int	ft_putpointer(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_printadress((unsigned long) adress));
}
