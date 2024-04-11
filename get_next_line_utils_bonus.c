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

size_t	ft_strlen(char const *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_ptr;
	size_t	i;

	if (!s || !start)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		str[i] = 0;
		i++;
	}
	s += start;
	str_ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (str_ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*temp_dup;

	temp_dup = 0;
	dup = 0;
	dup = (char *)malloc(strlen(s1) + 1);
	if (!dup)
		return (NULL);
	temp_dup = dup;
	while (*s1)
	{
		*temp_dup++ = *s1++;
	}
	*temp_dup = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*start_join;
	int		len_s1;
	int		len_s2;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	total_len = len_s1 + len_s2;
	join = (char *)malloc((total_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	start_join = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (start_join);
}

char	*ft_strchr(char *str, int c)
{
	unsigned char	b;
	int				i;

	b = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == b)
			return ((char *)&str[i]);
		i++;
	}
	if (b == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
