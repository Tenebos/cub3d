/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:13:13 by aldamien          #+#    #+#             */
/*   Updated: 2022/02/23 11:13:15 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D.h"
#include "./My-own-libft/includes/libft.h"
#include "./My-own-libft/includes/buffer.h"
#include <math.h>

double   get_opposite(int adj, int angle)
{
    return (adj * tan(angle));
}

double   get_hypothenus(int adj, int angle)
{
    return (cos(angle) / adj);
}

void    find_view_end(t_vars *vars)
{
    double delta_x;
    double delta_y;

    delta_y = 0;
    printf("%f\n", vars->game.player_pdv);
    if (vars->game.player_pdv >= 3.14115 + (3.14115 * 3 / 4) || vars->game.player_pdv <= 1.570575)
    {
        delta_x = 1;
        delta_y = get_opposite(1, vars->game.player_pdv);
        printf("ploc\n");
    }
//    printf("delta_y = %f\n", delta_y);
    printf("hypothenus = %f\n", get_hypothenus(1, vars->game.player_pdv));
}

void    rotate_view(t_vars *vars, int keycode)
{
    if (keycode == 65363)
    {
        vars->game.player_pdv += (3.14115 / 4);
        if (vars->game.player_pdv == (2 * 3.14115))
            vars->game.player_pdv = 0;
    }
    else if (keycode == 65361)
    {
        vars->game.player_pdv -= (3.14115 / 4);
        if (vars->game.player_pdv < 0)
            vars->game.player_pdv = (2 * 3.14115) - (3.14115 / 4);
    }
    printf("angle = %f\n", vars->game.player_pdv);
}