/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:55:13 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/25 17:45:47 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*save[ARR_SIZE];
	int			rtn;

	rtn = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_consist(save[fd]) && rtn != 0)
	{
		if ((rtn = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[rtn] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	*line = ft_setline(save[fd]);
	save[fd] = cut_nxtline(save[fd]);
	if (rtn == 0)
		return (0);
	return (1);
}
