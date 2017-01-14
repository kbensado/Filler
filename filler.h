/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:54:13 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 04:22:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

/*
**	key dir :
**
**	↖ 1
**	↑ 2
**	↗ 3
**	← 4
**	→ 5
**	↙ 6
**	↓ 7 
**	↘ 8
**		FREE ALL THE SHIT ?
*/


#define TAB_C print_dir(env->player.player_seed, PLATE_WITDH, PLATE_LENGHT);
#define TAB_B print_seed(env->player.player_seed, PLATE_WITDH, PLATE_LENGHT);
#define TAB_D PRINT_TABI(PLAYER_SEED, PLATE_WITDH, PLATE_LENGHT);
#define TAB_E print_dir(env->ennemy.ennemy_seed, PLATE_WITDH, PLATE_LENGHT);
#define TAB_F print_seed(env->ennemy.ennemy_seed, PLATE_WITDH, PLATE_LENGHT);

#define PL_SEED env->player.player_seed
#define PL_SCORE env->player.score
#define PLAYER_SIGLE (env->player.player[0] || env->player.player[1])
#define PL1 env->player.player[0]
#define PL2 env->player.player[1]

#define EN_SEED env->ennemy.ennemy_seed
#define EN_SCORE env->ennemy.score
#define ENNEMY_SIGLE (env->ennemy.ennemy[0] || env->ennemy.ennemy[1])
#define EN1 env->ennemy.ennemy[0]
#define EN2 env->ennemy.ennemy[1]

#define MAP env->plate.map
#define PLATE env->plate.piece
#define SEED env->plate.map_seed
#define PLATE_WITDH env->plate.plate_witdh
#define PLATE_LENGHT env->plate.plate_lenght
#define	H_WITDH	env->plate.half_plate_witdh
#define	H_LENGHT env->plate.half_plate_lenght
#define PIECE_WITDH env->plate.piece_witdh
#define PIECE_LENGHT env->plate.piece_lenght

#define GET_H_WITDH PLATE_WITDH % 2 == 0 ? PLATE_WITDH / 2 : (PLATE_WITDH / 2) + 1
#define GET_H_LENGHT PLATE_LENGHT % 2 == 0 ? PLATE_LENGHT / 2 : (PLATE_LENGHT / 2)
#include "libft/libft.h"
#include "ft_printf/includes/ft_printf.h"
#include <stdio.h>

typedef	struct	s_user
{
	int			coord[4];
	int			key;

}				t_user;

typedef struct	s_seed
{
	int			seed;
	int			key;
			
}				t_seed;

typedef	struct	s_player
{
	t_seed		**player_seed;
	char		padding_0[8];
	size_t		score;
	char		player[2];
	char		padding_1[6];

}				t_player;

typedef	struct	s_ennemy
{
	t_seed		**ennemy_seed;
	char		padding_0[8];
	size_t		score;
	char		ennemy[2];
	char		padding_1[6];

}				t_ennemy;

typedef	struct	s_plate
{
	char 		**map;
	char 		**piece;
	int			**map_seed;
	size_t		plate_witdh;
	size_t		plate_lenght;
	size_t		piece_witdh;
	size_t		piece_lenght;
	size_t		half_plate_witdh;
	size_t		half_plate_lenght;
	size_t		block;

}				t_plate;

typedef struct	s_filler_env
{
	t_ennemy	ennemy;
	t_player	player;
	t_plate		plate;
	t_seed		**target;

}				t_env;




void			print_seed(t_seed **map, size_t w, size_t l);
void			print_dir(t_seed **map, size_t w, size_t l);

/*
**	algo.c
*/

void			start_algo(t_env *env);	

/*
**	launch.c
*/

void			get_size_plate(t_env *env, char *line);
void			get_plate(t_env *env);
void			launch(t_env *env);

/*
**	macro.c
*/

void			set_seed(t_env *env, t_seed **target);
int				*_macro_tab(int tab[], int a, int b);
void			macro_grow(t_env *env, int set[2], size_t key, int dir);
void			set_sko(int i, int j, t_seed **target);

/*
**	seed.c
*/

void			set_seed_(t_env *env, int tab[4], t_seed **target, int i);
void			set_seed__(t_env *env, int tab[4], t_seed **target, int i);
void			set_seed___(t_env *env, int tab[4], t_seed **target, int j);
void			set_seed____(t_env *env, int tab[4], t_seed **target, int j);

/*
**	set.c
*/

void			map_seed(t_env *env, size_t i, size_t j);
int				is_player(char str[2], char c);
void			init_seed(t_env *env, char target2[2], int j, t_seed **target);
int				piece_seed(t_env *env, t_seed **target, int j, size_t key);

/*
**	solve.c
*/

void			the_answer(t_env *env);

#endif
