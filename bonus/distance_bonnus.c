/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonnus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:00:34 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:09:15 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	compare_distance(t_info *info)
{
	double	pd;
	double	pe;

	pd = sqrt(pow(info->x_p - info->hitwall_hor_x, 2)
			+ pow(info->y_p - info->hitwall_hor_y, 2));
	pe = sqrt(pow(info->x_p - info->hitwall_vir_x, 2)
			+ pow(info->y_p - info->hitwall_vir_y, 2));
	if (pd > pe)
	{
		choose_door_image(info, 1);
		info->flag = 1;
		info->intersection_x = fabs(info->hitwall_vir_x);
		info->intersection_y = fabs(info->hitwall_vir_y);
		info->size = pe;
	}
	else
	{
		choose_door_image(info, 0);
		info->flag = 0;
		info->intersection_x = fabs(info->hitwall_hor_x);
		info->intersection_y = fabs(info->hitwall_hor_y);
		info->size = pd;
	}
}

void	calcul_distance(t_info *info, double angle)
{
	if (info->check == 1 || info->check == 2)
		info->distance_ay = floor(info->y_p / 60) * 60 - pow(10, -10);
	else if (info->check == 3 || info->check == 4)
		info->distance_ay = floor(info->y_p / 60) * 60 + 60;
	info->distance_ax = info->x_p + (info->distance_ay - info->y_p)
		/ tan((angle));
	if (info->check == 3 || info->check == 2)
		info->distance_tx = floor(info->x_p / 60) * (60) - pow(10, -10);
	if (info->check == 4 || info->check == 1)
		info->distance_tx = floor(info->x_p / 60) * (60) + 60;
	info->distance_ty = info->y_p - (-info->distance_tx + info->x_p)
		* tan((angle));
	check_intersections_hor(info, angle);
	check_intersections_vir(info, angle);
	compare_distance(info);
}
