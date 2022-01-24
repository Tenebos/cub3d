/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:28:29 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/22 17:22:42 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include "./include/cub3D.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     pars_F(t_pars *pars, char *line)
{
        int     fd;

        if (!pars->F)
        {
                pars->F = str_duplicate(&line[2], -1);
                fd = open(pars->F, O_RDONLY);
                if (fd <= 0)
                        return (-1);
                close (fd);
                return (1);
        }
        else
                return (-1);
}

int     pars_C(t_pars *pars, char *line)
{
        int     fd;

        if (!pars->C)
        {
                pars->C = str_duplicate(&line[2], -1);
                fd = open(pars->C, O_RDONLY);
                if (fd <= 0)
                        return (-1);
                close (fd);
                return (1);
        }
        else
                return (-1);
}
