/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft_bonnus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondad <mmondad@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 11:54:10 by mmondad           #+#    #+#             */
/*   Updated: 2024-10-13 11:54:10 by mmondad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonnus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && s2 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, t_info *info)
{
	int		i;
	char	*s1;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	s1 = ft_malloc(i + 1, info);
	i = 0;
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
