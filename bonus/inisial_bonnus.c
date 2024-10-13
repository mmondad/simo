/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisial_bonnus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:56:30 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:09:41 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	init_door_texture(t_info *info)
{
	info->texture[4].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/bonus_textures/port_f.xpm", &info->texture[4].w,
			&info->texture[4].h);
	info->texture[4].image = mlx_get_data_addr(info->texture[4].xpm_ptr,
			&info->texture[4].bet_pxl, &info->texture[4].size_line,
			&info->texture[4].endn);
	info->texture[5].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/bonus_textures/port_o.xpm", &info->texture[5].w,
			&info->texture[5].h);
	info->texture[5].image = mlx_get_data_addr(info->texture[5].xpm_ptr,
			&info->texture[5].bet_pxl, &info->texture[5].size_line,
			&info->texture[5].endn);
}

void	init_texture(t_info *info)
{
	info->texture[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/mur_1.xpm", &info->texture[0].w,
			&info->texture[0].h);
	info->texture[0].image = mlx_get_data_addr(info->texture[0].xpm_ptr,
			&info->texture[0].bet_pxl, &info->texture[0].size_line,
			&info->texture[0].endn);
	info->texture[1].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/mur_2.xpm", &info->texture[1].w,
			&info->texture[1].h);
	info->texture[1].image = mlx_get_data_addr(info->texture[1].xpm_ptr,
			&info->texture[1].bet_pxl, &info->texture[1].size_line,
			&info->texture[1].endn);
	info->texture[2].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/ps3.xpm", &info->texture[2].w,
			&info->texture[2].h);
	info->texture[2].image = mlx_get_data_addr(info->texture[2].xpm_ptr,
			&info->texture[2].bet_pxl, &info->texture[2].size_line,
			&info->texture[2].endn);
	info->texture[3].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/walls_textures/prison_lux1.xpm", &info->texture[3].w,
			&info->texture[3].h);
	info->texture[3].image = mlx_get_data_addr(info->texture[3].xpm_ptr,
			&info->texture[3].bet_pxl, &info->texture[3].size_line,
			&info->texture[3].endn);
	init_door_texture(info);
}

void	init_angle(t_info *info, char c)
{
	if (c == 'N')
		info->angle = 3 * M_PI / 2;
	else if (c == 'W')
		info->angle = M_PI;
	else if (c == 'S')
		info->angle = M_PI / 2;
	else if (c == 'E')
		info->angle = 0;
}

void	conditions(t_info *info, double angle)
{
	if (angle >= 3 * M_PI / 2 && angle < 2 * M_PI)
		info->check = 1;
	else if (angle < 3 * M_PI / 2 && angle > M_PI)
		info->check = 2;
	else if (angle < M_PI / 2 && angle > 0)
		info->check = 4;
	else if (angle > M_PI / 2 && angle < M_PI)
		info->check = 3;
}

void	start_animation(t_info *info)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 4)
	{
		color = 0xFFFFFF - 170;
		x = 0;
		while (x < 170)
		{
			mlx_put_image_to_window(info->mlx, info->mlx_win,
				info->start_images[y].xpm_ptr, 300 + (120 * y), x);
			usleep(2 * 1400);
			x += 1;
			mlx_string_put(info->mlx, info->mlx_win, WIDTH / 2 - 50, HEIGHT / 2
				+ 50, color++, "click space to start");
		}
		y++;
	}
}

void	init_window(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "duva");
	init_start_images(info);
}
