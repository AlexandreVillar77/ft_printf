/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:48 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:01:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printwidth1(t_print *print, int len)
{
	if (print->flag->width[0] > 0)
	{
		if (print->flag->flagZero == 0)
			while (print->flag->width[0] > len)
			{
				print->flag->width[0]--;
				ft_putchar(' ');
			}
		else
			while (print->flag->width[0] > len)
			{
				print->flag->width[0]--;
				ft_putchar('0');
			}
	}
}

void	printwidth2(int rtn, t_print *print, int len, int call)
{
	if (call == 1)
	{
		if (rtn == 0 && print->flag->flagPoint == 1 && print->flag->width[0] > 0)
			len = 0;
		if (print->flag->width[1] < 0 && print->flag->width[0] != 0)
			print->flag->width[1] = 0;
		print->flag->conswidth = print->flag->width[1];
		//printf("width 1 : %d \n", print->flag->width[1]);
		if (print->flag->width[1] > print->flag->width[0] && print->flag->width[0] > 0)
			print->flag->width[0] = print->flag->width[1];
		ft_print_space(print, len);
	}
	else if (call == 2)
	{
		if (rtn == 0 && print->flag->flagPoint == 0 && print->flag->width[0] != 0)
			len++;
		else if (rtn == 0 && print->flag->flagPoint == 1 && len == 1)
			len = 0;
		if (print->flag->width[0] < 0)
			if ((print->flag->width[0] * -1) < print->flag->conswidth && print->flag->conswidth > 0)
				print->flag->width[1] = print->flag->conswidth;
		print->flag->width[1] = print->flag->conswidth;
		if (print->flag->conswidth > len)
			len = 1;
		ft_print_space_less(print, len);
	}
}

int		sizeofint(unsigned int nb, int s, int n)
{
	if (n != 0)
	{
		s++;
		if (nb == 0 && n < 0)
			nb = n * -1;
		else
			nb = n;
		n = 0;
	}
	if (nb < 10)
		return (s);
	return (sizeofint(nb / 10, s += 1, n));
}

int		ft_atoi(char *str)
{
	long int		rtn;
	int				nb;

	rtn = 0;
	nb = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		nb = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rtn *= 10;
		rtn += *str - 48;
		str++;
	}
	return (rtn * nb);
}

int		ft_managetype1(char c, t_print *print)
{
	if (c == 'c')
		return (print1(print));
	else if (c == 's')
		return (ft_putstrarg(print));
	else if (c == 'd' || c == 'i')
		return (ft_putnbrarg(print));
	else if (c == 'p')
		return (unsinged_long_conv(print));
	else if (c == 'u')
		return (unsigned_put_nbr(print));
	else if (c == 'x')
		return (unsigned_put_nb_base(print));
	else if (c == 'X')
		return (unsigned_put_nb_maj_base(print));
	return (0);
}