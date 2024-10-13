/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonnus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:31 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:10:54 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	drawing_skay(t_info *info, double z)
{
	int	y;

	y = 0;
	while (y < info->point_depart)
	{
		my_mlx_pixel_put(info, z, y, info->c_color_int);
		y++;
	}
}

void	drawing_floor(t_info *info, double z)
{
	int	j;

	j = 0;
	while (info->point_depart < HEIGHT)
	{
		my_mlx_pixel_put(info, (int)z, (int)info->point_depart,
			info->f_color_int);
		info->point_depart++;
		j += info->step;
	}
}

void	draw_floor(t_info *info, double z)
{
	double	j;

	j = info->step * info->lenght;
	while (info->point_depart < HEIGHT)
	{
		drawing_all_wall(info, j);
		my_mlx_pixel_put(info, (int)z, (int)info->point_depart, info->color
			+ 10);
		info->point_depart++;
		j -= info->step;
	}
}

void	draw_wall_game(t_info *info, double z)
{
	int		var;
	double	j;

	var = info->point_depart;
	j = 0;
	if (info->point_depart < 0)
	{
		j = info->step * (-info->point_depart);
		info->point_depart = 0;
	}
	while (info->point_depart < HEIGHT && info->point_depart <= info->lenght
		+ var)
	{
		drawing_all_wall(info, j);
		my_mlx_pixel_put(info, z, info->point_depart, info->color);
		info->point_depart++;
		j += info->step;
	}
}

void	draw_vector(t_info *info)
{
	double	count;
	double	z;
	int		var;

	count = -M_PI / 6;
	z = 0;
	info->point_depart = 0;
	while (count < M_PI / 6)
	{
		conditions(info, norm(info->angle + count));
		calcul_distance(info, norm(info->angle + count));
		calcul_step(info, count);
		drawing_skay(info, z);
		draw_wall_game(info, z);
		draw_floor(info, z);
		z += 1;
		count = count + RAD / (VIEW * 2);
		info->door_flag[0] = 0;
		info->door_flag[1] = 0;
	}
	render_minimap(info);
}
