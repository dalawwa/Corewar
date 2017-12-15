/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:39:24 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/06 14:45:00 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	global_variables_size(void)
{
	size_line = 0;
	position = 0;
}

void	start_struct_champ(t_champ *champ)
{
	
//	champ->line = NULL;
//	champ->name = NULL;
//	champ->op_code = '\0';
//	champ->is_label = 0;
	champ->label = NULL;
	champ->position = 0;
//	champ->params = NULL;
//	champ->size_param1 = 0;
//	champ->size_param2 = 0;
//	champ->size_param3 = 0;
//	champ->has_ocp = 0;
//	champ->ocp = '\0';
//	champ->size_octets = 0;
	champ->next = NULL;
	champ->prev = NULL;
}
