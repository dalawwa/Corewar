/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:32:33 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/13 15:34:08 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//on va verifier qu il s agit bien d un registre
//on va regarder si il commence par r et si il est compris entre 1 et 16
//on va mettre sa taille dans la struct
/*
int		check_is_reg(char *str, t_champ *list, int num)
{
	int		i;

	if (str[0] != 'r')
		return (0);
	i = ft_atoi(&str[1]);
	if (i > 16 || i < 1)
		return (0);
	if (num == 1)
		list->size_param1 = 1;
	else if (num == 2)
		list->size_param2 = 1;
	else if (num == 3)
		list->size_param3 = 1;
	return (1);
}*/
