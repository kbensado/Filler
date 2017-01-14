/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:58:29 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 03:54:26 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			print_dir(t_seed **map, size_t w, size_t l)
{
	size_t i = 0;
	size_t j = 0;
	// short a = 0x2190;
	while (i < w)
	{
		while (j < l)
		{
			PRINT("%2d ",map[i][j].key);
			j++;	
		}
		WS("");
		i++;
		j = 0;
	}
	WS("");
	WS("");
}

void			print_seed(t_seed **map, size_t w, size_t l)
{
	size_t i = 0;
	size_t j = 0;
	while (i < w)
	{
		while (j < l)
		{
			PRINT("%2d ", map[i][j].seed);
			j++;	
		}
		WS("");
		i++;
		j = 0;
	}
	WS("");
	WS("");
}


static void		it_grow(t_env *env, t_seed **target, int tab[2], size_t key)
{
	int			i;
	int			j;

	i = tab[0];
	j = tab[1];
	if ((i - 1) > -1 && ((j - 1) > 0) && (target[i - 1][j - 1].seed == - 1))
		target[i - 1][j - 1].seed = (int)key + 1;
	if ((i - 1) > -1 && (target[i - 1][j].seed == - 1))
		target[i - 1][j].seed = (int)key + 1;
	if ((i - 1) > -1 && ((j + 1) < (int)PLATE_LENGHT) && (target[i - 1][j + 1].seed == - 1))
		target[i - 1][j + 1].seed = (int)key + 1;
	if (((j - 1) > -1) && (target[i][j - 1].seed == - 1))
		target[i][j - 1].seed = (int)key + 1;
	if (((j + 1) < (int)PLATE_LENGHT) && (target[i][j + 1].seed == - 1))
		target[i][j + 1].seed = (int)key + 1;
	if ((i + 1) < (int)PLATE_WITDH && ((j - 1) > 0) && ((int)target[i + 1][j - 1].seed == - 1))
		target[i + 1][j - 1].seed = (int)key + 1;
	if ((i + 1) < (int)PLATE_WITDH && ((int)target[i + 1][j].seed == - 1))
		target[i + 1][j].seed = (int)key + 1;
	if ((i + 1) < (int)PLATE_WITDH && ((j + 1) < (int)PLATE_LENGHT) && (target[i + 1][j + 1].seed == - 1))
		target[i + 1][j + 1].seed = (int)key + 1;
}

int				piece_seed(t_env *env, t_seed **target, int j, size_t key)
{
	int			i;
	int			tab[2];

	i = -1;
	while (++i < (int)PLATE_WITDH)
	{
		while (j < (int)PLATE_LENGHT)
		{
			if (target[i][j].seed == (int)key)
			{
				tab[0] = i;
				tab[1] = j;
				it_grow(env, target, tab, key);
			}
			j++;
		}
		j = 0;
	}
	if ((target[PLATE_WITDH - 1][PLATE_LENGHT - 1].seed < 0)
		|| (target[0][0].seed < 0 || (target[0][PLATE_WITDH - 1].seed < 0))
		|| (target[0][PLATE_LENGHT - 1].seed < 0))
		return (piece_seed(env, target, 0, ++key));
	return (1);
}

void				init_seed(t_env *env, char target2[2], int j, t_seed **target)
{
	static int		key = 0;
	int				i;

	i = -1;
	while (++i < (int)PLATE_WITDH)
	{
		while (j < (int)PLATE_LENGHT)
		{
			key == 0 ? target[i][j].seed = -1 : (int)key;
			target[i][j].key = -1;
			if (key == 1 && is_player(target2, MAP[i][j]))
				set_sko(i, j, target);
			j++;
		}
		j = 0;
	}
	if (key == 0)
	{
		key++;
		init_seed(env, target2, 0, target);
	}
	key == 1 ? key = 0 : (int)key;
}

void			map_seed(t_env *env, size_t i, size_t j)
{
	if (!(env->plate.map_seed = (int **)ft_memalloctab(PLATE_WITDH, PLATE_LENGHT)))
		exit(0);
	while (i < PLATE_WITDH)
	{
		while (j < PLATE_LENGHT)
		{
			if (i < H_WITDH && j < H_LENGHT)
				env->plate.map_seed[i][j] = 1;
			if (i < H_WITDH && j > H_LENGHT)
				env->plate.map_seed[i][j] = 2;
			if (i > H_WITDH && j < H_LENGHT)
				env->plate.map_seed[i][j] = 3;
			if (i > H_WITDH && j > H_LENGHT)
				env->plate.map_seed[i][j] = 4;
			j++;
		}
		j = 0;
		i++;
	}
}

int			is_player(char str[2], char c)
{
	if (c != str[0] && c != str[1])
		return (0);
	return (1);
}
