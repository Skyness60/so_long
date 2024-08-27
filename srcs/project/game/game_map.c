/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:09:09 by sperron           #+#    #+#             */
/*   Updated: 2024/08/21 10:27:22 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	is_dir(char *path)
{
	char	buf[1];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, buf, 1) == -1)
		return (close(fd), 1);
	return (close(fd), 0);
}

static char	*read_map2(char *holder)
{
	char	*str;

	if (holder[0] == '\n')
	{
		str = holder;
		holder = ft_strjoin(str, "Q");
		free(str);
	}
	return (holder);
}

static void	free_memory(int fd, char *holder, char *holder_map)
{
	close(fd);
	free(holder);
	free(holder_map);
}

static char	*accumulate_lines(int fd)
{
	char	*line;
	char	*holder;
	char	*holder_map;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	holder_map = ft_strdup(line);
	free(line);
	while (true)
	{
		holder = get_next_line(fd);
		if (!holder)
			break ;
		holder = read_map2(holder);
		line = ft_strjoin(holder_map, holder);
		free(holder_map);
		free(holder);
		holder_map = line;
		if (!holder_map)
			return (NULL);
	}
	return (holder_map);
}

char	**read_map(char *path)
{
	int		fd;
	char	*holder_map;
	char	**map;

	fd = open(path, O_RDONLY);
	if (is_dir(path) == 1)
		return (close(fd), NULL);
	holder_map = accumulate_lines(fd);
	if (!holder_map)
		return (close(fd), NULL);
	map = ft_split(holder_map, "\n");
	if (!map || !map[0] || map[0][0] == '\0')
		return (free_memory(fd, NULL, holder_map), free_map(map), NULL);
	free_memory(fd, NULL, holder_map);
	return (map);
}
