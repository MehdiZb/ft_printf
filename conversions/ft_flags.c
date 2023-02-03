/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:39:16 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/18 15:39:23 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(t_pf_struct *pf, t_pf_conv *new_conv)
{
	int		str_len;
	int		width_len;
	int		cmpt;
	char	fill;

	(void)pf;
	if (!new_conv->is_width_set)
		return (0);
	str_len = new_conv->res_len;
	if ((width_len = new_conv->width - str_len) && width_len > 0)
		if (!(new_conv->width_str = ft_strnew((size_t)width_len)))
			return (-1);
	cmpt = 0;
	fill = (new_conv->zero != 0 && new_conv->left == 0
		&& ((new_conv->is_prec_set && new_conv->prec < 0)
			|| !new_conv->is_prec_set)) ? '0' : ' ';
	while (cmpt < width_len)
		new_conv->width_str[cmpt++] = fill;
	return (0);
}
