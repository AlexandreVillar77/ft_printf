/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:57:04 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 13:46:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_flag{
	int		flagZero;
	int		flagLess;
	int		flagPoint;
	int		flagStar;
	int		Printzero;
	int		nbwidth;
	int		conswidth;
	int		*width;
	int		nbchar;
}					t_flag;

typedef	struct		s_print{
	t_flag	*flag;
	int				printedchar;
	va_list 		va;
	int 			error;
}					t_print;

void				ft_putchar(char c);
int					ft_strlen(char *str);
int					ft_putstrarg(t_print *print);
void				ft_putnbr(int n);
void				ft_putstr(char *str);
int					sizeofint(unsigned int nb, int s, int n);
int					ft_strnstr(const char *haystack, const char *needle, size_t len);
void				printwidth1(t_print *print, int len);
void				printwidth2(int rtn, t_print *print, int len, int call);
void				ft_print_space_less(t_print *print, int len);
int					assign_rtn(t_print *print, int len);
void				fillflag(char *str, t_print *print);
int					ft_base(char *base);
int					checkifneg(int nb, t_print *print);
int					basevalue(char *base, char c);
int					printZero(t_flag *flag);
void				ft_putnbr_base(unsigned long int nb, char *base, char *dest);
int					inbase(char *base, char c);
int					ft_atoi_base(char *str, char *base);
void				ft_revtab(char *str);
int					ft_nblen(unsigned long int nb, int basel);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*convertwithp(unsigned long int nb, char *base);
void				ft_checkpointpos(t_print *print, char *str, int d);
void				ft_print_space(t_print *print, int len);
int					unsinged_long_conv(t_print *print);
int					ft_putnbrarg(t_print *print);
int					print1(t_print *print);
void				flagstarmanage(char *str, t_print *print, int d);
int					sizeofnmint(unsigned int nb, int s, int n, t_print *print);
int					ft_atoi(char *str);
int					pre_manage_flag(char *str, t_print *print);
int					ft_managetype1(char c, t_print *print);
void				ft_put_unsignednbr(unsigned int	nb);
int					unsigned_put_nbr(t_print *print);
int					unsigned_put_nb_base(t_print *print);
int					unsigned_put_nb_maj_base(t_print *print);
int					ft_arg(const char *str, t_print *print);
int					ft_read(t_print *print, const char *str);
int					ft_printf(const char *str, ...);
t_flag				*initflag();
void				resetflag(t_flag *flag);
t_print				*initprint();


#endif