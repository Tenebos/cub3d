/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:11:18 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/23 17:06:52 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include "./include/cub3D.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	create_txt_map(t_vars *vars, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (vars->pars.map_txt)
	{
		tmp = str_duplicate(vars->pars.map_txt, -1);
		free (vars->pars.map_txt);
		vars->pars.map_txt = NULL;
		vars->pars.map_txt = str_join(tmp, "\n");
		free (tmp);
		tmp = NULL;
		tmp = str_duplicate(vars->pars.map_txt, -1);
		free (vars->pars.map_txt);
		vars->pars.map_txt = NULL;
	}
	vars->pars.map_txt = str_join(tmp, line);
	if (tmp)
		free (tmp);
}

int     is_map_line(char *line)
{       
	int     i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W'))
			return (0);
		else 
			i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	verify_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != ' ')
			{
				if (check_up(map, j, i) == -1
					|| check_right(map, j, i) == -1
					|| check_left(map, j, i) == -1
					|| check_down(map, j, i) == -1)
					return (-1);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	convert_map(t_pars *pars)
{
	if (!pars->map_txt)
		return (-1);
	pars->map = str_split(pars->map_txt, '\n');
	return (1);
}
