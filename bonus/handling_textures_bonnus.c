/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 11:23:33 by mmondad           #+#    #+#             */
/*   Updated: 2024-10-13 11:23:33 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

double	norm(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	calcul_step(t_info *info, double count)
{
	info->lenght = (60 / (info->size * cos(count))) * ((WIDTH / 2)
			/ tan(0.523599));
	info->point_depart = (HEIGHT / 2) - (info->lenght / 2);
	if (info->door_flag[0])
		info->step = (double)info->texture[4].h / (double)info->lenght;
	else if (info->flag == 0)
	{
		if (info->check == 1 || info->check == 2)
			info->step = (double)info->texture[1].h / (double)info->lenght;
		else
			info->step = (double)info->texture[0].h / (double)info->lenght;
	}
	else
	{
		if (info->check == 1 || info->check == 4)
			info->step = (double)info->texture[3].h / (double)info->lenght;
		else
			info->step = (double)info->texture[2].h / (double)info->lenght;
	}
}

void	drawing_wall_vertical(t_info *info, int flag, double j)
{
	int	x;
	int	y;

	if (info->door_flag[0])
		flag = info->door_flag[0];
	x = (int)(info->texture[flag].w * info->intersection_x / 60)
		% info->texture[flag].w;
	y = j;
	info->color = get_color(y, x, info->texture[flag]);
}

void	drawing_wall_horizantal(t_info *info, int flag, double j)
{
	int	x;
	int	y;

	if (info->door_flag[0])
		flag = info->door_flag[0];
	y = j;
	x = (int)(info->texture[flag].w * info->intersection_y / 60)
		% info->texture[flag].w;
	info->color = get_color(y, x, info->texture[flag]);
}

void	drawing_all_wall(t_info *info, double j)
{
	if (info->flag == 0)
	{
		if (info->check == 1 || info->check == 2)
			drawing_wall_vertical(info, 1, j);
		else
			drawing_wall_vertical(info, 0, j);
	}
	else
	{
		if (info->check == 1 || info->check == 4)
			drawing_wall_horizantal(info, 3, j);
		else
			drawing_wall_horizantal(info, 2, j);
	}
}
