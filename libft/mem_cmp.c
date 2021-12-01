/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:20:44 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:20:44 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				i;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (aux1[i] != aux2[i])
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*aux;
	int				i;

	aux = (unsigned char *)str;
	i = 0;
	while (i < (int)n)
	{
		if (aux[i] == (unsigned char)c)
			return (&aux[i]);
		i++;
	}
	return (NULL);
}
