/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:40 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:02:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print	*initprint()
{
	t_print *print;

	if (!(print = malloc(sizeof(t_print) * 1)))
		return(0);
	print->printedchar = 0;
	print->error = 0;
	return (print);
}

void	resetflag(t_flag *flag)
{
	flag->flagLess = 0;
	flag->flagPoint = 0;
	flag->flagStar = 0;
	flag->flagZero = 0;
	flag->Printzero = 0;
	flag->nbchar = 0;
	flag->nbwidth = 0;
	flag->conswidth = 0;
	flag->width[0] = 0;
	flag->width[1] = 0;
	free(flag->width);
	free(flag);
}

t_flag	*initflag()
{
	t_flag	*flag;
	
	if (!(flag = malloc(sizeof(t_flag) * 1)))
		return (0);
	if (!(flag->width = malloc(sizeof(int) * 2)))
		return (0);
	flag->flagLess = 0;
	flag->flagPoint = 0;
	flag->flagStar = 0;
	flag->flagZero = 0;
	flag->Printzero = 0;
	flag->nbchar = 0;
	flag->nbwidth = 0;
	flag->conswidth = 0;
	flag->width[0] = 0;
	flag->width[1] = 0;
	return (flag);
}


void	fillflag(char *str, t_print *print)
{
	int		d;

	d = pre_manage_flag(str, print);
	if (ft_atoi(str + d) > 0)
	{
		print->flag->width[0] = ft_atoi(str + d);
		while (str[d] >= '0' && str[d] <= '9')
			d++;
		if (!(str[d] > 64 && str[d] < 91 || str[d] > 96 && str[d] < 123))
			str = str + d;
		print->flag->nbwidth = 1;
		d = 0;
	}
	flagstarmanage(str, print, d);
	while (str[d] && (str[d] == '0' || str[d] == '-' || str[d] == '.' ||
			str[d] == '*'))
			d++;
	if (ft_strnstr(str, "0", d) == '0')
		print->flag->flagZero = 1;
	if (ft_strnstr(str, "-", d) == '-')
		print->flag->flagLess = 1;
	if (ft_strnstr(str, ".", d) == '.')
		print->flag->flagPoint = 1;
	if (print->flag->width[0] < 0 && print->flag->flagPoint == 1)
		print->flag->width[0] = 1;
	ft_checkpointpos(print, str, d);
}

void	flagstarmanage(char *str, t_print *print, int d)
{
	if ((ft_strnstr(str, "*", d) == '*') && print->flag->width[0] == 0)
	{
		print->flag->width[0] = va_arg(print->va, int);
		d = 0;
		while (str[d] && str[d] != '*')
			d++;
		d++;
		print->flag->nbwidth = 1;
		str = str + d;
		d = 0;
	}
	while (str[d] && (str[d] == '0' || str[d] == '-' || str[d] == '.' ||
			str[d] == '*'))
			d++;
	if ((ft_strnstr(str, "*", d) == '*') && print->flag->width[1] == 0 && print->flag->nbwidth == 1)
		print->flag->width[1] = va_arg(print->va, int);
	if ((ft_atoi(str + d) != 0 || (str[d] >= '0' && str[d] <= '9'))&& print->flag->width[1] == 0 && print->flag->nbwidth == 1)
		print->flag->width[1] = ft_atoi(str + d);
	while ((str[d] >= '0' && str[d] <= '9' && str[d]) || (str[d] == '0' ||
			str[d] == '-' || str[d] == '.' || str[d] == '*'))
			d++;
	print->flag->nbchar += d;
}