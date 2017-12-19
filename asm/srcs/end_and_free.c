/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:46:01 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/18 17:14:48 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


//improve syntax error at token
int		ciao_bye_name(int i, header_t *op)
{
	if (op)
		free(op);
	if (i == 3)
		ft_printf("Champion name too long (Max length 128)\n");
	if (i == 4)
		ft_printf("Champion comment too long (Max length 2048)\n");
	if (i == 0)
		ft_printf("Syntax error at token\n");
	return (0);
}

int		ciao_bye(int i, char *str)
{
	if (i == 1)
	{
		ft_printf("Can't read source file %s\n", str);
		return (0);
	}
	return (1);
}

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

int		ciao_bye_bye_fr(int i, t_champ *champ)
{
	while (champ->next)
	{
		if (champ->label)
			free(champ->label);
		champ = champ->next;
	}
	if (champ)
		free(champ);
	if (i == 1)
		ft_printf("ERROR\n");
	return (0);
}
