/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:19:14 by avillar           #+#    #+#             */
/*   Updated: 2021/02/11 14:01:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[j])
	{
		if (base[j] == '-' || base[j] == '+' || base[j] == ' ' ||
				base[j] <= 32 || base[j] > 126)
			return (0);
		i = j + 1;
		while (base[i])
		{
			if (base[i] == base[j])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		basevalue(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long int nb, char *base, char *dest)
{
	int			i;

	i = 0;
	if (nb == 0)
	{
		dest[i] = base[0];
		i++;
	}
	else if (nb < 0)
	{
		dest[0] = '-';
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		dest[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i++;
	}
	dest[i] = '\0';
}
