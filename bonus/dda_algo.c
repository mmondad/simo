/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 10:50:47 by mmondad           #+#    #+#             */
/*   Updated: 2024-10-13 10:50:47 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	next_position_h(t_info *info, double angle)
{
	if (info->check < 3)
	{
		info->distance_ax = (info->distance_ax + (60 / -tan((angle))));
		info->distance_ay -= 60;
	}
	else
	{
		info->distance_ax = (info->distance_ax + (60 / tan((angle))));
		info->distance_ay += 60;
	}
}

void	check_intersections_hor(t_info *info, double angle)
{
	double	x;
	double	y;

	x = info->distance_ax / 60;
	while ((info->distance_ay / 60 < info->last_line && info->distance_ay
			/ 60 >= 0) && (info->distance_ax / 60 < info->width
			&& info->distance_ax / 60 >= 0))
	{
		if (info->maps[(int)(info->distance_ay / 60)][(int)(info->distance_ax
				/ 60)] == '1' || info->maps[(int)(info->distance_ay
				/ 60)][(int)(info->distance_ax / 60)] == 'P')
		{
			if (info->maps[(int)(info->distance_ay
					/ 60)][(int)(info->distance_ax / 60)] == 'P')
				info->door_flag[0] = 1;
			info->hitwall_hor_x = info->distance_ax;
			info->hitwall_hor_y = info->distance_ay;
			return ;
		}
		next_position_h(info, angle);
	}
	info->hitwall_hor_x = info->distance_ax;
	info->hitwall_hor_y = info->distance_ay;
}

void	next_position_v(t_info *info, double angle)
{
	if (info->check == 3 || info->check == 2)
	{
		info->distance_tx -= 60;
		info->distance_ty = info->y_p - (-info->distance_tx + info->x_p)
			* tan((angle));
	}
	else
	{
		info->distance_tx += 60;
		info->distance_ty = info->y_p - (-info->distance_tx + info->x_p)
			* tan((angle));
	}
}

void	check_intersections_vir(t_info *info, double angle)
{
	while (((info->distance_ty / 60) < info->last_line && info->distance_ty
			/ 60 >= 0) && ((info->distance_tx / 60) < info->width
			&& info->distance_tx / 60 >= 0))
	{
		if (info->maps[(int)(info->distance_ty / 60)][(int)(info->distance_tx
				/ 60)] == '1' || info->maps[(int)(info->distance_ty
				/ 60)][(int)(info->distance_tx / 60)] == 'P')
		{
			if (info->maps[(int)(info->distance_ty
					/ 60)][(int)(info->distance_tx / 60)] == 'P')
				info->door_flag[1] = 1;
			info->hitwall_vir_x = info->distance_tx;
			info->hitwall_vir_y = info->distance_ty;
			return ;
		}
		next_position_v(info, angle);
	}
	info->hitwall_vir_x = info->distance_tx;
	info->hitwall_vir_y = info->distance_ty;
}
