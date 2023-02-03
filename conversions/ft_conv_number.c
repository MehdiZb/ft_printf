/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:20:47 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/22 16:20:50 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_nb	ft_get_unsigned_value(t_pf_struct *pf, t_pf_conv *new_conv)
{
	t_pf_nb				nb;

	if (new_conv->h >= 2)
		nb.nb = (unsigned long long)((unsigned char)va_arg(pf->ap, int));
	else if (new_conv->h == 1)
		nb.nb = (unsigned long long)((unsigned short)va_arg(pf->ap, int));
	else if (new_conv->l >= 2)
		nb.nb = (unsigned long long)va_arg(pf->ap, unsigned long long);
	else if (new_conv->l == 1)
		nb.nb = (unsigned long long)va_arg(pf->ap, unsigned long);
	else
		nb.nb = (unsigned long long)va_arg(pf->ap, unsigned int);
	nb.positive = 1;
	return (nb);
}

t_pf_nb	ft_get_value(t_pf_struct *pf, t_pf_conv *new_conv)
{
	t_pf_nb		nb;
	long long	value;

	if (new_conv->conv_type == 'u' || new_conv->conv_type == 'x'
		|| new_conv->conv_type == 'X')
		return (ft_get_unsigned_value(pf, new_conv));
	else if (new_conv->h >= 2)
		value = (long long)((signed char)va_arg(pf->ap, int));
	else if (new_conv->h == 1)
		value = (long long)((short)va_arg(pf->ap, int));
	else if (new_conv->l >= 2)
		value = (long long)va_arg(pf->ap, long long);
	else if (new_conv->l == 1)
		value = (long long)va_arg(pf->ap, long);
	else
		value = (long long)va_arg(pf->ap, int);
	nb.positive = (value >= 0) ? 1 : 0;
	nb.nb = (unsigned long long)(value >= 0) ? value : -value;
	return (nb);
}

void	ft_putnbr_base_in_str(unsigned long long nb,
	char *str, const char *base, int base_len)
{
	size_t	cmpt;

	cmpt = 0;
	if (nb >= (unsigned)base_len)
	{
		ft_putnbr_base_in_str(nb / base_len, str, base, base_len);
		ft_putnbr_base_in_str(nb % base_len, str, base, base_len);
	}
	else
	{
		while (str[cmpt])
			cmpt++;
		str[cmpt] = base[nb];
	}
}

void	ft_add_hex_and_sep(t_pf_conv *new_conv, t_pf_nb *nb)
{
	int	cmpt;
	int	cpy;

	cmpt = 0;
	if (!nb->positive)
		new_conv->res[cmpt++] = '-';
	else if (new_conv->plus || new_conv->space)
		new_conv->res[cmpt++] = (new_conv->plus) ? '+' : ' ';
	if (new_conv->hashtag && nb->nb && (new_conv->res[cmpt++] = '0'))
		new_conv->res[cmpt++] = 'x';
	while (new_conv->res[cmpt])
		cmpt++;
	if (new_conv->apostrophe && (cpy = nb->nb_size))
		while (cpy > 0)
		{
			if (cpy % 3 == 0 && cpy != nb->nb_size)
				new_conv->res[(cmpt++) + (nb->nb_size - (cpy--))] = ',';
			cpy--;
		}
}

int		ft_conv_number(t_pf_struct *pf, t_pf_conv *new_conv)
{
	t_pf_nb	nb;
	char	*base;
	int		base_len;

	nb = ft_get_value(pf, new_conv);
	base = (new_conv->conv_type == 'x'
		|| new_conv->conv_type == 'X') ? BASE_HEXA : BASE_TEN;
	base_len = (base == BASE_HEXA) ? BASE_HEXA_LEN : BASE_TEN_LEN;
	if (ft_new_number_str(new_conv, &nb, base_len) == -1)
		return (-1);
	if (!(new_conv->is_prec_set && !new_conv->prec && !nb.nb))
	{
		ft_add_hex_and_sep(new_conv, &nb);
		ft_putnbr_base_in_str(nb.nb, new_conv->res, base, base_len);
	}
	if (new_conv->conv_type == 'X')
		ft_str_toupper(new_conv->res);
	new_conv->res_len = (int)ft_strlen(new_conv->res);
	if (ft_width(pf, new_conv) == -1)
		return (-1);
	ft_move_sign(new_conv);
	return (0);
}
