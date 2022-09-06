/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:54:38 by ccottin           #+#    #+#             */
/*   Updated: 2022/09/06 17:59:49 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*fill_info_wall(char *str, int start, int end)
{
	char	*ret;
	int		i;

	ret = ft_calloc(end - start + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (start < end)
		ret[i++] = str[start++];
	return (ret);
}
int	get_info_wall_0(t_data *data, char *str, int i, char c)
{
	int	y;

	while (str[i] && str[i] == ' ')
		i++;
	y = i;
	while (str[y] && (str[y] != ' ' || str[y] != '\n'))
		y++;
	if (c == 'N')
	{
		if (data->map.north_texture)
			return (-7);
		data->map.north_texture = fill_info_wall(str, i, y);
		if (!data->map.north_texture)
			return (-1);
	}
	if (c == 'S')
	{
		if (data->map.south_texture)
			return (-7);
		data->map.south_texture = fill_info_wall(str, i, y);
		if (!data->map.south_texture)
			return (-1);
	}
	while (str[y] && str[y] == ' ')
		y++;
	if (str[y] != 0 && str[y] != '\n')
		return (-5);
	return (0);
}

int	get_info_wall_1(t_data *data, char *str, int i, char c)
{
	int	y;

	while (str[i] && str[i] == ' ')
		i++;
	y = i;
	while (str[y] && (str[y] != ' ' || str[y] != '\n'))
		y++;
	if (c == 'E')
	{
		if (data->map.east_texture)
			return (-7);
		data->map.east_texture = fill_info_wall(str, i, y);
		if (!data->map.east_texture)
			return (-1);
	}
	if (c == 'W')
	{
		if (data->map.west_texture)
			return (-7);
		data->map.west_texture = fill_info_wall(str, i, y);
		if (!data->map.west_texture)
			return (-1);
	}
	while (str[y] && str[y] == ' ')
		y++;
	if (str[y] != 0 && str[y] != '\n')
		return (-5);
	return (0);
}
