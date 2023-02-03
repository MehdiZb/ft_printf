/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:39:19 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/05 18:39:21 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_split(char *str, char charset)
{
	int	len;

	len = 0;
	if (charset == '\0')
	{
		while (str[len])
			len++;
		return (len);
	}
	while (str[len])
	{
		if (str[len] == charset)
			break ;
		len++;
	}
	return (len);
}

static char	**ft_fill_tab(char *str, char charset, char **tab)
{
	int	j;
	int i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && str[i] != charset)
		{
			if (!(tab[j] = malloc(sizeof(char)
							* (ft_strlen_split((str + i), charset) + 1))))
				return ((void*)NULL);
			cmpt = 0;
			while (str[i] && str[i] != charset)
				tab[j][cmpt++] = str[i++];
			tab[j++][cmpt] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbwords;
	int		i;

	if (!s)
		return (0);
	nbwords = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nbwords++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab = 0;
	if (!(tab = malloc((sizeof(char*) * (nbwords + 1)))))
		return (0);
	return (ft_fill_tab((char*)s, c, tab));
}
