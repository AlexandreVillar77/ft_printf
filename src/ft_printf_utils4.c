/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:45:08 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:01:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pre_manage_flag(char *str, t_print *print)
{
	int		d;

	d = 0;
	if ((str[0] <= '9' && str[0] > '0'))
		return (0);
	while (str[d] && (str[d] == '0' || str[d] == '-' || str[d] == '.' ||
			str[d] == '*'))
			d++;
	if (ft_strnstr(str, "0", d) == '0')
		print->flag->flagZero = 1;
	if (ft_strnstr(str, "-", d) == '-')
		print->flag->flagLess = 1;
	if (ft_strnstr(str, ".", d) == '.')
		print->flag->flagPoint = 1;
	return (d);
}

void	ft_print_space_less(t_print *print, int len)
{
	if (print->flag->width[0] < 0)
		print->flag->width[0] *= -1;
	if ((print->flag->width[0] < print->flag->width[1]) ||
		len == print->flag->width[0])
		return ;
	//printf(" ///  width0 = %d // width 1 = %d // len = %d \n", print->flag->width[0], print->flag->width[1], len);
	if (print->flag->width[0] <= len || print->flag->width[1] == 0)
		print->flag->width[0] -= len;
	while (print->flag->width[1] < print->flag->width[0])
	{
		ft_putchar(' ');
		print->flag->width[0]--;
	}
}

int		assign_rtn(t_print *print, int len)
{
	int		rtn;
	int		opt;

	opt = print->flag->width[0];
	if (opt < 0)
		opt *= -1;
	if (opt < print->flag->width[1] && print->flag->width[1] > len)
		rtn = print->flag->width[1];
	else if (opt > print->flag->width[1] && opt > len)
		rtn = opt;
	else if (opt < len)
		rtn = len;
	else
		rtn = opt;
	return (rtn);
}

int		checkifneg(int nb, t_print *print)
{
	int rtn;

	rtn = 0;
	if (nb < 0)
	{
		rtn++;
		ft_putchar('-');
		if (print->flag->width[0] > 0)
			print->flag->width[0] -= 1;
		else if (print->flag->width[0] < 0)
			print->flag->width[0] += 1;
	}
	if (nb == 0 && print->flag->width[0] == 0 &&
		print->flag->width[1] == 0)
	{
		rtn = -1;
	}
	return (rtn);
}

int		printZero(t_flag *flag)
{
	if (flag->flagLess == 0 && (flag->width[0] != 0 ||
	 	flag->width[1] > 0))
		return (1);
	else if (flag->flagLess == 1 && flag->width[0] != 0 && 
		flag->width[1] != 0)
		return (1);
	else
		return (0);	
}