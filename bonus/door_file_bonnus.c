/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_file_bonnus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:30:50 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 14:16:02 by khmessah         ###   ########.fr       */
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

void	choose_door_image(t_info *info, int index)
{
	if (info->door_flag[index])
		info->door_flag[0] = 4 + info->door_stat;
	else
		info->door_flag[0] = 0;
}

int	is_opened(t_info *info, char c, int *x)
{
	if (!info->door_stat && c == 'P')
		return (1);
	return (0);
}

int	door_validator(t_info *info, int x, int y)
{
	if (info->maps[y][x + 1] == 'P' || info->maps[y][x - 1] == 'P'
		|| info->maps[y - 1][x] == 'P' || info->maps[y + 1][x] == 'P')
		return (0);
	if (info->maps[y][x + 1] == '1' && info->maps[y][x - 1] == '1'
		&& info->maps[y - 1][x] != '1' && info->maps[y + 1][x] != '1')
		return (1);
	if (info->maps[y][x + 1] != '1' && info->maps[y][x - 1] != '1'
		&& info->maps[y - 1][x] == '1' && info->maps[y + 1][x] == '1')
		return (1);
	return (0);
}
