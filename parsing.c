/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:03:32 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/17 15:38:18 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./My-own-libft/includes/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	get_info(int fd, t_vars *vars)
{
	while (get_next_line)

}

int	parsing_hub(int argc, char **argvi, t_vars *vars)
{
	int	len;
	int	fd;

	if (argc != 2)
		return (-2);
	len = str_len(argv[1]);
	if (len < 5 || str_comp(&argv[1][len - 5], ".cube") != 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (-3);
	if (get_info(fd, vars) < 0)
		return (-4);
	return (1);
}
