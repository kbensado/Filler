/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:51:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 02:22:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// static void		free_env(t_env *env)
// {
// 	if (env->map)
// 		ft_memdel((void **)env->map);
// }

int				main()
{
	t_env		env;

	env.plate.map = NULL;
	env.player.player_seed = NULL;
	env.ennemy.ennemy_seed = NULL;
	launch(&env);
	get_plate(&env);
	// PRINT("%c || %c\n%d || %d\n", env.player[0], env.player[1], env.witdh, env.lenght);
	// sleep(10);
	// free_env(&env);
	return (0);
}
