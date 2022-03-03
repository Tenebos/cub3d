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
#include <stdio.h>
#include <stdlib.h>

int    adapt_angle(t_vars *vars)
{
    if (vars->game.player_pdv >= 270)
        return (vars->game.player_pdv - 270);
    else if (vars->game.player_pdv >= 180)
        return (vars->game.player_pdv - 180);
    else if (vars->game.player_pdv >= 90)
        return (vars->game.player_pdv - 90);
    return (vars->game.player_pdv);
}

double  get_adj_f_one(int angle)
{
    if (angle == 0)
        return (1);
    else if (angle == 15)
        return (1);
    else if (angle == 30)
        return (1);
    else if (angle == 45)
        return (1);
    else if (angle == 60)
        return (0.5773503);
    else if (angle == 75)
        return (0.2679492);
    else
        return (-1);
}

double  get_opp_f_one(int angle)
{
    if (angle == 0)
        return (0);
    else if (angle == 15)
        return (0.2679492);
    else if (angle == 30)
        return (0.5773503);
    else if (angle == 45)
        return (1);
    else if (angle == 60)
        return (1);
    else if (angle == 75)
        return (1);
    else
        return (-1);
}

void    get_delta(t_vars *vars)
{
    printf("pdv = %d\n", vars->game.player_pdv);
    if (vars->game.player_pdv >= 270)
    {
        vars->game.delta_y = get_opp_f_one(adapt_angle(vars));
        vars->game.delta_x = get_adj_f_one(adapt_angle(vars));
    }
    else if (vars->game.player_pdv >= 180)
    {
        vars->game.delta_y = -get_adj_f_one(adapt_angle(vars));
        vars->game.delta_x = -get_opp_f_one(adapt_angle(vars));
    }
    else if (vars->game.player_pdv >= 90)
    {
        vars->game.delta_y = -get_opp_f_one(adapt_angle(vars));
        vars->game.delta_x = get_adj_f_one(adapt_angle(vars));
    }
    else
    {
        vars->game.delta_y = get_adj_f_one(adapt_angle(vars));
        vars->game.delta_x = get_opp_f_one(adapt_angle(vars));
    }
    printf("delta_x = %f, delta_y = %f\n", vars->game.delta_x, vars->game.delta_y);
}

void    rotate_view(t_vars *vars, int keycode)
{
    if (keycode == 65363)
    {
        vars->game.player_pdv += 15;
        if (vars->game.player_pdv == 360)
            vars->game.player_pdv = 0;
    }
    else if (keycode == 65361)
    {
        vars->game.player_pdv -= 15;
        if (vars->game.player_pdv < 0)
            vars->game.player_pdv = 345;
    }
    get_delta(vars);
} 