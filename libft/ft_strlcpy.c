/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:17:06 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 15:25:44 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t cmpt;

	if (!dst || !src)
		return (0);
	cmpt = 0;
	while ((cmpt + 1) < destsize && src[cmpt])
	{
		dst[cmpt] = src[cmpt];
		cmpt++;
	}
	if (destsize)
		dst[cmpt] = 0;
	return (ft_strlen((char*)src));
}
