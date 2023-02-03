/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:34:07 by Mzblah            #+#    #+#             */
/*   Updated: 2019/09/28 17:34:10 by Mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	needle_len;

	i = 0;
	needle_len = ft_strlen((char*)needle);
	while (haystack[i])
	{
		if (!ft_strncmp(haystack + i, needle, needle_len))
			return ((char*)haystack + i);
		i++;
	}
	if (!haystack[0] && !needle[0])
		return ((char*)haystack);
	return (0);
}
