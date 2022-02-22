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
	init_zero(&vars->pars, sizeof(vars->pars));
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

static int	display(t_error code)
{
	static const char	*error[ERROR_MAX] =
	{
		[WRONG_AC] = "Error Parsing :: wrong number of arguments",
		[IS_NOT_CUBE] = "Error Parsing :: argument is not ending by .cube",
		[CANT_OPEN] = "Error Parsing :: cannot open the argument",
		[ERROR_INSIDE_CUBE] = "Error Parsing :: Wrong content for .cube",
		[ERROR_MAP_1] = "Error Parsing :: map invalid",
		[ERROR_MAP_2] = "Error Parsing :: map invalid"
	};
	printf("%s\n", error[code]);
	return (code);
}

int	parsing_hub(int argc, char **argv, t_vars *vars)
{
	int	len;
	int	fd;

	if (argc != 2)
		return (display(WRONG_AC));
	len = str_len(argv[1]);
	if (len < 5 || str_comp(&argv[1][len - 5], ".cube") != 0)
		return (display(IS_NOT_CUBE));
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (display(CANT_OPEN));
	if (get_info(fd, vars, NULL, NULL) < 0)
		return (display(ERROR_INSIDE_CUBE));
	if (convert_map(&vars->pars) == -1)
		return (display(ERROR_MAP_1));
	if (verify_map(vars->pars.map) == -1)
		return (display(ERROR_MAP_2));
	return (10);
}