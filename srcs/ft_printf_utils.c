/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:25:55 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/23 18:58:43 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_toupper(char *str)
{
	size_t i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void	ft_new_number_str_add_length(t_pf_conv *new_conv,
		t_pf_nb *nb, int *cmpt, size_t *str_size)
{
	*cmpt = (new_conv->prec > *cmpt) ? new_conv->prec : *cmpt;
	*cmpt += (new_conv->hashtag && nb->nb) ? 2 : 0;
	*cmpt += (new_conv->apostrophe) ? (*cmpt - 1) / 3 : 0;
	*cmpt += (!nb->positive || new_conv->plus || new_conv->space) ? 1 : 0;
	*str_size = (new_conv->prec > *cmpt) ? new_conv->prec : *cmpt;
	*str_size = (new_conv->is_prec_set
			&& !new_conv->prec && !nb->nb) ? 0 : *str_size;
}

int		ft_new_number_str(t_pf_conv *new_conv, t_pf_nb *nb, size_t base)
{
	unsigned long long	value_cpy;
	size_t				str_size;
	size_t				cmpt_prec;
	int					cmpt;

	cmpt = 0;
	value_cpy = nb->nb;
	if (value_cpy == 0)
		cmpt++;
	while (value_cpy > 0)
	{
		value_cpy /= base;
		cmpt++;
	}
	nb->nb_size = cmpt;
	ft_new_number_str_add_length(new_conv, nb, &cmpt, &str_size);
	if (!(new_conv->res = ft_strnew(str_size)))
		return (-1);
	cmpt_prec = 0;
	if (new_conv->is_prec_set)
		while ((long)cmpt_prec < (long)(str_size - nb->nb_size))
			new_conv->res[cmpt_prec++] = '0';
	return (0);
}

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_move_sign(t_pf_conv *new_conv)
{
	if (new_conv->res && new_conv->width_str && new_conv->width_str[0] == '0')
	{
		if (new_conv->res[0] == ' '
			|| new_conv->res[0] == '+' || new_conv->res[0] == '-')
			ft_swap(&new_conv->res[0], &new_conv->width_str[0]);
		else if (new_conv->res[1] == 'x' || new_conv->res[1] == 'X')
		{
			if (!new_conv->width_str[1])
				ft_swap(&new_conv->res[0], &new_conv->res[1]);
			else
				ft_swap(&new_conv->res[1], &new_conv->width_str[1]);
		}
	}
}
