/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:15:42 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/16 14:15:43 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_is_char_in_str(char c, const char *str)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (c == str[i])
			return (i);
	return (-1);
}
