/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-06 10:13:15 by mmondad           #+#    #+#             */
/*   Updated: 2024-09-06 10:13:15 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_data(t_info *info, int x, int y)
{
	info->x_p = (x * TILE_SIZE) + (TILE_SIZE / 2);
	info->y_p = (y * TILE_SIZE) + (TILE_SIZE / 2);
	init_angle(info, info->maps[y][x]);
}

void	check_nbr_player(t_info *info)
{
	int	x;
	int	count;
	int	y;

	count = 0;
	y = 0;
	while (info->maps[y])
	{
		x = 0;
		while (info->maps[y][x])
		{
			if (is_player(info->maps[y][x]))
			{
				set_player_data(info, x, y);
				count++;
			}
			x++;
		}
		y++;
	}
	if (count > 1 || count == 0)
		print_error("player\n");
}

int	check_extention_map(t_info *info)
{
	int	i;

	while (info->map_name && *info->map_name != '.')
		info->map_name++;
	i = 0;
	while (info->map_name && info->map_name[i])
	{
		if (ft_strcmp(info->map_name, ".cub") != 0)
			return (print_error("extension\n"), 0);
		i++;
	}
	return (1);
}

int	strcmp_path(char *s1, char *s2, int n)
{
	while (is_space(*s1))
		s1++;
	while (n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n && is_space(*(s1)))
		return (0);
	return (1);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 12))
		return (1);
	return (0);
}

char	*set_path(char *str)
{
	str += 2;
	while (is_space(*str))
		str++;
	if (*str)
		return (str);
	return (NULL);
}
