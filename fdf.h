/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:32:53 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/25 17:05:22 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "Libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_fdf
{
	t_data	img;
	int		**map;
	char	**split_line;
	char	*line;
	size_t	width;
	size_t	height;
}				t_fdf;

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_coords;

int		event_hook(t_vars *vars);
int		key_hook(int key_code, t_vars *vars);
void	put_points(int fd, t_fdf fdf);
size_t	map_size(size_t length, char *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif