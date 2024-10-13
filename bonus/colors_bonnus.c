/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonnus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:15:42 by khmessah          #+#    #+#             */
/*   Updated: 2024/10/12 14:15:44 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int y, int x, t_image image)
{
	int	index;

	index = ((y * image.size_line) + (x * (image.bet_pxl / 8)));
	if (image.size_line * image.h > index && index > 0)
		return (*(int *)(image.image + index));
	else
		return (0);
}
