/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:54 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:02:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		print1(t_print *print)
{
	char	c;
	int		i;

	if (!(c = (char)va_arg(print->va, int)))
		return (0);
	i = print->flag->width[0];
	if (print->flag->flagLess == 1)
	{
		ft_putchar(c);
		if (print->flag->flagPoint == 0)
			printwidth1(print, 1);
	}
	else
	{
		if (print->flag->flagPoint == 0)
			printwidth1(print, 1);
		ft_putchar(c);
	}
	if (i == 0)
		i = 1;
	return (i);
}

int		ft_putstrarg(t_print *print)
{
	char	*str;
	int		i;
	int		rtn;

	i = 0;
	if (!(str = va_arg(print->va, char*)))
		return (0);
	if (print->flag->width[0] > 0)
		rtn = print->flag->width[0];
	else
		rtn = ft_strlen(str);
	if (print->flag->width[0] > ft_strlen(str))
		if (print->flag->flagLess == 0 && print->flag->flagPoint == 0)
			printwidth1(print, ft_strlen(str));
	while (str[i] && (i < print->flag->width[0] || print->flag->width[0] == 0))
	{
		ft_putchar(str[i]);
		i++;
	}
	if (print->flag->flagLess == 1 && print->flag->flagPoint == 0)
		printwidth1(print, ft_strlen(str));
	return (rtn);
}

int		ft_putnbrarg(t_print *print)
{
	int		nb;
	int		rtn;

	nb = va_arg(print->va, int);
	rtn = assign_rtn(print, sizeofnmint( 0, 0, nb));
	if (print->flag->flagLess == 0 && (print->flag->width[0] != 0 || print->flag->width[1] > 0))
		printwidth2(print, sizeofnmint(0, 0, nb), 1);
	if (nb != 0 || (print->flag->width[0] != 0 || print->flag->width[1] > 0))
		ft_putnbr(nb);
	if (print->flag->flagLess == 1 || print->flag->width[0] < 0 || print->flag->width[1] > 0)
	{
		printwidth2(print, sizeofnmint(0, 0, nb), 2);
	}
	return (rtn);
}

int		unsinged_long_conv(t_print *print)
{
	unsigned long int		nb;
	char	*n;
	int		rtn;
	
	if (!(nb = (unsigned long int)(va_arg(print->va, void*))))
		return (0);
	rtn = ft_nblen(nb, 16);
	n = convertwithp(nb, "0123456789abcdef");
	if (print->flag->width[0] > rtn)
		rtn += print->flag->width[0] - rtn;
	ft_putstr("0x");
	if (print->flag->width[0] > ft_nblen(nb, 16))
		if (print->flag->flagLess == 0)
		{
			printwidth2(print, ft_nblen(nb, 16), 1);
			ft_putstr(n);
		}	
	if (print->flag->flagLess == 1)
	{
		printwidth2(print, ft_nblen(nb, 16), 1);
		ft_putstr(n);
	}
	print->printedchar += 2;
	free(n);
	return (rtn);
}