/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:32 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 14:52:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_arg(const char *str, struct t_print *print)
{
	int		i;
	char	toprint;

	i = 0;
	toprint = 0;
	if (str[i] && str[i + 1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (str[i] && str[i] == '%')
		i++;
	fillflag((char *)(str + i), print);
	i += print->flag->nbchar;
	print->printedchar += ft_managetype1(str[i], print);
	return (i);
}

int		ft_read(struct t_print *print, const char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count--;
			i += ft_arg(str + i, print);
		}
		else
			ft_putchar(str[i]);
		count++;
		i++;
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int				rtn;
	struct	t_print *print;

	rtn = 0;
	
	print = initprint();
	va_start(print->va, str);
	rtn = ft_read(print, str);
	rtn += print->printedchar;
	va_end(print->va);
	free (print->flag);
	free (print);
	return (rtn);
}