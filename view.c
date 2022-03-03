/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:22:07 by aldamien          #+#    #+#             */
/*   Updated: 2022/02/26 15:22:10 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D.h"

int check_case(t_vars *vars, int x, int y)
{
    if (vars->pars.map[y][x] == '1' || vars->pars.map[y][x] == ' ')
        return (1);
    return (0);
}

int find_wall(t_vars *vars)
{
    double s_delta_x;
    double s_delta_y;
    int is_wall;

    is_wall = 0;
    s_delta_x = vars->game.player_x;
    s_delta_y = vars->game.player_y; 
    while (is_wall == 0)
    {
        if (fabs(vars->game.delta_x) < fabs(vars->game.delta_y))
        {
            if (floor(s_delta_x + vars->game.delta_x) > floor(s_delta_x))
            {
                is_wall = check_case(vars, floor(s_delta_x + vars->game.delta_x), floor(s_delta_y));
                if (is_wall == 1)
                    break;
            }
            if (floor(s_delta_y + vars->game.delta_y) > floor(s_delta_y))
            {

            }
        }
    }
    return (0);
}