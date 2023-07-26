/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:31:17 by nminotte          #+#    #+#             */
/*   Updated: 2022/11/20 13:59:55 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static char	*get_read(int fd, char *buff)
{
	int		i;
	char	*buf_tmp;

	buf_tmp = ft_calloc(1, (BUFFER_SIZE + 1));
	i = 1;
	while (i != 0)
	{
		i = read(fd, buf_tmp, BUFFER_SIZE);
		if (i == -1 || (i == 0 && buff[0] == '\0'))
		{
			free (buff);
			free (buf_tmp);
			return (NULL);
		}
		buf_tmp[i] = '\0';
		buff = ft_strjoin_free(buff, buf_tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buf_tmp);
	return (buff);
}

char	*get_line_stdin(int fd)
{
	char	*buff;

	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, 1);
	buff = get_read(fd, buff);
	if (!buff)
		return (NULL);
	return (buff);
}
