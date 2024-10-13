/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonnus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:46:02 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 20:15:43 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

void	clean_line(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (is_space(line[i]))
		i--;
	if (info->width < ++i)
		info->width = i;
}

void	new_maps(t_info *info)
{
	int	i;

	i = 0;
	while (info->maps[i])
	{
		clean_line(info, info->maps[i]);
		info->maps[i] = strdup_new_map(info->maps[i], info);
		i++;
	}
}

int	move_mouse(int x, int y, t_info *info)
{
	static int	a;

	if (x > a)
		info->angle += 0.01;
	else if (x < a)
		info->angle -= 0.01;
	a = x;
	return (0);
}

void	ft_hook(t_info *info)
{
	init_window(info);
	init_images(info);
	init_texture(info);
	mlx_hook(info->mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(info->mlx_win, 2, 1L << 0, move_player, info);
	mlx_hook(info->mlx_win, 6, 1 << 6, move_mouse, info);
	mlx_loop(info->mlx);
	free_list(info, 0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		print_error("arguments error\n");
	init_info(&info, av);
	read_maps(&info);
	check_textures_path(&info);
	if (!info.path_ea || !info.path_so || !info.path_we || !info.path_no)
		print_error("path_error\n");
	new_maps(&info);
	check_extention_map(&info);
	check_wall_valide(&info);
	check_nbr_player(&info);
	if (!check_element_maps(&info))
	{
		printf("autre caractere\n");
		return (0);
	}
	ft_hook(&info);
}
