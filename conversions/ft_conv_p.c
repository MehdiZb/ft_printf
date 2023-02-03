/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:11:49 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/23 18:49:23 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_p(t_pf_struct *pf, t_pf_conv *new_conv)
{
	long	ptr_long;
	long	ptr_cpy;
	size_t	cmpt;

	cmpt = 2;
	ptr_long = (long)va_arg(pf->ap, void*);
	ptr_cpy = ptr_long;
	while (ptr_cpy > 0)
	{
		ptr_cpy /= BASE_HEXA_LEN;
		cmpt++;
	}
	cmpt += (!ptr_cpy && !(new_conv->is_prec_set && !new_conv->prec)) ? 1 : 0;
	if (!(new_conv->res = ft_strnew(cmpt)))
		return (-1);
	new_conv->res[0] = '0';
	new_conv->res[1] = 'x';
	if (!(new_conv->is_prec_set && !new_conv->prec))
		ft_putnbr_base_in_str((unsigned long long)ptr_long, new_conv->res,
			BASE_HEXA, BASE_HEXA_LEN);
	new_conv->res_len = (int)ft_strlen(new_conv->res);
	return (ft_width(pf, new_conv));
}
