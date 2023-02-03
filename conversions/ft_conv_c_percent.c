/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:39:21 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/21 20:40:03 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c_percent(t_pf_struct *pf, t_pf_conv *new_conv)
{
	char	*str;
	int		c;

	if (new_conv->conv_type == 'c')
		c = va_arg(pf->ap, int);
	else
		c = '%';
	if (new_conv->l && !(c >= 0 && c <= 255))
		return (-1);
	if (!(str = ft_strnew(1)))
		return (-1);
	str[0] = c;
	new_conv->res = str;
	new_conv->res_len = 1;
	return (ft_width(pf, new_conv));
}
