/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:32:06 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/25 18:22:44 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	event_hook(t_vars *vars)
{
	(void)vars;
	exit(0);
}

int	key_hook(int key_code, t_vars *vars)
{
	if (key_code == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		event_hook(NULL);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	vars.mlx = mlx_init();
	fdf.width = 1920;
	fdf.height = 1080;
	vars.win = mlx_new_window(vars.mlx, fdf.width, fdf.height, "FdF");
	fdf.img.img = mlx_new_image(vars.mlx, fdf.width, fdf.height);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
			&fdf.img.line_length,
			&fdf.img.endian);
	dprintf(1, "test\n");
	put_points(fd, fdf);
	dprintf(1, "test\n");
	mlx_put_image_to_window(vars.mlx, vars.win, fdf.img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, event_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
