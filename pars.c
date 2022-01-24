/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:39 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/22 18:35:35 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include "./include/cub3D.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	pars_NO(t_pars *pars, char *line)
{
	int	fd;

	if (!pars->NO)
	{
		pars->NO = str_duplicate(&line[3], -1);
		fd = open(pars->NO, O_RDONLY);
		if (fd <= 0)
			return (-1);
		close (fd);
		return (1);
	}
	else
		return (-1);
}

int     pars_SO(t_pars *pars, char *line)
{
	int     fd;

	if (!pars->SO)
	{
		pars->SO = str_duplicate(&line[3], -1);
		fd = open(pars->SO, O_RDONLY);
		if (fd <= 0)
			return (-1);
		close (fd);
		return (1);
	}
	else
		return (-1);
}

int     pars_WE(t_pars *pars, char *line)
{
	int     fd;

	if (!pars->WE)
	{
		pars->WE = str_duplicate(&line[3], -1);
		fd = open(pars->WE, O_RDONLY);
		if (fd <= 0)
			return (-1);
		close (fd);
		return (1);
	}
	else
		return (-1);
}

int     pars_EA(t_pars *pars, char *line)
{
	int     fd;

	if (!pars->EA)
	{
		pars->EA = str_duplicate(&line[3], -1);
		fd = open(pars->EA, O_RDONLY);
		if (fd <= 0)
			return (-1);
		close (fd);
		return (1);
	}
	else
		return (-1);
}

int	pars_solo_line(t_vars *vars, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (pars_NO(&vars->pars, line));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (pars_SO(&vars->pars, line));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (pars_WE(&vars->pars, line));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (pars_EA(&vars->pars, line));
	else if (line[0] == 'C' && line[1] == ' ')
		return (pars_C(&vars->pars, line));
	else if (line[0] == 'F' && line[1] == ' ')
		return (pars_F(&vars->pars, line));
	else
		return (0);
	return (0);
}
