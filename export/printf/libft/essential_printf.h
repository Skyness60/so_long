/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:09:26 by sperron           #+#    #+#             */
/*   Updated: 2024/07/24 16:04:24 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESSENTIAL_PRINTF_H
# define ESSENTIAL_PRINTF_H
# include <unistd.h> // write
# include <stdlib.h> // malloc size_t
# include <stdbool.h> // bool

// function for printf

int				ft_putchar(char c);
int				ft_puthexa(char form, long double nbr);
int				ft_putnbr(int n);
int				ft_putnbr_unsigned(unsigned int n);
int				ft_putstr(char *str);
int				ft_putpointer(void *adress);
#endif