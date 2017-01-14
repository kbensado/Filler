/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:32:23 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/13 23:02:16 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void		set_seed____(t_env *env, int tab[4], t_seed **target, int j)
{
	int		i;
	int 	key;

	key = 0;
	i = tab[1];
	(void)env;
	while (j >= tab[2])
	{
		while (i <= tab[0])
		{
			if (target[i][j].key == 0)
				key = 1;
			else
				key = 0;
			key == 0 ? target[i][j].key = 5 : (int)key;
			i++;
		}
		j--;
		key = 0;
		i = tab[1];
	}
}

void		set_seed___(t_env *env, int tab[4], t_seed **target, int j)
{
	int		i;
	int 	key;

	key = 0;
	i = tab[1];
	(void)env;
	while (j <= tab[2])
	{
		while (i <= tab[0])
		{
			if (target[i][j].key == 0)
				key = 1;
			else
				key = 0;
			key == 0 ? target[i][j].key = 4 : (int)key;
			i++;
		}
		j++;
		key = 0;
		i = tab[1];
	}
}

void		set_seed__(t_env *env, int tab[4], t_seed **target, int i)
{
	int		j;
	int 	key;

	key = 0;
	j = tab[3];
	(void)env;
	while (i >= tab[0])
	{
		while (j <= tab[2])
		{
			if (target[i][j].key == 0)
				key = 1;
			else
				key = 0;
			key == 0 ? target[i][j].key = 7 : (int)key;
			j++;
		}
		i--;
		key = 0;
		j = tab[3];
	}
}


void		set_seed_(t_env *env, int tab[4], t_seed **target, int i)
{
	int		j;
	int key;

	key = 0;
	j = tab[3];
	(void)env;
	while (i <= tab[0])
	{
		while (j <= tab[2])
		{
			if (target[i][j].key == 0)
				key = 1;
			else
				key = 0;
			key == 0 ? target[i][j].key = 2 : (int)key;
			j++;
		}
		i++;
		key = 0;
		j = tab[3];
	}
}
