/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla < muharsla@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:56:39 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/14 16:31:37 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_alloc(int fd, char *buff)
{
	char	*readed;
	int		readed_len;

	readed = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!readed)
		return (NULL);
	readed_len = 1;
	while (!ft_strchr(readed) && readed_len != 0)
	{
		readed_len = read(fd, readed, BUFFER_SIZE);
		if (readed_len == -1)
			return (free(readed), NULL);
		buff = ft_strjoin(buff, readed);
	}
	free(readed);
	readed = NULL;
	return (buff);
}

char	*ft_first(char *buff)
{
	char	*src;
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (!buff[a])
		return (NULL);
	while (buff[a] && buff[a] != '\n')
		a++;
	src = ft_calloc((a + 2), sizeof(char));
	if (!src)
		return (NULL);
	while (i <= a && buff[i] != '\0')
	{
		src[i] = buff[i];
		i++;
	}
	return (src);
}

char	*ft_last(char *buff)
{
	char	*src;
	int		a;
	int		i;

	a = 0;
	i = 0;
	while (buff[a] && buff[a] != '\n')
		a++;
	if (!buff[a])
		return (free(buff), NULL);
	src = ft_calloc(((ft_strlen(buff) - a)), sizeof(char));
	if (!src)
		return (NULL);
	a++;
	while (buff[a] != '\0')
	{
		src[i] = buff[a];
		i++;
		a++;
	}
	free(buff);
	buff = NULL;
	return (src);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*src;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buff), buff = NULL, NULL);
	buff = ft_alloc(fd, buff);
	if (!buff)
		return (free(buff), buff = NULL, NULL);
	src = ft_first(buff);
	buff = ft_last(buff);
	return (src);
}
