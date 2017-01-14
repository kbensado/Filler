/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:15:42 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 04:42:32 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			set_env(t_env *env)
{
	static size_t	key = 0;

	H_WITDH = GET_H_WITDH;
	H_LENGHT = GET_H_LENGHT;
	env->plate.block = (PLATE_WITDH * PLATE_LENGHT) / 4;
	if (key == 0)
	{
		map_seed(env, 0, 0);
		key++;
	}
}

void				the_answer(t_env *env)
{
	size_t i = 0;
	set_env(env);
	if (env->player.player_seed == NULL || env->ennemy.ennemy_seed)
	{
		if (!(EN_SEED = (t_seed **)ft_memalloc(sizeof(t_seed *) * PLATE_WITDH)))
			exit(0);
		if (!(PL_SEED = (t_seed **)ft_memalloc(sizeof(t_seed *) * PLATE_WITDH)))
			exit(0);
		while (i < PLATE_WITDH)
		{
			if (!(PL_SEED[i] = ft_memalloc(sizeof(t_seed) * PLATE_LENGHT)))
				exit(0);
			if (!(EN_SEED[i] = ft_memalloc(sizeof(t_seed) * PLATE_LENGHT)))
				exit(0);
			i++;
		}
	}
	init_seed(env, env->player.player, -1, env->player.player_seed);
	piece_seed(env, env->player.player_seed, 0, 0);
	set_seed(env, env->player.player_seed);
	init_seed(env, env->ennemy.ennemy, -1, env->ennemy.ennemy_seed);
	piece_seed(env, env->ennemy.ennemy_seed, 0, 0);
	set_seed(env, env->ennemy.ennemy_seed);
	start_algo(env);
	TAB_C
	TAB_B
	TAB_E
	TAB_F
	// key == 0 ? 


	PRINT("hou YEAH\n");
}
