/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:03:32 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/23 17:59:36 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include "./include/cub3D.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// avancer par etape
// trouver comment faire marcher gnl        ok
// trouver comment diviser une ligne        ok

// verifier une texture ?                   ok

// exporter et clean une texture            ok
// dupliquer pour toutes les autres.        ok
// checker les doublons                     ?
// verifier la validite de la map                     ok
// -> un seul caractere de joueur                     ok
// -> 0 et cara joueur toujours entoures par des 1    ok

static int	pars_verify(t_pars *pars)
{
	int	i;
	int	check;

	if (!pars->NO || !pars->WE || !pars->EA || !pars->SO || !pars->C
		|| !pars->F || !pars->map_txt)
		return (-1);
	i = 0;
	check = 0;
	while (pars->map_txt[i])
	{
		if (pars->map_txt[i] != '0' && pars->map_txt[i] != '1'
			&& pars->map_txt[i] != ' ' && pars->map_txt[i] != '\n')
			check++;
		i++;
	}
	if (check != 1)
		return (-1);
	// check ou pas check de textures differentes ?
	return (1);
}

static void	init_pars(t_pars *pars)
{
	pars->NO = NULL;
	pars->WE = NULL;
	pars->EA = NULL;
	pars->SO = NULL;
	pars->C = NULL;
	pars->F = NULL;
	pars->map = NULL;
	pars->map_txt = NULL;
}

void	clear_pars(t_pars *pars)
{
	int	i;

	i = 0;
	if (pars->NO)
		free (pars->NO);
	if (pars->WE)
		free (pars->WE);
	if (pars->EA)
		free (pars->EA);
	if (pars->SO)
		free (pars->SO);
	if (pars->C)
		free (pars->C);
	if (pars->F)
		free (pars->F);
	if (pars->map_txt[i])
		free (pars->map_txt);
	if (pars->map)
	{
		while (pars->map[i])
		{
			free(pars->map[i]);
			i++;
		}
		free (pars->map);
	}
}

static int	get_info(int fd, t_vars *vars, char *line, char *buffer)
{
	int	check;
	int	endmap;

	check = 1;
	endmap = 0;
	init_pars(&vars->pars);
	while ((check == 1 || check == 0) && (get_next_line(fd, &buffer, &line) || line))
	{
		check = pars_solo_line(vars, line);
		if (!is_map_line(line) && endmap == 1)
			endmap = 2;
		else if (is_map_line(line) && (endmap == 0 || endmap == 1))
		{
			create_txt_map(vars, line);
			endmap = 1;
		}
		else if (is_map_line(line) && endmap == 2)
			endmap = 3;
		free (line);
	}
	check = pars_verify(&vars->pars);
	if (check == -1 || endmap == 3)
		return (-1);
	return (1);
}

int	parsing_hub(int argc, char **argv, t_vars *vars)
{
	int	len;
	int	fd;

	if (argc != 2)
		return (-2);
	len = str_len(argv[1]);
	if (len < 5 || str_comp(&argv[1][len - 5], ".cube") != 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (-3);
	if (get_info(fd, vars, NULL, NULL) < 0)
		return (-4);
	if (convert_map(&vars->pars) == -1)
		return (-5);
	if (verify_map(vars->pars.map) == -1)
		return (-6);
	return (1);
}
