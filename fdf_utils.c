/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:44:25 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/25 18:52:06 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*tab_atoi(char **tab_str)
{
	int	i;
	int	size;
	int	*res;

	size = 0;
	i = 0;
	while (tab_str[size])
		size++;
	res = ft_calloc(sizeof(int), size + 1);
	while (tab_str[i])
	{
		res[i] = ft_atoi(tab_str[i]);
		i++;
	}
	return (res);
}

void	put_points(int fd, t_fdf fdf)
{
	size_t		i;
	size_t		j;

	fdf.line = "";
	i = 0;
	j = 0;
	while (fdf.line != NULL)
	{
		fdf.line = get_next_line(fd);
		fdf.split_line = ft_split(fdf.line, ' ');
		//fdf.map[i] = tab_atoi(fdf.split_line);
		tab_atoi(fdf.split_line);
		i++;
	}
}

// coords.y = j * map_size(height, map[j]);

// size_t	map_size(size_t length, char *line)
// {
// 	size_t	size;
// 	size_t	offset;
// 	size_t	line_size;

// 	line_size = 0;
// 	while (line[line_size])
// 		line_size++;
// 	offset = (length / (line_size * 2)) / 2;
// 	size = length / (line_size * 2) + offset;
// 	return (size);
// }
