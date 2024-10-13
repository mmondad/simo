/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:25 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 22:05:32 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rendering_2d(t_info *info)
{
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->save = mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
	if (info->angle < 0)
		info->angle += 2 * M_PI;
	if (info->angle > 2 * M_PI)
		info->angle -= 2 * M_PI;
	draw_vector(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
	mlx_destroy_image(info->mlx, info->img);
	return (0);
}
