/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essential.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:14:36 by sperron           #+#    #+#             */
/*   Updated: 2024/08/20 21:50:01 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESSENTIAL_H
# define ESSENTIAL_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
char	**ft_split(char const *s, char *c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
int		ft_intstrlen(const char *str);
#endif
