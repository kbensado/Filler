/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 05:31:57 by cmichaud          #+#    #+#             */
/*   Updated: 2016/12/21 00:00:40 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "../libft.h"

typedef struct			s_env
{
	int					flag1;
	int					flag2;
	int					flag3;
	int					flag4;
	char				charflag;
	int					largeur;
	int					preci;
	int					ispreci;
	int					modifh;
	int					modifl;
	int					modifj;
	int					modifz;
	char				convert;
	int					nbrd;
	short int			nbshort;
	long long			nb;
	unsigned long long	unb;
	int					isnb;
	char				*str;
	int					ispw;
	int					pw;
	int					c;
	int					len;
	wchar_t				wchar;
	wchar_t				*wstr;
	char				*base;
}						t_e_print;

void					ft_affchar(t_e_print *env);
void					ft_affunb(unsigned long long nb, t_e_print *env);
char					*ft_getflag(char *s, va_list *ap, t_e_print *env);
char					*ft_getpreci(char *s, va_list *ap, t_e_print *env);
void					ft_affnb(long long nb, t_e_print *env);
void					ft_affstr(t_e_print *env, const char *s);
int						ft_affelem(t_e_print *env);
void					ft_afflargnb(int larg, int size, t_e_print *env);
void					ft_afflarg(int larg, int size, t_e_print *env);
int						ft_putwchar_next(char a, wchar_t
	wchar, char *str, int nb);
void					ft_affo(t_e_print *env);
void					ft_affp(t_e_print *env);
void					ft_affx(t_e_print *env);
void					ft_convert(t_e_print *env);
void					ft_affconv(t_e_print *env);
int						ft_max(int a, int b, int c);
void					final_len(t_e_print *list, int len, int preci, int largeur);
int						ft_printf(char const *s, ...);
char					*ft_getflag(char *s, va_list *ap, t_e_print *env);
int						ft_aff(va_list *ap, t_e_print *env, char const *s);
int						ft_putwchar(wchar_t wchar, t_e_print *env, char a, char b);
int						ft_wcharlen(wchar_t wchar, t_e_print *env, int i);
void					ft_applywstrpreci(t_e_print *env);
void					ft_afflargwstr(t_e_print *env);

#endif
