/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:54:41 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 14:01:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_putnbr(int	n)
{
	unsigned int	nb;

	nb = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	else if (n > 0)
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else if (nb < 10)
		ft_putchar(nb + 48);
}

int		sizeofnmint(int nb, int s, int n)
{
	unsigned int x;
	
	if (n < 0)
	{
		x = n * -1;
		s++;
		return (sizeofint(x, s += 1, 0));
	}
	else
	{
		x = n;
		return (sizeofint(x , s += 1, 0)); 
	}
}

int		ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		seek;

	i = 0;
	seek = 0;
	if (!(needle[i]))
		return (0);
	if (needle[i] && !(haystack[i]))
		return (0);
	if (len == 0 && ft_strlen((char *)needle) == 0)
		return (0);
	while (len >= 0 && ((char *)haystack)[i])
	{
		while (((char *)haystack)[(i + seek)] == ((char *)needle)[seek]
				&& ((char *)haystack)[i + seek])
			seek++;
		if (seek == ft_strlen((char *)needle) && i + seek <= (int)len)
			return ((char )haystack[i]);
		seek = 0;
		i++;
	}
	return (0);
}