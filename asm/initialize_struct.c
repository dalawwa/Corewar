/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:39:24 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/28 15:44:16 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	start_struct_champ(t_champ *champ)
{
	champ->line = NULL;
	champ->op = NULL;
	champ->is_label = 0;
	champ->position = 0;
	champ->params = NULL;
	champ->next = NULL;
	champ->prev = NULL;
}
