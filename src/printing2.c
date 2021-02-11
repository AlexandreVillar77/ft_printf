/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:06 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:02:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		unsigned_put_nbr(t_print *print)
{
	int		rtn;
	unsigned int	nb;
	
	if (!(nb = va_arg(print->va, unsigned int)))
		return (0);
	rtn = ft_nblen((unsigned long int) nb, 10);
	if (print->flag->width[0] > rtn)
		rtn += print->flag->width[0] - rtn;
	if (print->flag->width[0] > ft_nblen((unsigned long int) nb, 10))
		if (print->flag->flagLess == 0)
			printwidth2(print, ft_nblen((unsigned long int)nb, 10), 1);
	ft_put_unsignednbr(nb);
	if (print->flag->flagLess == 1)
		printwidth2(print, ft_nblen((unsigned long int)nb, 10), 2);
	return (rtn);
}

int		unsigned_put_nb_base(t_print *print)
{
	unsigned int		nb;
	char	*n;
	int		rtn;
	
	if (!(nb = va_arg(print->va, unsigned int)))
		return (0);
	rtn = ft_nblen((unsigned long int)nb, 16);
	n = convertwithp((unsigned long int)nb, "0123456789abcdef");
	if (print->flag->width[0] > rtn)
		rtn += print->flag->width[0] - rtn;
	if (print->flag->width[0] > ft_nblen((unsigned long int)nb, 16))
		if (print->flag->flagLess == 0)
			printwidth2(print, ft_nblen((unsigned long int)nb, 16), 1);
	ft_putstr(n);
	if (print->flag->flagLess == 1)
		printwidth2(print, ft_nblen((unsigned long int)nb, 16), 2);
	free(n);
	return (rtn);
}

int		unsigned_put_nb_maj_base(t_print *print)
{
	unsigned int		nb;
	char	*n;
	int		rtn;
	
	if (!(nb = va_arg(print->va, unsigned int)))
		return (0);
	rtn = ft_nblen((unsigned long int)nb, 16);
	n = convertwithp((unsigned long int)nb, "0123456789ABCDEF");
	if (print->flag->width[0] > rtn)
		rtn += print->flag->width[0] - rtn;
	if (print->flag->width[0] > ft_nblen((unsigned long int)nb, 16))
		if (print->flag->flagLess == 0)
			printwidth2(print, ft_nblen((unsigned long int)nb, 16), 1);
	ft_putstr(n);
	if (print->flag->flagLess == 1)
		printwidth2(print, ft_nblen((unsigned long int)nb, 16), 2);
	free(n);
	return (rtn);
}