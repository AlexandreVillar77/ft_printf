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

void	ft_print_space_less(t_print *print, int len)
{
	if ((print->flag->width[0] * -1) < print->flag->width[1])
		return ;
	print->flag->width[0] += len + print->flag->width[1];
	while (print->flag->width[0] < 0)
	{
		ft_putchar(' ');
		print->flag->width[0]++;
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
	else
		rtn = len;
	return (rtn);
}