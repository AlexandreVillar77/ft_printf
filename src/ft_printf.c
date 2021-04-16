/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:32 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:01:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_arg(const char *str, t_print *print)
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
	print->flag = initflag();
	fillflag((char *)(str + i), print);
	i += print->flag->nbchar;
	while ((str[i] >= '0' && str[i] <= '9' && str[i]) || (str[i] == '0' ||
			str[i] == '-' || str[i] == '.' || str[i] == '*'))
		i++;
	print->printedchar += ft_managetype1(str[i], print);
	//printf("width 1 : %d \nwidth 2 : %d \n", print->flag->width[0], print->flag->width[1]);
	resetflag(print->flag);
	return (i);
}

int		ft_read(t_print *print, const char *str)
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
		if (i > ft_strlen((char*)str))
			break;
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int			rtn;
	t_print		*print;

	rtn = 0;
	
	print = initprint();
	va_start(print->va, str);
	rtn = ft_read(print, str);
	rtn += print->printedchar;
	va_end(print->va);
	free(print);
	return (rtn);
}