/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:39:24 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/26 14:48:58 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	global_variables_size(void)
{
	line_error = 0;
	temp = 0;
	size_line = 0;
	position = 0;
}

void	start_struct_champ(t_champ *champ)
{
	champ->label = NULL;
	champ->position = 0;
	champ->next = NULL;
}
