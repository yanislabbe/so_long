/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:05:49 by ylabbe            #+#    #+#             */
/*   Updated: 2022/05/05 15:37:32 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_tfdata
{
	int		count;
	int		value;
	va_list	ap;
}	t_tfdata;

int		ft_printf(const char *format, ...);
int		tf_putchar(char c);
int		tf_strlen(char *format);
int		tf_putstr(char *format);
int		tf_putnbr(int nb);
int		tf_type_u(unsigned int n);
int		tf_type_x(unsigned long long nbr, char format);
int		tf_type_p(void *nbr, char format);
void	tf_cursor(char *format, t_tfdata *tfdata);

#endif
