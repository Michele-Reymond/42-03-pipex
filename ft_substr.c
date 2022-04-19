/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:03:48 by mreymond          #+#    #+#             */
/*   Updated: 2022/04/19 13:55:44 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len > size && start < size)
		len = size - (size_t)start + 1;
	if (start > size)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start] != '\0' && start < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

// Alloue (avec malloc(3)) et retourne une chaine de caractères issue 
// de la chaine ’s’.Cette nouvelle chaine commence à l’index ’start’ 
// et a pour taille maximale ’len’

// #1. La chaine de laquelle extraire la nouvelle chaine
// #2. L’index de début de la nouvelle chaine dans lachaine ’s’.
// #3. La taille maximale de la nouvelle chaine.

// RETURN 
// The nouvelle chaine de caractere. NULL sil’allocation échoue.