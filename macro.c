/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:12:40 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 03:51:17 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_witdh(t_env *env, int i, t_seed **target, size_t key)
{
	static int	res = 0;
	int			j;

	j = -1;
	key == 0 ? res = 0 : (int)res;
	while (key == 0 && ++i < (int)PLATE_WITDH)
	{
		while (++j < (int)PLATE_LENGHT)
		{
			if (target[i][j].key == 0)
				i > res ? res = i : (int)i;
		}
		j = -1;
	}
	while (key == 1 && ++i < (int)PLATE_WITDH)
	{
		while (++j < (int)PLATE_LENGHT)
		{
			if (target[i][j].key == 0)
				i < res ? res = i : (int)i;
		}
		j = -1;
	}
	return (res);
}

static int	get_lenght(t_env *env, int i, t_seed **target, size_t key)
{
	static int	res = 0;
	int 		j;

	j = -1;
	key == 0 ? res = 0 : (int)res;
	while (key == 0 && ++i < (int)PLATE_WITDH)
	{
		while (++j < (int)PLATE_LENGHT)
		{
			if (target[i][j].key == 0)
				j > res ? res = j : (int)i;
		}
		j = -1;
	}
	while (key == 1 && ++i < (int)PLATE_WITDH)
	{
		while (++j < (int)PLATE_LENGHT)
		{
			if (target[i][j].key == 0)
				j < res ? res = j : (int)i;
		}
		j = -1;
	}
	return (res);
}

int			*_macro_tab(int tab[] ,int a, int b)
{
	tab[0] = a;
	tab[1] = b;
	return (tab);
}

void		set_sko(int i, int j, t_seed **target)
{
	target[i][j].seed = 0;
	target[i][j].key = 0;
}

void		set_seed(t_env *env, t_seed **target)
{
	int		tab[4];

	tab[0] = get_witdh(env, -1, target, 0);
	tab[1] = get_witdh(env, -1, target, 1);
	tab[2] = get_lenght(env, -1, target, 0);
	tab[3] = get_lenght(env, -1, target, 1);
	set_seed_(env, tab, target, 0);
	set_seed__(env, tab, target, (int)PLATE_WITDH - 1);
	set_seed___(env, tab, target, 0);
	set_seed____(env, tab, target, (int)PLATE_LENGHT - 1);
}
