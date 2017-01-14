/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 04:05:45 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 04:44:06 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_nb_block(t_env *env, size_t i, size_t j)
{
	while (i < PLATE_WITDH)
	{
		while (j < PLATE_LENGHT)
		{
			if (MAP[i][j] == PL1 || MAP[i][j] == PL2)
			{
				PL_SCORE++;
				EN_SEED[i][j].seed = -1;
			}
			if (MAP[i][j] == EN1 || MAP[i][j] == EN2)
			{
				EN_SCORE++;
				PL_SEED[i][j].seed = -1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		start_algo(t_env *env)
{
	PL_SCORE = 0;
	EN_SCORE = 0;
	get_nb_block(env, 0, 0);

	PRINT("p1 = %d || p2 = %d\n", (int)PL_SCORE, (int)EN_SCORE);
}
