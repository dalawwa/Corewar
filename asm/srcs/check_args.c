/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:21:43 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/08 14:07:40 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//same pour ceux qui ont aussi un label
/*
int		check_args_valid_with_label(char *str, int op, t_champ *list)
{
	char	**tab;

	list->params = ft_strsplit_three(str, ' ', '\t', ',');
	tab = ft_strsplit_three(str, ' ', '\t', ',');
	if (tab[2] && (op == 1 || op == 9 || op == 15 || op == 12) && (check_is_direct(tab[2], list, 1)))
		return (1);
	else if (tab[2] && tab[3] && (op == 2 || op == 13) && (check_is_indirect(tab[2], list, 1) || check_is_direct(tab[2], list, 1)) && (check_is_reg(tab[3], list, 2)))
		return (1);
	else if (tab[2] && tab[3] && op == 3 && check_is_reg(tab[2], list, 1) && (check_is_reg(tab[3], list, 2) || check_is_indirect(tab[3], list, 2)))
		return (1);
	else if (tab[2] && tab[3] && tab[4] && (op == 4 || op == 5) && check_is_reg(tab[2], list, 1) && check_is_reg(tab[3], list, 2) && check_is_reg(tab[4], list, 3))
		return (1);
	else if (tab[2] && tab[3] && tab[4] && (op == 6 || op == 7 || op == 8) && (check_is_reg(tab[2], list, 1) || check_is_indirect(tab[2], list, 1) || check_is_direct(tab[2], list, 1)) && (check_is_reg(tab[3], list, 2) || check_is_indirect(tab[3], list, 2) || check_is_direct(tab[3], list, 2)) && check_is_reg(tab[4], list, 3))
		return (1);
	else if (tab[2] && tab[3] && tab[4] && (op == 10 ||op == 14) && (check_is_reg(tab[2], list, 1) || check_is_indirect(tab[2], list, 1) || check_is_direct(tab[2], list, 1)) && (check_is_reg(tab[3], list, 2) || check_is_direct(tab[3], list, 2)) && check_is_reg(tab[4], list, 3))
		return (1);
	else if (tab[2] && tab[3] && tab[4] && op == 11 && check_is_reg(tab[2], list, 1) && (check_is_reg(tab[3], list, 2) || check_is_indirect(tab[3], list, 2) || check_is_direct(tab[3], list, 2)) && (check_is_reg(tab[4], list, 3) || check_is_direct(tab[4], list, 3)))
		return (1);
	else if (tab[2] && op == 16 && check_is_reg(tab[2], list, 1))
		return (1);
	return (0);
}
*/
//on va verifier pour chaque ligne si les arguments recus sont valides
//il faudrait checker aussi que la suite de la phrase est coherente
//il faudrait verfiier qu il n y a pas plus d arguments
int		check_args_valid(char **str, int opc)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if ((opc == 1 || opc == 9 || opc == 15 || opc == 12) && (check_is_direct(0, str, opc)))
		return (1);
	else if ((opc == 2 || opc == 13) && (check_is_indirect(1, str) || check_is_direct(1, str, opc)) && (check_is_reg(0, str)))
		return (1);
	else if (opc == 3 && check_is_reg(1, str) && (check_is_reg(0, str) || check_is_indirect(0, str)))
		return (1);
	else if ((opc == 4 || opc == 5) && check_is_reg(1, str) && check_is_reg(1, str) && check_is_reg(0, str))
		return (1);
	else if ((opc == 6 || opc == 7 || opc == 8) && (check_is_reg(1, str) || check_is_indirect(1, str) || check_is_direct(1, str, opc)) && (check_is_reg(1, str) || check_is_indirect(1, str) || check_is_direct(1, str, opc)) && check_is_reg(0, str))
		return (1);
	else if ((opc == 10 || opc == 14) && (check_is_reg(1, str) || check_is_indirect(1, str) || check_is_direct(1, str, opc)) && (check_is_reg(1, str) || check_is_direct(1, str, opc)) && check_is_reg(0, str))
		return (1);
	else if (opc == 11 && check_is_reg(1, str) && (check_is_reg(1, str) || check_is_indirect(1, str) || check_is_direct(1, str, opc)) && (check_is_reg(0, str) || check_is_direct(0, str ,opc)))
		return (1);
	else if (opc == 16 && check_is_reg(0, str))
		return (1);
	return (0);
}

/*
//on va compter le nombre de virgules pour savoir combien d arguments sont suppose etre dans la ligne.
void		add_number_args(t_champ *list)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (list->line[i] != '\0')
	{
		if (list->line[i] == ';' || list->line[i] == '#')
			break ;
		if (list->line[i] == ',')
			j++;
		i++;
	}
	list->nb_params = j + 1;
	if (list->op_code == 15 || list->op_code == 12 || list->op_code == 16 || list->op_code == 1)
		if (list->nb_params != 1)
			ciao_bye_bye(1);
	if (list->op_code == 2 || list->op_code == 3 || list->op_code == 13)
		if (list->nb_params != 2)
			ciao_bye_bye(1);
	if (list->op_code == 4 || list->op_code == 5 || list->op_code == 6 || list->op_code == 7 || list->op_code == 8 || list->op_code == 10 || list->op_code == 11 || list->op_code == 14)
		if (list->nb_params != 3)
			ciao_bye_bye(1);
}
*/
