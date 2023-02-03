/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:57:56 by Mzblah            #+#    #+#             */
/*   Updated: 2019/10/05 15:58:11 by Mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i)))
		i++;
	if (i == n)
		return (0);
	return ((*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i)));
}
