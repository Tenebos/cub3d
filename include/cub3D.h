/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:23:50 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/13 15:31:07 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "./../minilibx-linux/mlx.h"
#include "./../minilibx-linux/mlx_int.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct s_pars
{
	char	*NO;
	char	*WE;
	char	*EA;
	char	*SO;
	char	*C;
	char	*F;
	char	*map;
}		t_pars;

typedef struct  s_vars
{
        void    *mlx;
        void    *win;
        int     res_x;
        int     res_y;
        t_data  img;
        t_pars  pars;
}               t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	end_close(t_vars *vars);

int	parsing_hub(int argc, char **argv, t_vars *vars);

#endif
