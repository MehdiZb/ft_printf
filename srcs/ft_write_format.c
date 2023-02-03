/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:35:38 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/23 19:35:41 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_conv(t_pf_struct *pf,
	t_pf_conv **conv, unsigned long long int *ret_value)
{
	int	tmp;

	(void)pf;
	if ((*conv)->conv_type == 'n')
		ft_set_n(pf, *conv, *ret_value);
	if ((*conv)->width_str)
		*ret_value += ft_strlen((*conv)->width_str);
	if ((*conv)->res)
		*ret_value += (*conv)->res_len;
	if ((*conv)->left == 0 && (*conv)->width_str)
		write(1, (*conv)->width_str, ft_strlen((*conv)->width_str));
	if ((*conv)->res)
		write(1, (*conv)->res, (*conv)->res_len);
	if ((*conv)->left == 1 && (*conv)->width_str)
		write(1, (*conv)->width_str, ft_strlen((*conv)->width_str));
	tmp = (*conv)->end + 1;
	(*conv) = (*conv)->next;
	return (tmp);
}

int		ft_write_until_percent(t_pf_struct *pf,
	int cmpt, unsigned long long int *ret_value)
{
	int	tmp_cmpt;
	int	i;

	tmp_cmpt = cmpt;
	i = 0;
	while (pf->format[cmpt] && pf->format[cmpt] != '%')
	{
		i++;
		cmpt++;
	}
	write(1, pf->format + tmp_cmpt, i);
	*ret_value += i;
	return (cmpt);
}

int		ft_write_format(t_pf_struct *pf)
{
	int						cmpt;
	t_pf_conv				*tmp;
	unsigned long long int	ret_value;

	cmpt = 0;
	ret_value = 0;
	tmp = pf->first_conv;
	while (pf->format && pf->format[cmpt])
	{
		if (pf->format[cmpt] != '%')
			cmpt = ft_write_until_percent(pf, cmpt, &ret_value);
		else
			cmpt = ft_write_conv(pf, &tmp, &ret_value);
	}
	return ((int)ret_value);
}
