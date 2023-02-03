/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:10:56 by mzblah            #+#    #+#             */
/*   Updated: 2019/11/15 14:11:00 by mzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>

/*
**  DEFINE
*/

# define CONV_CHARACTERS	"cspdiuxX%n"
# define BASE_HEXA			"0123456789abcdef"
# define BASE_HEXA_LEN		16
# define BASE_TEN			"0123456789"
# define BASE_TEN_LEN		10

# define NC					new_conv
# define CT					conv_type

# define F					format

/*
**  STRUCTURE
*/

typedef	struct		s_printf_number
{
	unsigned long long	nb;
	int					positive;
	int					nb_size;
}					t_pf_nb;

typedef	struct		s_printf_conversion
{
	char						*res;
	size_t						res_len;
	size_t						start;
	size_t						end;
	char						conv_type;
	int							left;
	int							zero;
	int							plus;
	int							space;
	int							width;
	int							is_width_set;
	char						*width_str;
	int							prec;
	int							is_prec_set;
	int							l;
	int							h;
	int							hashtag;
	int							apostrophe;
	void						*ptr_n;
	t_pf_nb						nb;
	struct s_printf_conversion	*next;
}					t_pf_conv;

typedef struct		s_printf_struct
{
	char		*format;
	int			indice;
	va_list		ap;
	t_pf_conv	*first_conv;
}					t_pf_struct;

int					ft_write_format(t_pf_struct *pf);
int					ft_conversion(t_pf_struct *pf);
void				ft_conv_lst_add_back(t_pf_conv **alst, t_pf_conv *new);
void				ft_str_toupper(char *str);
int					ft_new_number_str(t_pf_conv *new_conv,
						t_pf_nb *nb, size_t base);
void				ft_putnbr_base_in_str(unsigned long long nb,
						char *str, const char *base, int base_len);
int					ft_clear_list(t_pf_struct *pf, int end);

int					ft_conv_c_percent(t_pf_struct *pf, t_pf_conv *new_conv);
int					ft_conv_s(t_pf_struct *pf, t_pf_conv *new_conv);
int					ft_conv_p(t_pf_struct *pf, t_pf_conv *new_conv);
int					ft_conv_number(t_pf_struct *pf, t_pf_conv *new_conv);
int					ft_conv_n(t_pf_struct *pf, t_pf_conv *new_conv);
int					ft_set_n(t_pf_struct *pf,
						t_pf_conv *new_conv, unsigned long long int ret_value);

int					ft_width(t_pf_struct *pf, t_pf_conv *new_conv);
void				ft_move_sign(t_pf_conv *new_conv);

#endif
