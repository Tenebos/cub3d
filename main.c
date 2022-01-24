/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:53 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/24 12:12:56 by aldamien         ###   ########.fr       */
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

int	end_close(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	clear_pars(&vars->pars);
	exit (0);
	return (1);
}

int	mlx_keycode(int keycode, t_vars *vars)
{
	if(keycode == 65307)
		end_close(vars);
	return (1);
}

void	resolution(int argc, char **argv, t_vars *vars)
{

	if (argc == 3)
	{
		vars->res_x = ft_atoi(argv[1]);
		vars->res_y = ft_atoi(argv[2]);
	}
	else
	{
		vars->res_x = 1920;
		vars->res_y = 1080;
	}
}

void	create_img(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->res_x, vars->res_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
		&vars->img.line_length, &vars->img.endian);
	my_mlx_pixel_put(&vars->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	mem_set(&vars, 0, sizeof(t_vars));
	if (parsing_hub(argc, argv, &vars) == 1)
	{
//		resolution(argc, argv, &vars);
		vars.res_x = 1920;
		vars.res_y = 1080;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.res_x, vars.res_y, "Hello world!");
		create_img(&vars);
		mlx_hook(vars.win, 2, 1L<<0, mlx_keycode, &vars);
		mlx_hook(vars.win, 33, 1L<<17, end_close, &vars); //croix
		mlx_loop(vars.mlx);
	}
	printf("retour de parsing : %d\n", parsing_hub(argc, argv, &vars));
}
