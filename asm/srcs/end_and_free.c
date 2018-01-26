/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:46:01 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/25 13:46:26 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ciao_bye_name(int i, header_t *op)
{
	if (op && i == 10)
		i = 11;
	if (i == 3 && error_msg == 2)
		ft_printf("Champion name should be on one line\n");
	else if (i == 3)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (i == 4 && error_msg == 2)
		ft_printf("Champion comment should be on one line\n");
	else if (i == 4)
		ft_printf("Champion comment too long (Max length 2048)\n");
	else if (i == 0)
		ft_printf("Syntax error at token\n");
	return (0);
}

int		ciao_bye(int i, char *str)
{
	if (i == 1)
	{
		ft_printf("Can't read source file %s\nThe file should be .s to be convert\n", str);
		return (0);
	}
	if (i == 2)
	{
		ft_printf("Can't read source file %s\nThe file can't be open, you should check the path\n", str);
		return (0);
	}
	return (1);
}

void	ciao_bye_bye(int i)
{
	if (i > 0)
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		_exit(0);
	}
}

int			freedom_for_list(t_champ *lab)
{
	t_champ	*end;

	end = lab->next;
	while (end)
	{
		lab->next = NULL;
		if (lab->label)
			free(lab->label);
		if (lab)
			free(lab);
		lab = end;
		end = lab->next;
	}
	if (lab->label)
		free(lab->label);
	if (lab)
		free(lab);
	return (1);
}

int		ciao_bye_bye_fr(int i, t_champ *champ)
{
	t_champ	*ciao;

	ciao = champ->next;
	while (ciao)
	{
		champ->next = NULL;
		if (champ->label)
			free(champ->label);
		champ = ciao;
		ciao = champ->next;
	}
	if (champ->label)
		free(champ->label);
	if (i == 1)
		ft_printf("ERROR\n");
	return (0);
}
