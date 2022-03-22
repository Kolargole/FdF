/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:32:06 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/22 16:06:16 by vimercie         ###   ########lyon.fr   */
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
	t_data	img;

	if (argc != 2)
		return (0);
	open(argv[1], O_RDONLY);
	if (open == -1)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	void    put_points(int fd)
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, event_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
