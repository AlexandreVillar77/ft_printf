/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:22:06 by avillar           #+#    #+#             */
/*   Updated: 2021/02/11 14:01:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		inbase(char *base, char c)
{
	int	i;
	int ok;

	ok = 1;
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			ok--;
		i++;
	}
	return (ok);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int res;

	res = 0;
	sign = 1;
	if (ft_base(base) == 0)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (inbase(base, *str) == 0)
	{
		res = res * ft_strlen(base) + basevalue(base, *str);
		str++;
	}
	return (res * sign);
}

void	ft_revtab(char *str)
{
	int		i;
	char	swp;
	int		x;

	x = ft_strlen(str) - 1;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (i < x)
	{
		swp = str[i];
		str[i] = str[x];
		str[x] = swp;
		x--;
		i++;
	}
}

int		ft_nblen(unsigned long int nb, int basel)
{
	if (nb < (unsigned long int)basel)
		return (1);
	return (1 + (ft_nblen(nb / basel, basel)));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		size;
	char	*newnb;
	int		sign;

	if (ft_base(base_from) == 0 || ft_base(base_to) == 0)
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	size = ft_nblen(nb, ft_strlen(base_to));
	sign = 0;
	if (nb < 0)
		sign = 1;
	if (!(newnb = malloc(sizeof(char) * size + 1 + sign)))
		return (0);
	ft_putnbr_base(nb, base_to, newnb);
	ft_revtab(newnb);
	return (newnb);
}
