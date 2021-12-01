/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:21:07 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:21:07 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Returns the number of lines a 2D string table that ends in NULL
-> *chars*\0
-> *chars*\0
-> NULL 
Retunr value: 2 */
int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count])
		count++;
	return (count);
}

/* Frees a 2D table */
void	ft_free_chartable(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}
