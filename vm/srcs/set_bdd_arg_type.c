/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bdd_arg_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:53:55 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 13:07:46 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_args_type4(t_bdd *bdd_i)
{
	bdd_i->ocp[1]->type_arg1 = 'r';
	bdd_i->ocp[1]->type_arg2 = 'r';
	bdd_i->ocp[1]->type_arg3 = 'd';
	bdd_i->ocp[2]->type_arg1 = 'r';
	bdd_i->ocp[2]->type_arg2 = 'd';
	bdd_i->ocp[2]->type_arg3 = 'd';
	bdd_i->ocp[3]->type_arg1 = 'r';
	bdd_i->ocp[3]->type_arg2 = 'd';
	bdd_i->ocp[3]->type_arg3 = 'r';
	bdd_i->ocp[4]->type_arg1 = 'r';
	bdd_i->ocp[4]->type_arg2 = 'i';
	bdd_i->ocp[4]->type_arg3 = 'd';
	bdd_i->ocp[5]->type_arg1 = 'r';
	bdd_i->ocp[5]->type_arg2 = 'i';
	bdd_i->ocp[5]->type_arg3 = 'r';
}

void	set_args_type3(t_bdd *bdd_i)
{
	bdd_i->ocp[1]->type_arg1 = 'r';
	bdd_i->ocp[1]->type_arg2 = 'd';
	bdd_i->ocp[1]->type_arg3 = 'r';
	bdd_i->ocp[2]->type_arg1 = 'd';
	bdd_i->ocp[2]->type_arg2 = 'r';
	bdd_i->ocp[2]->type_arg3 = 'r';
	bdd_i->ocp[3]->type_arg1 = 'd';
	bdd_i->ocp[3]->type_arg2 = 'd';
	bdd_i->ocp[3]->type_arg3 = 'r';
	bdd_i->ocp[4]->type_arg1 = 'i';
	bdd_i->ocp[4]->type_arg2 = 'r';
	bdd_i->ocp[4]->type_arg3 = 'r';
	bdd_i->ocp[5]->type_arg1 = 'i';
	bdd_i->ocp[5]->type_arg2 = 'd';
	bdd_i->ocp[5]->type_arg3 = 'r';
}

void	set_args_type2(t_bdd *bdd_i)
{
	bdd_i->ocp[1]->type_arg1 = 'r';
	bdd_i->ocp[1]->type_arg2 = 'd';
	bdd_i->ocp[1]->type_arg3 = 'r';
	bdd_i->ocp[2]->type_arg1 = 'r';
	bdd_i->ocp[2]->type_arg2 = 'i';
	bdd_i->ocp[2]->type_arg3 = 'r';
	bdd_i->ocp[3]->type_arg1 = 'd';
	bdd_i->ocp[3]->type_arg2 = 'd';
	bdd_i->ocp[3]->type_arg3 = 'r';
	bdd_i->ocp[4]->type_arg1 = 'd';
	bdd_i->ocp[4]->type_arg2 = 'i';
	bdd_i->ocp[4]->type_arg3 = 'r';
	bdd_i->ocp[5]->type_arg1 = 'i';
	bdd_i->ocp[5]->type_arg2 = 'd';
	bdd_i->ocp[5]->type_arg3 = 'r';
	bdd_i->ocp[6]->type_arg1 = 'i';
	bdd_i->ocp[6]->type_arg2 = 'i';
	bdd_i->ocp[6]->type_arg3 = 'r';
	bdd_i->ocp[7]->type_arg1 = 'd';
	bdd_i->ocp[7]->type_arg2 = 'r';
	bdd_i->ocp[7]->type_arg3 = 'r';
	bdd_i->ocp[8]->type_arg1 = 'i';
	bdd_i->ocp[8]->type_arg2 = 'r';
	bdd_i->ocp[8]->type_arg3 = 'r';
}

void	set_args_type1(t_bdd *bdd_i, int i)
{
	if (i == 1 || i == 12)
	{
		bdd_i->ocp[0]->type_arg1 = 'd';
		bdd_i->ocp[1]->type_arg1 = 'i';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'r';
	}
	else if (i == 2)
	{
		bdd_i->ocp[0]->type_arg1 = 'r';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[1]->type_arg1 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'i';
	}
	else if ((i >= 3 && i <= 7) || i == 9 || i == 10 || i == 13)
	{
		bdd_i->ocp[0]->type_arg1 = 'r';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[0]->type_arg3 = 'r';
	}
}

int		set_args_type(t_bdd *bdd_i, int i)
{
	set_args_type1(bdd_i, i);
	if (i >= 5 && i <= 7)
		set_args_type2(bdd_i);
	else if (i == 9 || i == 13)
		set_args_type3(bdd_i);
	else if (i == 10)
		set_args_type4(bdd_i);
	else if (i == 15)
		bdd_i->ocp[0]->type_arg1 = 'r';
	else if (i == 0 || i == 8 || i == 14 || i == 11)
		bdd_i->ocp[0]->type_arg1 = 'd';
	return (1);
}
