/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:25:28 by ylabbe            #+#    #+#             */
/*   Updated: 2022/05/05 14:31:34 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*voir_nl(char *src)
{
	char	*buf;
	int		i;

	if (!*src)
		return (NULL);
	buf = malloc(sizeof(char) * (gnl_strlen(src) + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		buf[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		buf[i] = src[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static char	*lecture_nl(char *src)
{
	char	*buf;
	int		i2;
	int		i;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	buf = malloc(sizeof(char) * (gnl_strlen(src) - i + 1));
	if (!buf)
		return (NULL);
	i++;
	i2 = 0;
	while (src[i])
		buf[i2++] = src[i++];
	buf[i2] = '\0';
	free(src);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*src;
	char		*buf;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!gnl_strchr(src, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		src = gnl_strjoin(src, buf);
	}
	free(buf);
	buf = voir_nl(src);
	src = lecture_nl(src);
	return (buf);
}
