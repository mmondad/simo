/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonnus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:16:43 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 20:04:43 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	init_start_images(t_info *info)
{
	int	w;
	int	h;

	info->start_images[0].xpm_ptr = mlx_xpm_file_to_image(info->mlx,
			"./bonus/presentation_textures/presentation.xpm", &w, &h);
	mlx_put_image_to_window(info->mlx, info->mlx_win,
		info->start_images[0].xpm_ptr, 0, 0);
}

void	init_images(t_info *info)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open("./bonus/images.txt", O_RDONLY);
	y = 0;
	while (y < WEAPONS)
	{
		x = 0;
		while (x < 4)
		{
			line = get_next_line(fd, info);
			line[ft_strlen(line) - 1] = '\0';
			info->images[y][x].xpm_ptr = checker(info,
					mlx_xpm_file_to_image(info->mlx, line,
						&info->images[y][x].w, &info->images[y][x].h));
			info->images[y][x].image = checker(info,
					mlx_get_data_addr(info->images[y][x].xpm_ptr,
						&info->images[y][x].bet_pxl,
						&info->images[y][x].size_line,
						&info->images[y][x].endn));
			x++;
		}
		y++;
	}
}

void	init_info(t_info *info, int ac, char **av)
{
	info->ac = ac;
	info->gun = 0;
	info->garbage = NULL;
	info->width = 0;
	info->door_flag[0] = 0;
	info->door_flag[1] = 0;
	info->door_stat = 0;
	info->map_name = av[1];
	info->tmp = 0;
	info->path_ea = NULL;
	info->path_no = NULL;
	info->path_we = NULL;
	info->path_so = NULL;
	info->x_p = 0;
	info->index_x = 0;
	info->index_y = -1;
	info->y_p = 0;
	info->ceiling_color = NULL;
	info->floor_color = NULL;
	info->last_line = 0;
	info->dir_x = 0;
	info->dir_y = 0;
	info->c = ft_malloc(sizeof(int) * 3, info);
	info->f = ft_malloc(sizeof(int) * 3, info);
}
