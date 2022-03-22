/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:44:25 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/22 23:44:32 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void    put_points(int fd, size_t width, size_t height)
{
    char        *line;
    char        **map;
    t_coords    coords;
    size_t      i;
    size_t      j;

    line = "";
    i = 0;
    j = 0;
    while (line != NULL)
    {
        line = get_next_line(fd, BUFFER_SIZE);
        map = ft_split(line, ' ');
        coords.y = j * map_size(height, map[j]);
        while (convert[i])
            {
                coords.x = i * map_size(width, map[j]);
                my_mlx_pixel_put(&img, coords.x, coords.y, 0x00FF0000);
                i++;
            }
        j++;
    }
}

size_t  map_size(size_t length, char *line)
{
    size_t  i;
    size_t  size;
    size_t  offset;

    line_size = 0;
    while (line[line_size])
        line_size++;
    offset = (length / (line_size * 2)) / 2;
    size = length / (line_size * 2) + offset;
    return (size);
}