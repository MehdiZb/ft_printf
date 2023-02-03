/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:47:09 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/23 18:51:38 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_s(t_pf_struct *pf, t_pf_conv *new_conv)
{
	char	*str;
	size_t	str_ln;
	size_t	cmpt;

	cmpt = 0;
	str = va_arg(pf->ap, char*);
	if (!str)
		str = "(null)";
	if (str)
	{
		str_ln = (new_conv->is_prec_set &&
			new_conv->prec < (int)ft_strlen(str) && new_conv->prec >= 0)
			? new_conv->prec : ft_strlen(str);
		if (!(new_conv->res = ft_strnew(str_ln)))
			return (-1);
		while (cmpt < str_ln && str)
			new_conv->res[cmpt++] = *(str++);
	}
	new_conv->res_len = ft_strlen(new_conv->res);
	return (ft_width(pf, new_conv));
}
