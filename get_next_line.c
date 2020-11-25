/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:00:47 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/25 16:24:20 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_nxtline(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return (0);
	i++;
	while (s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save;
	int			rtn;

	rtn = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_consist(save) && rtn != 0)
	{
		if ((rtn = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[rtn] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*line = ft_setline(save);
	save = cut_nxtline(save);
	if (rtn == 0)
		return (0);
	return (1);
}
