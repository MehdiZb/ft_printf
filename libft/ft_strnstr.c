/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:18:27 by Mzblah            #+#    #+#             */
/*   Updated: 2019/09/28 18:19:23 by Mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen((char*)needle);
	while (haystack[i] && (i + needle_len) <= n)
	{
		if (!ft_strncmp(haystack + i, needle, needle_len))
			return ((char*)haystack + i);
		i++;
	}
	if ((!haystack[0] && !needle[0] && n > 0) || needle_len == 0)
		return ((char*)haystack);
	return (0);
}
