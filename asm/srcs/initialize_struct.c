/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:39:24 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:11:00 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	global_variables_size(void)
{
	g_line_error = 0;
	g_temp = 0;
	g_size_line = 0;
	g_position = 0;
}

void	start_struct_champ(t_champ *champ)
{
	champ->label = NULL;
	champ->position = 0;
	champ->next = NULL;
}
