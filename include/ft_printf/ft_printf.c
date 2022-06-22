/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:11:30 by ylabbe            #+#    #+#             */
/*   Updated: 2022/05/05 15:38:12 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tfdata	init_tfdata(void)
{
	t_tfdata	tfdata;

	tfdata.count = 0;
	tfdata.value = 0;
	return (tfdata);
}

int	tf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	tf_putstr(char *format)
{
	if (format == NULL)
		return (write(1, "(null)", 6));
	return (write(1, format, tf_strlen(format)));
}

void	tf_cursor(char *format, t_tfdata *tfdata)
{
	if (format[tfdata->count] != '%')
		tfdata->value += tf_putchar(format[tfdata->count]);
	if (format[tfdata->count] == '%')
	{
		tfdata->count++;
		if (format[tfdata->count] == 'd' || format[tfdata->count] == 'i')
			tfdata->value += tf_putnbr(va_arg(tfdata->ap, int));
		else if (format[tfdata->count] == 'c')
			tfdata->value += tf_putchar((char)va_arg(tfdata->ap, int));
		else if (format[tfdata->count] == 's')
			tfdata->value += tf_putstr(va_arg(tfdata->ap, char *));
		else if (format[tfdata->count] == 'p')
			tfdata->value += tf_type_p(va_arg(tfdata->ap, void *),
					format[tfdata->count]);
		else if (format[tfdata->count] == 'x' || format[tfdata->count] == 'X')
			tfdata->value += tf_type_x(va_arg(tfdata->ap, unsigned int),
					format[tfdata->count]);
		else if (format[tfdata->count] == 'u')
			tfdata->value += tf_type_u(va_arg(tfdata->ap, unsigned int));
		else if (format[tfdata->count] == '%')
			tfdata->value += tf_putchar('%');
	}
}

int	ft_printf(const char *format, ...)
{
	t_tfdata	tfdata;

	tfdata = init_tfdata();
	va_start(tfdata.ap, (char *)format);
	while (format[tfdata.count])
	{
		tf_cursor((char *)format, &tfdata);
		tfdata.count++;
	}
	return (tfdata.value);
}
