/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 00:08:00 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/14 02:06:54 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_piece(t_env *env)
{
	char		*line;
	size_t		i;

	i = 0;
	env->plate.piece = ft_memalloc(sizeof(char *) * ((size_t)PIECE_WITDH));
	while (get_next_line(0, &line))
	{
		if (match(line, "*got*"))
		{
			ft_strchr(line, env->player.player[0]) ? the_answer(env) : (void)i;
			// PRINT_TAB(env->piece, PIECE_WITDH);
			ft_strdel(&line);
			return ;
		}
		env->plate.piece[i] = ft_strsub(line, 0, (size_t)PIECE_LENGHT);
		i++;
		ft_strdel(&line);
	}

}

static void		get_map(t_env *env, size_t i)
{
	char	*line;
	char	**buff;

	env->plate.map = ft_memalloc(sizeof(char *) * ((size_t)PLATE_WITDH));
	while (get_next_line(0, &line))
	{
		if (match(line, "Piece*"))
		{
			buff = ft_strsplit(line, ' ');
			PIECE_WITDH = (size_t)ft_atoi(buff[1]);
			PIECE_LENGHT = (size_t)ft_atoi(buff[2]);
			ft_del_tab(buff, 3);
			ft_strdel(&line);
			get_piece(env);
			return ;
		}
		env->plate.map[i] = ft_strsub(line, 4, (size_t)PLATE_LENGHT);
		i++;
		ft_strdel(&line);
	}
}

void		get_size_plate(t_env *env, char *line)
{
	char	**buff;

	buff = ft_strsplit(line, ' ');
	PLATE_WITDH = (size_t)ft_atoi(buff[1]);
	PLATE_LENGHT = (size_t)ft_atoi(buff[2]);
	ft_del_tab(buff, 3);
	ft_strdel(&line);
}


void		get_plate(t_env *env)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (match(line, "fin*"))
			exit(1);
		if (match(line, "Plateau*"))
		{
			get_size_plate(env, line);
			get_next_line(0, &line);
			ft_strdel(&line);
			get_map(env, 0);
			// PRINT_TAB(env->map, PLATE_WITDH);
			ft_del_tab(env->plate.map, PLATE_WITDH);
			ft_del_tab(env->plate.piece, PIECE_WITDH);
		}
		ft_strdel(&line);
	}
}

void		launch(t_env *env)
{
	char	*line;

	while(get_next_line(0, &line))
	{
		if (match(line, "*p1*kbensado*"))
		{
			env->player.player[0] = 'O';
			env->player.player[1] = 'o';
			env->ennemy.ennemy[0] = 'X';
			env->ennemy.ennemy[1] = 'x';
			ft_strdel(&line);
			return ;
		}
		if (match(line, "*p2*kbensado*"))
		{
			env->player.player[0] = 'X';
			env->player.player[1] = 'x';
			env->ennemy.ennemy[0] = 'O';
			env->ennemy.ennemy[1] = 'o';
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
}
