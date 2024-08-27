/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:08:47 by sperron           #+#    #+#             */
/*   Updated: 2024/08/06 16:12:34 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/essential_printf.h"

static	int	print_color(char form)
{
	if (form == 'r')
		return (ft_putstr("\033[0m"));
	else if (form == 'R')
		return (ft_putstr("\033[31m"));
	else if (form == 'G')
		return (ft_putstr("\033[32m"));
	else if (form == 'Y')
		return (ft_putstr("\033[33m"));
	else if (form == 'B')
		return (ft_putstr("\033[34m"));
	else if (form == 'M')
		return (ft_putstr("\033[35m"));
	else if (form == 'C')
		return (ft_putstr("\033[36m"));
	return (0);
}

static int	conv(char form, va_list args)
{
	if (form == 'c')
		return (ft_putchar((char) va_arg(args, int)));
	else if (form == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (form == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (form == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (form == 'x' || form == 'X')
		return (ft_puthexa(form, va_arg(args, unsigned int)));
	else if (form == '%')
		return (ft_putchar('%'));
	else if (print_color(form) != 0)
		return (print_color(form));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		nb;

	va_start(args, format);
	i = 0;
	nb = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			nb += conv(format[i++ + 1], args);
		else
			nb += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), nb);
}
