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

static char	*get_line(char *buff, char *line)
{
	int		i;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\0')
	{
		line[i] = buff[i];
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_next(char *buf, size_t i)
{
	int		j;
	char	*tmp;
	int		len;

	len = ft_strlen(buf);
	len = len - i;
	if (buf[0] == '\0')
	{
		free (buf);
		return (0);
	}
	tmp = ft_calloc(sizeof(char), (len + 1));
	j = 0;
	while (buf[i] != '\0')
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;
	size_t		nbchar;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_calloc(1, 1);
	buff[fd] = get_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	nbchar = ft_strlnn(buff[fd]);
	line = ft_calloc(sizeof(char), (nbchar + 1));
	line = get_line(buff[fd], line);
	buff[fd] = get_next(buff[fd], nbchar);
	return (line);
}
