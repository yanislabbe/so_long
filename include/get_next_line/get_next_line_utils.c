/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:43:17 by ylabbe            #+#    #+#             */
/*   Updated: 2022/05/04 16:18:56 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *src)
{
	size_t	st;

	st = 0;
	while (src[st])
		st++;
	return (st);
}

char	*gnl_strchr(char *src, int c)
{
	if (!src)
		return (NULL);
	while (*src || *src == c)
	{
		if (*src == (char)c)
			return ((char *)src);
		++src;
	}
	return (NULL);
}

char	*gnl_strjoin(char *src, char *src2)
{
	char	*buf;
	size_t	st2;
	size_t	st;

	if (!src)
	{
		src = malloc(sizeof(char) * 1);
		src[0] = '\0';
	}
	buf = malloc(sizeof(char) * (gnl_strlen(src) + gnl_strlen(src2) + 1));
	if (!buf)
		return (NULL);
	st = -1;
	st2 = 0;
	if (src)
		while (src[++st] != '\0')
			buf[st] = src[st];
	while (src2[st2] != '\0')
		buf[st++] = src2[st2++];
	buf[gnl_strlen(src) + gnl_strlen(src2)] = '\0';
	free(src);
	return (buf);
}
