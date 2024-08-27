/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:29:52 by sperron           #+#    #+#             */
/*   Updated: 2024/07/24 16:04:36 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential_printf.h"

int	ft_puthexa(char form, long double nbr)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = NULL;
	if (form == 'x')
		hexa = "0123456789abcdef";
	else if (form == 'X')
		hexa = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= 16)
		count += ft_puthexa(form, ((unsigned long) nbr / 16));
	ft_putchar(hexa[(unsigned long)nbr % 16]);
	count++;
	return (count);
}
