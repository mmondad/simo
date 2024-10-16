/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators_bonnus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khmessah <khmessah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:36:03 by mmondad           #+#    #+#             */
/*   Updated: 2024/10/12 20:14:11 by khmessah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

int	is_map(char *str)
{
	while (*str && is_space(*str))
		str++;
	if (*str)
		return (1);
	return (0);
}

int	ft_isdegit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
