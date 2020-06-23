/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 12:30:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 16:26:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_and_exit(char *line, t_data *data)
{
	free(line);
	free(data);
	exit_error(MALLOC_FAIL);
}

static char	*ft_copy_add_newline(char *line, t_data *data)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	len = ft_strlen(line);
	new_line = malloc(len + 2);
	if (!new_line)
		free_and_exit(line, data);
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = '\n';
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

static char	*ft_join_free_add_newline(char *str_map, char *line, t_data *data)
{
	char	*new_str_map;
	int		i;
	int		x;

	new_str_map = malloc(ft_strlen(str_map) + ft_strlen(line) + 2);
	if (!new_str_map)
	{
		free(str_map);
		free_and_exit(line, data);
	}
	i = 0;
	x = 0;
	while (str_map[i] != '\0')
	{
		new_str_map[i] = str_map[i];
		i++;
	}
	free(str_map);
	while (line[x] != '\0')
	{
		new_str_map[i + x] = line[x];
		x++;
	}
	free(line);
	new_str_map[i + x] = '\n';
	new_str_map[i + x + 1] = '\0';
	return (new_str_map);
}

void		parse_map(int fd, char *line, t_data *data)
{
	char	*str_map;

	str_map = ft_copy_add_newline(line, data);
	while (get_next_line(fd, &line))
		str_map = ft_join_free_add_newline(str_map, line, data);
	str_map = ft_join_free_add_newline(str_map, line, data);
	data->file.map = ft_split(str_map, '\n');
	if (!data->file.map)
	{
		free(str_map);
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
	free(str_map);
	close(fd);
}
