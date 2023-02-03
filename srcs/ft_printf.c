/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:05:18 by mzblah            #+#    #+#             */
/*   Updated: 2019/12/05 17:16:29 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_clear_list(t_pf_struct *pf, int end)
{
	t_pf_conv	*tmp;
	t_pf_conv	*tmp_cpy;

	tmp = 0;
	if (pf)
	{
		tmp = pf->first_conv;
		while (tmp)
		{
			if (tmp->res)
				free(tmp->res);
			if (tmp->width_str)
				free(tmp->width_str);
			tmp_cpy = tmp;
			tmp = tmp->next;
			free(tmp_cpy);
		}
		pf->format = 0;
		if (end)
			free(pf);
	}
	return (-1);
}

void	ft_conv_lst_add_back(t_pf_conv **alst, t_pf_conv *new)
{
	t_pf_conv *tmp;

	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
}

int		ft_printf(const char *format, ...)
{
	t_pf_struct	*pf;
	int			ret;

	if (!(pf = (t_pf_struct *)malloc(sizeof(t_pf_struct))))
		return (-1);
	ft_bzero(pf, sizeof(*pf));
	pf->format = (char *)format;
	va_start(pf->ap, format);
	while (pf->format && pf->format[pf->indice])
	{
		if (pf->format[pf->indice] == '%')
		{
			if (ft_conversion(pf) == -1)
				return (ft_clear_list(pf, 1));
		}
		else
			++pf->indice;
	}
	va_end(pf->ap);
	ret = ft_write_format(pf);
	ft_clear_list(pf, 1);
	return (ret);
}

/*
**#include <stdio.h>
**
**int	main(void)
**{
**	unsigned long long ultra = 1251;
**
**	ft_printf("\nllX = %llu\n", ultra);
**	printf("\nllX = %llu\n", ultra);
**	return (0);
**}
*/
