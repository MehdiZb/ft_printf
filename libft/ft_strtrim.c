/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:17:51 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 18:17:52 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimmed_str_start(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (s1[i] && ft_is_char_in_str(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_trimmed_str_end(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_is_char_in_str(s1[i], set))
		i--;
	return (i + 1);
}

static size_t	ft_trimmed_str_len(char const *s1, char const *set)
{
	size_t	size;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if ((size = ft_trimmed_str_start(s1, set)) == s1_len)
		return (0);
	size += (s1_len - ft_trimmed_str_end(s1, set));
	return (s1_len - size);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	new_str_len;
	size_t	i;
	size_t	cmpt;

	if (!s1)
		return (0);
	if (!set || !set[0] ||
		(new_str_len = ft_trimmed_str_len(s1, set)) == ft_strlen(s1))
		return (ft_strdup(s1));
	new_str_len = ft_trimmed_str_len(s1, set);
	if (!(str = ft_strnew(new_str_len)))
		return (0);
	i = ft_trimmed_str_start(s1, set);
	cmpt = 0;
	while (cmpt < new_str_len)
		str[cmpt++] = s1[i++];
	return (str);
}
