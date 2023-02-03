/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:56:52 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 17:56:54 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;

	str_len = 0;
	if (!s1 && !s2)
		return (0);
	if (s1)
		str_len = (size_t)ft_strlen(s1);
	if (s2)
		str_len += (size_t)ft_strlen(s2);
	if (!(str = ft_strnew(str_len)))
		return (0);
	if (s1)
		ft_strcat(str, s1);
	if (s2)
		ft_strcat(str, s2);
	return (str);
}
