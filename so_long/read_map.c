/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:10:20 by klemongr          #+#    #+#             */
/*   Updated: 2022/03/10 23:59:27 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *path_to_map)
{
	int	i;

	i = 0;
	if (!path_to_map || !*path_to_map)
		return (0);
	while (path_to_map[i])
		i++;
	return (ft_strcmp(&path_to_map[i - 4], ".ber"));
}

char	*read_map_from_file(int fd)
{
	char	*tmp;
	char	*result;
	char	str[BUFFER_SIZE + 1];
	int		num_of_read;

	result = malloc(1);
	if (!result)
		return (NULL);
	*result = 0;
	num_of_read = 1;
	while (num_of_read)
	{
		num_of_read = read(fd, str, BUFFER_SIZE);
		str[num_of_read] = 0;
		tmp = result;
		result = ft_strjoin(result, str);
		free(tmp);
	}
	return (result);
}

char	**read_map(char *path_to_map)
{
	char	**result;
	char	*str;
	int		fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!check_extension(path_to_map))
	{
		write(2, "Map description file ending with the .ber extension.\n", 54);
		return (NULL);
	}
	str = read_map_from_file(fd);
	result = ft_split(str, '\n');
	if (!str || !result)
	{
		write(2, "Error read map\n", 16);
		free(str);
		free_split(result);
		return (NULL);
	}
	free(str);
	return (result);
}
