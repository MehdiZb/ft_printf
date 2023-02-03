/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:02:02 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 19:02:20 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*while_itoa(unsigned int nb_cpy, int cmpt, char *str)
{
	while (nb_cpy != 0)
	{
		str[cmpt--] = (nb_cpy % 10) + 48;
		nb_cpy /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb_cpy;
	int				cmpt;
	int				signe;

	cmpt = 0;
	signe = (n < 0) ? 1 : 0;
	nb_cpy = (n < 0) ? -n : n;
	while (nb_cpy != 0)
	{
		nb_cpy = nb_cpy / 10;
		cmpt++;
	}
	if (n == 0)
		cmpt = 1;
	cmpt += signe;
	if (!(str = malloc(sizeof(char) * (cmpt + 1))))
		return (0);
	str[0] = '0';
	str[cmpt--] = '\0';
	nb_cpy = (n < 0) ? -n : n;
	str = while_itoa(nb_cpy, cmpt, str);
	if (signe == 1)
		str[0] = '-';
	return (str);
}
