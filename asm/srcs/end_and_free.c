/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:46:01 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/29 11:13:23 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//quitter l ex en cas de pb
////il faudra rajouter les struct pour tout free
void	ciao_bye_bye(int i)
{
	if (i > 0)
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		_exit(0);
	}
}

