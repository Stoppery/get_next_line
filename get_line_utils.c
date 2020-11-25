/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:08:43 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/25 16:25:46 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_memmove(void *destination, const void *source, size_t amount)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (destination == source)
		return (destination);
	str1 = (unsigned char *)destination;
	str2 = (unsigned char *)source;
	if (str2 > str1)
		while (amount--)
			*str1++ = *str2++;
	else if (str2 < str1)
		while (amount--)
			*(str1 + amount) = *(str2 + amount);
	return (destination);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!(s1 && s2) || !(arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[++i])
		arr[i] = s1[i];
	while (s2[++j])
		arr[i + j] = s2[j];
	arr[i + j] = '\0';
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
