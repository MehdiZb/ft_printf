/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:05:04 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 17:06:32 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strnew(0));
	if (!(str = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < len && (s + start)[i])
	{
		str[i] = (s + start)[i];
		i++;
	}
	return (str);
}
