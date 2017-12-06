/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:21:43 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/06 14:46:24 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_is_direct(char *str)
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
	return (1);
}

int		check_is_indirect(char *str)
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
	return (1);
}

int		check_is_reg(char *str)
{
	int		i;

	if (str[0] != 'r')
		return (0);
	i = ft_atoi(&str[1]);
	if (i > 16 || i < 1)
		return (0);
	return (1);
}


//on va verifier pour chaque ligne si les arguments recus sont valides
//il faudrait checker aussi que la suite de la phrase est coherente
//il faudrait verfiier qu il n y a pas plus d arguments
int		check_args_valid(char *str, int op)
{
	char	**tab;

	tab = ft_strsplit_three(str, ' ', '\t', ',');
	if (tab[1] && (op == 1 || op == 9 || op == 15 || op == 12) && (check_is_direct(tab[1])))
		return (1);
	else if (tab[1] && tab[2] && (op == 2 || op == 13) && (check_is_indirect(tab[1]) || check_is_direct(tab[1])) && (check_is_reg(tab[2])))
		return (1);
	else if (tab[1] && tab[2] && op == 3 && check_is_reg(tab[1]) && (check_is_reg(tab[2]) || check_is_indirect(tab[2])))
		return (1);
	else if (tab[1] && tab[2] && tab[3] && (op == 4 || op == 5) && check_is_reg(tab[1]) && check_is_reg(tab[2]) && check_is_reg(tab[3]))
		return (1);
	else if (tab[1] && tab[2] && tab[3] && (op == 6 || op == 7 || op == 8) && (check_is_reg(tab[1]) || check_is_indirect(tab[1]) || check_is_direct(tab[1])) && (check_is_reg(tab[2]) || check_is_indirect(tab[2]) || check_is_direct(tab[2])) && check_is_reg(tab[3]))
		return (1);
	else if (tab[1] && tab[2] && tab[3] && (op == 10 ||op == 14) && (check_is_reg(tab[1]) || check_is_indirect(tab[1]) || check_is_direct(tab[1])) && (check_is_reg(tab[2]) || check_is_direct(tab[2])) && check_is_reg(tab[3]))
		return (1);
	else if (tab[1] && tab[2] && tab[3] && op == 11 && check_is_reg(tab[1]) && (check_is_reg(tab[2]) || check_is_indirect(tab[2]) || check_is_direct(tab[2])) && (check_is_reg(tab[3]) || check_is_direct(tab[3])))
		return (1);
	else if (tab[1] && op == 16 && check_is_reg(tab[1]))
		return (1);
	return (0);
}

void		add_number_args(t_champ *list)
{
	int		i;
	int		j;

	j = 0;
	list = list->next;
	while (list->next)
	{
		j = 0;
		i = 0;
		while (list->is_label == 1 && list->next)
			list = list->next;
		if (list->next == NULL)
			break ;
		while (list->line[i] != '\0')
		{
			if (list->line[i] == ',')
				j++;
			i++;
		}
		list->nb_params = j + 1;
		list = list->next;
	}
}
