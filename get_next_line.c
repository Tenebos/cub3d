/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:35:01 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/13 17:14:25 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static const int	BUFFER_SIZE = 5;

static int	str_len(char *txt)
{
	int	i;

	i = 0;
	if (txt == NULL)
		return (0);
	while (txt[i])
		i++;
	return (i);
}

static int	str_search(char *txt, char c)
{
	int	i;

	i = 0;
	while (txt[i] != c)
		i++;
	if (txt[i] == 0)
		return (-1);
	return (i);
}

static char *dispatch_text(char **res)
{
	char	*line;
	char	*tmp;
	int	i;

	i = str_search(*res, '\n');
	if (i >= 0)
	{
		line = substr(*res, i);
		tmp = strdup(&(*res[i]));
		free(*res);
		*res = tmp;
	}
	else
	{
		line = *res
		*res = NULL;
	}
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *res = NULL;
	char	buf[BUFFER_SIZE + 1];
	int	i;

	if (res && str_search(res, '\n'))
		return (dispatch_text(&res));
	else
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = 0;
		res = strjoin(res, buf); // !! il va falloir pouvoir join des chaines vides
		while (str_search(res, '\n') == -1 && i != 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			buf[i] = 0;
			res = strjoin(res, buf); // free les deux chaines au besoin
		}
		return (dispatch_text(&res));
	}
}
