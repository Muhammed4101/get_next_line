/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muharsla < muharsla@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:56:36 by muharsla          #+#    #+#             */
/*   Updated: 2024/12/05 12:20:25 by muharsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*ft_calloc(int m, int size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s);
int		ft_strlen(const char *s);

#endif
