/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:44:25 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/22 16:16:49 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void    put_points(int fd, size_t width, size_t height)
{
    char        *line;
    char        **convert;
    t_coords    coords;
    size_t      n;

    line = "";
    coords.y = 0;
    coords.x = 0;
    while (line != NULL)
    {
        line = get_next_line(fd);
        convert = ft_split(line, ' ');
        coords.y = y * map_size(height);
        while (convert[n])
            {
                coords.x = n * map_size(width);
                my_mlx_pixel_put(&img, coords.x, coords.y, 0x00FF0000);
                n++;
            }
        coords.y++;
    }
}

size_t  map_size(size_t length)
{
    // length / (line_size * 2)
}