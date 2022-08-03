/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:18:16 by ccottin           #+#    #+#             */
/*   Updated: 2022/08/03 18:04:53 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_return(int ret, t_data *data)
{
	if (ret == 1)
	{
		printf("Error\nPlease give a single map as argument\n");
		exit(0);
	}
	if (ret == -2)
	{
		printf("Error\nInvalid file extension\n");
		exit(0);
	}
	if (ret == -1)
	{
		printf("Error\n");
		perror("cub3D ");
		exit (1);
	}
}
