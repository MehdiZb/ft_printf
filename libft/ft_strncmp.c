/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:47:25 by Mzblah            #+#    #+#             */
/*   Updated: 2019/09/28 17:47:34 by Mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] > (unsigned char)s2[i]) ? 1 : -1);
		i++;
	}
	if (i < n && s1[i] != s2[i])
		return (((unsigned char)s1[i] > (unsigned char)s2[i]) ? 1 : -1);
	return (0);
}
