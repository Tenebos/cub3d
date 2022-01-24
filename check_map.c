/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:42:43 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/23 17:09:03 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include "./include/cub3D.h"

int	check_up(char **map, int j, int i)
{
	if (j == 0)
		return (-1);
	if (map[j - 1][i] == ' ')
		return (-1);
	return (1);
}

int     check_right(char **map, int j, int i)
{	
        if (map[j][i + 1] == ' ' || map[j][i + 1] == 0)
                return (-1);
        return (1);
}

int     check_left(char **map, int j, int i)
{
	if (i == 0)
		return (-1);
        if (map[j][i - 1] == ' ')
                return (-1);
        return (1);
}   
int	check_down(char **map, int j, int i)
{
	if (map[j + 1] == NULL)
		return (-1);
	if (map[j + 1][i] == ' ')
		return (-1);
	return (1);
}
