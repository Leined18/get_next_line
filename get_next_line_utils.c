#include "get_next_line.h"

// STRLEN

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0') // Cuenta la longitud del string hasta encontrar el carácter nulo
		i++;
	return (i);
}

//CALLOC

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	len;

	len = count * size; // Calcula el tamaño total de memoria a reservar
	aux = malloc(len); // Reserva memoria usando malloc
	if (!aux) // Verifica si malloc falló
		return (0);
	while (len--) // Inicializa la memoria reservada a 0
		aux[len] = 0;
	return (aux);
}

//STRDUP

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + 1)); // Reserva memoria y suma 1 para el carácter nulo
	if (!str) // Verifica si ft_calloc falló
		return (0);
	while (*s1 != '\0') // Copia el string
		str[i++] = (char)*s1++;
	return (str);
}

// STRCHR

char	*ft_strchr(const char *s, int c)
{	char	*aux;

	aux = (char *)s;
	while (*aux != '\0') // Busca el carácter en el string
	{
		if (*aux == (char)c)
			return (aux);
		aux++;
	}
	if (*aux == (char)c) // Verifica si el carácter es el carácter nulo
		return (aux);
	return (0);
}

// STRJOIN

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1); // Reserva memoria para la concatenación
	if (!str) // Comprueba si ft_calloc falló
		return (NULL);
	while (s1 && s1[i]) // Copia el primer string
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j]) // Copia el segundo string
		str[i++] = s2[j++];
	return (str);
}