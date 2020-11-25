/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:57:48 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/25 17:38:59 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_consist(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char	*d;
	char	*s;

	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (s > d)
		while (len--)
			*d++ = *s++;
	else if (s < d)
		while (len--)
			*(d + len) = *(s + len);
	return (dst);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	unsigned int	n;

	if (!s1 && !s2)
		return (0);
	n = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(arr = malloc(sizeof(char) * n)))
		return (0);
	ft_memmove(arr, s1, ft_strlen(s1));
	ft_memmove(arr + ft_strlen(s1), s2, ft_strlen(s2));
	arr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((void *) s1);
	return (arr);
}

char	*ft_setline(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
