/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:20:06 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:01:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convertwithp(unsigned long int nb, char *base)
{
	char	*nbr;
	
	if (!(nbr = malloc(sizeof(char) * (ft_nblen(nb, ft_strlen(base)) + 1))))
		return (0);
	ft_putnbr_base(nb, base, nbr);
	ft_revtab(nbr);
	return (nbr);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_put_unsignednbr(unsigned int	nb)
{
	if (nb > 9)
	{
		ft_put_unsignednbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_checkpointpos(t_print *print, char *str, int d)
{
	int		i;

	i = 0;
	while (i < d && str[i] != '.' && str[i])
		i++;
	if (str[i - 1] != '*')
		if (str[i - 1] > '9' || str[i - 1] < '1')
			if (print->flag->width[0] != 0)
			{
				print->flag->Printzero = 1;
				if (print->flag->width[0] < 0)
					print->flag->width[1] = print->flag->width[0] * -1;
				else
					print->flag->width[1] = print->flag->width[0];
				print->flag->width[0] = 0;
			}
	
	/*if (str[i] == '.')
		while (i > 0)
		{
			if (str[i] == '*' || (str[i] > '0' && str[i] <= '9') && print->flag->width[0] == 0)
			{
				if (print->flag->width[1] > 0)
					print->flag->width[1] = 0;
				break;
			}
			i--;
		}*/
}

void	ft_print_space(t_print *print, int len)
{
	if (print->flag->flagLess == 0 && print->flag->flagZero == 1 &&
		 print->flag->width[1] == 0 &&
		  print->flag->width[0] > print->flag->width[1])
		{
			print->flag->width[1] = print->flag->width[0];
			print->flag->width[0] = 0;
		}
	while (print->flag->width[0] > print->flag->width[1] &&
			print->flag->width[0] > len && print->flag->flagLess == 0)
	{
		ft_putchar(' ');
		print->flag->width[0]--;
	}
	if (print->flag->width[1] < 0)
		print->flag->width[1] = 0;
	while (print->flag->width[1] > len && print->flag->width[1] != 0)
	{
		ft_putchar('0');
		print->flag->width[1]--;
	}
}