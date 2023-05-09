/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:33:46 by akharraz          #+#    #+#             */
/*   Updated: 2023/05/08 17:24:07 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void draw_player(t_data *img, t_map *map)
{
	for (int x = 0; x < 10; x++)
		my_mlx_pixel_put(img, (map->p_pos.x * FS + (cos(map->p_pos.ang)) * x), map->p_pos.y * FS + (sin(map->p_pos.ang) * x), 0x2271b3);
}

void draw_grid(t_data *img, int i, int j, t_map *map)
{
	int colour;
	int x, y;

	colour = 0x00FFFFFF;
	x = 0;
	if (map->map[j][i] == '1')
		colour = 0x00C0F000;
	while (x < FS - 1)
	{
		y = 0;
		while (y < FS - 1)
		{
			my_mlx_pixel_put(img, i * FS + x, j * FS + y, colour);
			y++;
		}
		x++;
	}
}

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

void DDA(int X0, int Y0, int X1, int Y1, t_data *data)
{
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(data, round(X), round(Y), 0xFF0000);
		X += Xinc; // increment in x at each step
		Y += Yinc; // increment in y at each step
	}
}

void	paint(t_map *map, t_data *img, int len, int start, t_ray ray, int wid_i)
{
	int	off_x;
	int	off_y;
	int	i;

	if (ray.inter == HORIZONTAL_INTER)
		off_x = (ray.x - (int)ray.x) * map->so.w;
	else
		off_x = (ray.y - (int)ray.y) * map->so.w;
	i = start;
	while (i < len && i < HIGHT)
	{
		off_y = ((i - start) / (double)(len - start)) * map->so.h;
		if (i >= 0)
			my_mlx_pixel_put(img, wid_i, i, map->so.addr[((map->so.h * off_y) + off_x)]);
		i++;
	}
}

void	project(t_ray ray, int wid_i, t_data *img, t_map *map)
{
	double	proj_wall_h;
	int		i;
	int 	len;
	int		j;

	j = -1;
	ray.diatance = ray.diatance * cos(map->p_pos.ang - ray.angle);
	proj_wall_h = (1 * ((WIDTH / 2) / FS) / ray.diatance) * FS;
	i = ((HIGHT) - (proj_wall_h)) / 2;
	len = (proj_wall_h) + i;
	while (++j < i)
		my_mlx_pixel_put(img, wid_i, j, map->c_col);
	// while (i < len && i < HIGHT)
	// {
	// 	my_mlx_pixel_put(img, wid_i, i, 0xFF00);
	// 	i++;
	// }
	(void)map;
	paint(map,img, len, i, ray, wid_i);
	// len--;
	while (len++ < HIGHT)
		my_mlx_pixel_put(img, wid_i, len, map->f_col);
}

int draw_map(t_map *map)
{
	t_data img;

	move(map);
	img.img = mlx_new_image(map->mlx.mlx, WIDTH, HIGHT);
	img.addr = (unsigned int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
										&img.endian);
	cast(map, &img);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img.img, 0, 0);
	mlx_destroy_image(map->mlx.mlx, img.img);
	return (0);
}
