/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:23:09 by Julian            #+#    #+#             */
/*   Updated: 2021/12/01 12:23:16 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error(char *message)
{
	printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

void	print_warning(char *message)
{
	printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}
