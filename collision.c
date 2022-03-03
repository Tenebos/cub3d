/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:31:10 by aldamien          #+#    #+#             */
/*   Updated: 2022/02/22 14:31:13 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D.h"
#include "./My-own-libft/includes/libft.h"
#include "./My-own-libft/includes/buffer.h"

void    decrease_y(t_vars *vars)
{
	if (vars->pars.map[(vars->game.player_y - 15 - 1) / 15][(vars->game.player_x - 15) / 15] != '1'
	&& vars->pars.map[(vars->game.player_y - 15 - 1) / 15][(vars->game.player_x - 15) / 15] != ' ')
		vars->game.player_y--;
}

void    increase_y(t_vars *vars)
{
	printf("%d\n", (vars->game.player_y - 15 + 1) / 15);
	if (vars->pars.map[(vars->game.player_y - 15 + 1) / 15][(vars->game.player_x - 15) / 15] != '1'
	&& vars->pars.map[(vars->game.player_y - 15 + 1) / 15][(vars->game.player_x - 15) / 15] != ' ')
		vars->game.player_y++;
}

void    decrease_x(t_vars *vars)
{
	if (vars->pars.map[(vars->game.player_y - 15) / 15][(vars->game.player_x - 15 - 1) / 15] != '1'
	&& vars->pars.map[(vars->game.player_y - 15) / 15][(vars->game.player_x - 15 - 1) / 15] != ' ')
		vars->game.player_x--;
}

void    increase_x(t_vars *vars)
{
	if (vars->pars.map[(vars->game.player_y - 15) / 15][(vars->game.player_x - 15 + 1) / 15] != '1'
	&& vars->pars.map[(vars->game.player_y - 15) / 15][(vars->game.player_x - 15 + 1) / 15] != ' ')
		vars->game.player_x++;
}

void	check_collision (t_vars *vars, int keycode)
{
	if (keycode == 119)
        decrease_y(vars);
	else if (keycode == 115)
        increase_y(vars);
	else if (keycode == 97)
        decrease_x(vars);
	else if (keycode == 100)
        increase_x(vars);
	printf("player_x = %d, player y = %d\n", vars->game.player_x, vars->game.player_y);
	get_delta(vars);
	refresh_img(vars);
}