/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:27:47 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/23 19:27:49 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_idx(char *str, int *idx)
{
	int res;

	res = 0;
	while (ft_isdigit(str[*idx]))
		res = (res * 10) + (str[(*idx)++] - 48);
	--(*idx);
	return (res);
}

void	ft_init_conv_first_part(t_pf_conv *new_conv, char c)
{
	if (c == '-')
		new_conv->left = 1;
	else if (c == '0')
		new_conv->zero = 1;
	else if (c == '+')
		new_conv->plus = 1;
	else if (c == ' ')
		new_conv->space = 1;
	else if (c == '\'')
		new_conv->apostrophe = 1;
	else if (c == '#')
		new_conv->hashtag = 1;
	else if (c == 'l')
		new_conv->l++;
	else if (c == 'h')
		new_conv->h++;
}

void	ft_init_conv_second_part(t_pf_struct *pf,
	t_pf_conv *new_conv, char c, int *tmp)
{
	int star;

	if (c == '*')
	{
		star = (int)va_arg(pf->ap, int);
		if (star < 0)
		{
			new_conv->left = 1;
			new_conv->width = -star;
		}
		else
			new_conv->width = star;
		new_conv->is_width_set = 1;
	}
	else if (c == '.')
	{
		if (pf->format[++(*tmp)] == '*')
			new_conv->prec = (int)va_arg(pf->ap, int);
		else if (ft_isdigit(pf->format[*tmp]))
			new_conv->prec = ft_atoi_idx(pf->format, tmp);
		else
			*tmp = *tmp - 1;
		new_conv->is_prec_set = 1;
	}
}

void	ft_init_pf_conv(t_pf_struct *pf, t_pf_conv *new_conv)
{
	int	tmp;

	ft_bzero(new_conv, sizeof(*new_conv));
	new_conv->start = pf->indice;
	tmp = ++pf->indice;
	while (pf->F[tmp]
		&& (ft_is_char_in_str(pf->F[tmp], CONV_CHARACTERS)) == -1)
	{
		if (pf->F[tmp] == '-' || pf->F[tmp] == '0' || pf->F[tmp] == '+'
			|| pf->F[tmp] == ' ' || pf->F[tmp] == '\'' || pf->F[tmp] == '#'
				|| pf->F[tmp] == 'l' || pf->F[tmp] == 'h')
			ft_init_conv_first_part(new_conv, pf->F[tmp]);
		else if (pf->F[tmp] == '*' || pf->F[tmp] == '.')
			ft_init_conv_second_part(pf, new_conv, pf->F[tmp], &tmp);
		else if (ft_isdigit(pf->F[tmp]))
		{
			new_conv->width = ft_atoi_idx(pf->format, &tmp);
			new_conv->is_width_set = 1;
		}
		tmp++;
	}
	new_conv->end = tmp;
	new_conv->conv_type = pf->F[tmp];
	pf->indice = ++tmp;
}

int		ft_conversion(t_pf_struct *pf)
{
	t_pf_conv	*new_conv;

	if (!(new_conv = (t_pf_conv *)malloc(sizeof(*new_conv))))
		return (-1);
	ft_bzero(((void *)new_conv), sizeof(*new_conv));
	ft_init_pf_conv(pf, new_conv);
	ft_conv_lst_add_back(&pf->first_conv, new_conv);
	if (new_conv->conv_type == 'c' || new_conv->conv_type == '%')
		return (ft_conv_c_percent(pf, new_conv));
	else if (new_conv->conv_type == 's')
		return (ft_conv_s(pf, new_conv));
	else if (new_conv->conv_type == 'p')
		return (ft_conv_p(pf, new_conv));
	else if (NC->CT == 'n')
		return (ft_conv_n(pf, new_conv));
	else if (NC->CT == 'x' || NC->CT == 'X'
		|| NC->CT == 'd' || NC->CT == 'i' || NC->CT == 'u')
		return (ft_conv_number(pf, new_conv));
	return (-1);
}
