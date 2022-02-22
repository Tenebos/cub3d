/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:55:38 by aldamien          #+#    #+#             */
/*   Updated: 2022/02/22 11:55:40 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D.h"
#include "./My-own-libft/includes/libft.h"
#include "./My-own-libft/includes/buffer.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    print_case(t_vars *vars, char c, int line, int colonn)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i <= 15)
    {
        while (j <= 15)
        {
            if (c == '1')
            	my_mlx_pixel_put(&vars->img, (line + i), (colonn + j), 0x00FF0000);
            else if (c == '0')
                my_mlx_pixel_put(&vars->img, (line + i), (colonn + j), 0x0000FF00);
        j++;
        }
        j = 0;
        i++;
    }
}

void    create_map(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->pars.map[i])
    {
        while (vars->pars.map[i][j])
        {
            print_case(vars, vars->pars.map[i][j], (15 + 15 * j), (15 + 15 * i));
            j++;
        }
        i++;
        j = 0;
    }
}

void	create_img(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->res_x, vars->res_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
		&vars->img.line_length, &vars->img.endian);
        create_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}