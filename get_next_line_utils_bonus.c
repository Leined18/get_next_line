/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/04/01 16:36:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	while (len--)
		aux[len] = 0;
	return (aux);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (*s1 != '\0')
		res[i++] = (char)*s1++;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	res = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[x])
		res[i++] = s2[x++];
	return (res);
}
