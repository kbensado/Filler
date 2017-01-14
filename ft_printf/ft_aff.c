/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:58:17 by kbensado          #+#    #+#             */
/*   Updated: 2016/12/21 00:00:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_affchar(t_e_print *env)
{
	if (env->flag1 == 1)
	{
		ft_putchar(env->c);
		env->nbrd++;
		ft_afflarg(env->largeur, 1, env);
		return ;
	}
	ft_afflarg(env->largeur, 1, env);
	ft_putchar(env->c);
	env->nbrd++;
}

static void	ft_affunb_next(t_e_print *env, char *str)
{
	if (env->ispreci == 1 && !ft_strcmp("0", str) && env->preci == 0)
	{
		if (env->charflag == '0' || env->largeur > 1)
		{
			ft_putchar(env->charflag);
			env->nbrd++;
		}
	}
	else
	{
		ft_putstr(str);
		env->nbrd += ft_strlen(str);
	}
	if (env->flag1 == 1)
		ft_afflargnb(env->largeur, ft_strlen(str), env);
	ft_memdel((void **)&str);
}

void		ft_affunb(unsigned long long nb, t_e_print *env)
{
	char	*str;

	str = ft_llutoa(nb);
	if (env->preci > (int)ft_strlen(str))
		env->largeur -= (env->preci - ft_strlen(str));
	if (env->flag1 == 0)
		ft_afflargnb(env->largeur, ft_strlen(str), env);
	else
		env->charflag = ' ';
	if (env->ispreci == 1 && env->preci > (int)ft_strlen(str))
	{
		env->nbrd += env->preci - ft_strlen(str);
		while (env->preci-- - ft_strlen(str) > 0)
			write(1, "0", 1);
	}
	ft_affunb_next(env, str);
}
