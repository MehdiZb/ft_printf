/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:16:40 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/22 15:16:42 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_n(t_pf_struct *pf,
	t_pf_conv *new_conv, unsigned long long int ret_value)
{
	(void)pf;
	if (!new_conv->ptr_n)
		return (0);
	if (new_conv->h >= 2)
		*((char*)new_conv->ptr_n) = (signed char)ret_value;
	else if (new_conv->h == 1)
		*((short*)new_conv->ptr_n) = (short)ret_value;
	else if (new_conv->l >= 2)
		*((long long*)new_conv->ptr_n) = (long long)ret_value;
	else if (new_conv->l == 1)
		*((long*)new_conv->ptr_n) = (long)ret_value;
	else
		*((int*)new_conv->ptr_n) = (int)ret_value;
	return (0);
}

int	ft_conv_n(t_pf_struct *pf, t_pf_conv *new_conv)
{
	new_conv->ptr_n = va_arg(pf->ap, void*);
	return (0);
}
