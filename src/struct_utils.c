/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:40 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 14:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

struct t_print	*initprint()
{
	struct t_print *print;

	if (!(print = malloc(sizeof(struct t_print) * 1)))
		return(0);
	print->flag = initflag();
	print->printedchar = 0;
	print->error = 0;
	return (print);
}

struct t_flag	*resetflag(struct t_flag *flag)
{
	flag->flagLess = 0;
	flag->flagPoint = 0;
	flag->flagStar = 0;
	flag->flagZero = 0;
	flag->nbchar = 0;
	return (flag);
}

struct t_flag	*initflag()
{
	struct t_flag	*flag;
	
	if (!(flag = malloc(sizeof(struct t_flag) * 1)))
		return (0);
	flag->flagLess = 0;
	flag->flagPoint = 0;
	flag->flagStar = 0;
	flag->flagZero = 0;
	flag->nbchar = 0;
	return (flag);
}

void	fillflag(char *str, struct t_print *print)
{
	int		d;

	d = 0;
	while (str[d] && (str[d] == '0' || str[d] == '-' || str[d] == '.' ||
			str[d] == '*'))
			d++;
	if (ft_strnstr(str, "0", d) == '0')
		print->flag->flagZero = 1;
	if (ft_strnstr(str, "-", d) == '-')
		print->flag->flagLess = 1;
	if (ft_strnstr(str, "*", d) == '*')
		print->flag->flagStar = 1;
	if (ft_strnstr(str, ".", d) == '.')
		print->flag->flagPoint = 1;
	if (print->flag->flagStar == 1)
		print->flag->width = va_arg(print->va, int);
	else 
		print->flag->width = ft_atoi(str + d);
	if (ft_atoi(str + d) > 0)
		d += sizeofnmint(0, 0, ft_atoi(str + d));
	print->flag->nbchar = d;
}