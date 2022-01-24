/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:23:50 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/23 16:41:41 by aldamien         ###   ########.fr       */
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
	char	*map_txt;
	char	**map;
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

//pars
int	pars_NO(t_pars *pars, char *line);
int	pars_SO(t_pars *pars, char *line);
int	pars_EA(t_pars *pars, char *line);
int	pars_WE(t_pars *pars, char *line);
int	pars_C(t_pars *pars, char *line);
int	pars_F(t_pars *pars, char *line);
int	pars_solo_line(t_vars *vars, char *line);

//check map
int	check_up(char **map, int j, int i);
int	check_right(char **map, int j, int i);
int	check_left(char **map, int j, int i);
int	check_down(char **map, int j, int i);

//parsing
int	parsing_hub(int argc, char **argv, t_vars *vars);
int	convert_map(t_pars *pars);
int	is_map_line(char *line);
void	create_txt_map(t_vars *vars, char *line);
int	verify_map(char **map);

void	clear_pars(t_pars *pars);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	end_close(t_vars *vars);

#endif
