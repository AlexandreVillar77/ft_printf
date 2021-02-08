/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:20:06 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 13:37:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convertwithp(unsigned long int nb, char *base)
{
	char	*nbr;
	
	if (!(nbr = malloc(sizeof(char) * (ft_nblen(nb, ft_strlen(base)) + 1))))
		return (0);
	ft_putnbr_base(nb, "0123456789abcdef", nbr);
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