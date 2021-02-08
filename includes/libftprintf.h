/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:57:04 by marvin            #+#    #+#             */
/*   Updated: 2021/02/05 14:29:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

struct				t_flag{
	int		flagZero;
	int		flagLess;
	int		flagPoint;
	int		flagStar;
	int		width;
	int		nbchar;
};

struct				t_print{
	struct	t_flag	*flag;
	int				printedchar;
	va_list 		va;
	int 			error;
};

void				ft_putchar(char c);
int					ft_strlen(char *str);
int					ft_putstrarg(struct t_print *print);
void				ft_putnbr(int n);
void				ft_putstr(char *str);
int					sizeofint(unsigned int nb, int s, int n);
int					ft_strnstr(const char *haystack, const char *needle, size_t len);
void				printwidth1(struct t_print *print, int len);
void				printwidth2(struct t_print *print, int len);
void				fillflag(char *str, struct t_print *print);
int					ft_base(char *base);
int					basevalue(char *base, char c);
void				ft_putnbr_base(unsigned long int nb, char *base, char *dest);
int					inbase(char *base, char c);
int					ft_atoi_base(char *str, char *base);
void				ft_revtab(char *str);
int					ft_nblen(unsigned long int nb, int basel);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*convertwithp(unsigned long int nb, char *base);
int					unsinged_long_conv(struct t_print *print);
int					ft_putnbrarg(struct t_print *print);
int					print1(struct t_print *print);
int					sizeofnmint(int nb, int s, int n);
int					ft_atoi(char *str);
int					ft_managetype1(char c, struct t_print *print);
void				ft_put_unsignednbr(unsigned int	nb);
int					unsigned_put_nbr(struct t_print *print);
int					unsigned_put_nb_base(struct t_print *print);
int					unsigned_put_nb_maj_base(struct t_print *print);
int					ft_arg(const char *str, struct t_print *print);
int					ft_read(struct t_print *print, const char *str);
int					ft_printf(const char *str, ...);
struct	t_flag		*initflag();
struct	t_flag		*resetflag(struct t_flag *flag);
struct	t_print		*initprint();


#endif