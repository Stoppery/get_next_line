/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsherie <dsherie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:57:34 by dsherie           #+#    #+#             */
/*   Updated: 2020/11/25 17:45:40 by dsherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define ARR_SIZE 4096

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*cut_nxtline(char *s);
int		ft_consist(char *str);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_setline(char *s);

#endif
