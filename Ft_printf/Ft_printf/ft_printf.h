/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:49:12 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/21 09:37:42 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "Libft/libft.h"

# define BASE_16	"0123456789abcdef"
# define BASE_16X	"0123456789ABCDEF"

typedef struct	s_printf
{
	int		width;
	int		precision;
	int		checkp;
	char	flag;
	char	zero;
	char	is_str;
	int		negative;
	int		pointer;
	char	*save;
	va_list	args;
	int		ret;
}				t_printf;

t_printf		*g_var;

int				ft_printf(const char *s, ...);
int				percentagecase(const char **s);
void			init(void);
int				flags(const char **s);
int				width_case(const char **s);
int				precision_case(const char **s);
int				base_case(const char **s);
int				number_case(const char **s);
int				hex_case(const char **s);
int				d_case(const char **s);
int				s_case(const char **s);
int				c_case(const char **s);
int				u_case(const char **s);
int				percent_case(const char **s);
int				p_case(const char **s);
int				ux_case(const char **s);
int				x_case(const char **s);
int				printnull(void);
int				print(void);
int				prefix_print(int len);
void			word_n_suffix_print(int len, int i);
void			ft_printchar(char c);
int				add_zero(int len);
char			*ft_utoa(unsigned int n);
char			*ft_hex_itoa(unsigned int n, const char *base);
char			*ft_hex_long_itoa(size_t n, const char *base);
int				prepare_print(void);

#endif
