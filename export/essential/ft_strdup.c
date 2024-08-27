/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:12:51 by sperron           #+#    #+#             */
/*   Updated: 2024/08/14 00:21:19 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential.h"

char	*ft_strdup(const char *s)
{
	char	*renv;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	renv = (char *)malloc(ft_strlen((char *)s) + 1);
	if (renv == NULL)
		return (NULL);
	while (s[i])
	{
		renv[i] = s[i];
		i++;
	}
	renv[i] = '\0';
	return (renv);
}

// int main(void)
// {
//     printf("%s", ft_strdup("test"));
//     printf("\n");
//     printf("%s", strdup("test"));
//     printf("\n");
//     return (0);
// }