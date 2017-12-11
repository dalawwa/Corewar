/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:21:43 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/11 20:26:08 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


//not finish, some special moment where param should be equal to 2
int		check_is_direct(char *str, t_champ *list, int num)
{
	int	i;

	i = 1;
	if (str[0] != '%')
		return (0);
	if (str[i] == ':')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (num == 1)
		list->size_param1 = 4;
	else if (num == 2)
		list->size_param2 = 4;
	else if (num == 3)
		list->size_param3 = 4;
	return (1);
}

int		check_is_indirect(char *str, t_champ *list, int num)
{
	int	i;

	i = 0;
	if (str[i] == ':')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (num == 1)
		list->size_param1 = 2;
	else if (num == 2)
		list->size_param2 = 2;
	else if (num == 3)
		list->size_param3 = 2;
	return (1);
}

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
}


//on va verifier pour chaque ligne si les arguments recus sont valides
//il faudrait checker aussi que la suite de la phrase est coherente
//il faudrait verfiier qu il n y a pas plus d arguments
int		check_args_valid(char *str, int op, t_champ *list)
{
	char	**tab;
	int		i;
	int		j;
	int		g;

	i = 1;
	j = 2;
	g = 3;
	if (list->is_label_and == 1)
	{
		i++;
		j++;
		g++;
	}
	list->params = ft_strsplit_three(str, ' ', '\t', ',');
	tab = ft_strsplit_three(str, ' ', '\t', ',');
	if (tab[i] && (op == 1 || op == 9 || op == 15 || op == 12) && (check_is_direct(tab[i], list, 1)))
		return (1);
	else if (tab[i] && tab[j] && (op == 2 || op == 13) && (check_is_indirect(tab[i], list, 1) || check_is_direct(tab[i], list, 1)) && (check_is_reg(tab[j], list, 2)))
		return (1);
	else if (tab[i] && tab[j] && op == 3 && check_is_reg(tab[i], list, 1) && (check_is_reg(tab[j], list, 2) || check_is_indirect(tab[j], list, 2)))
		return (1);
	else if (tab[i] && tab[j] && tab[g] && (op == 4 || op == 5) && check_is_reg(tab[i], list, 1) && check_is_reg(tab[j], list, 2) && check_is_reg(tab[g], list, 3))
		return (1);
	else if (tab[i] && tab[j] && tab[g] && (op == 6 || op == 7 || op == 8) && (check_is_reg(tab[i], list, 1) || check_is_indirect(tab[i], list, 1) || check_is_direct(tab[i], list, 1)) && (check_is_reg(tab[j], list, 2) || check_is_indirect(tab[j], list, 2) || check_is_direct(tab[j], list, 2)) && check_is_reg(tab[g], list, 3))
		return (1);
	else if (tab[i] && tab[j] && tab[g] && (op == 10 ||op == 14) && (check_is_reg(tab[i], list, 1) || check_is_indirect(tab[i], list, 1) || check_is_direct(tab[i], list, 1)) && (check_is_reg(tab[j], list, 2) || check_is_direct(tab[j], list, 2)) && check_is_reg(tab[g], list, 3))
		return (1);
	else if (tab[i] && tab[j] && tab[g] && op == 11 && check_is_reg(tab[i], list, 1) && (check_is_reg(tab[j], list, 2) || check_is_indirect(tab[j], list, 2) || check_is_direct(tab[j], list, 2)) && (check_is_reg(tab[g], list, 3) || check_is_direct(tab[g], list, 3)))
		return (1);
	else if (tab[1] && op == 16 && check_is_reg(tab[i], list, 1))
		return (1);
	return (0);
}


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
