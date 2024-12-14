/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla < muharsla@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:56:42 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/05 12:20:15 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_calloc(int m, int size)
{
	char	*c;
	int		i;
	int		res;

	i = 0;
	res = m * size;
	c = (char *)malloc(res);
	if (!c)
		return (NULL);
	while (res > 0)
	{
		c[i] = 0;
		i++;
		res--;
	}
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*c;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	c = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!c)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		c[i++] = s2[j++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}

int	ft_strchr(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
