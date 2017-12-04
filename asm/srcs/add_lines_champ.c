/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/04 16:52:19 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
//je vais recuperer les arguments
void		add_args_champ(t_champ *list)
{
	int	i;
	int	j;

	while (list->prev)
		list = list->prev;
	list = list->next;
	while (list->next)
	{
		i = 0;
		j = 0;
		while (list->is_label == 1 && list->next)
			list = list->next;
		if (list->next == NULL)
			break ;
		while ((list->line[i + 1] != 'r' || list->line[i + 1] != '%') && (list->line[i] != ' ' || list->line[i] != '\t') && list->line[i] != '\0')
			i++;
		i++;
		while (list->line[i] != ' ' && list->line[i] != ',' && list->line[i] != '\t' && list->line[i] != '\0')
		{
			ft_putchar(list->line[i]);
			i++;
			j++;
		}
		ft_putchar(' ');
		list = list->next;
	}
}
*/

//je recupere le nombre d arguments
void		add_number_args(t_champ *list)
{
	int		i;
	int		j;
	char	**tab;

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
//	tab = ft_strsplit_three(list->line, ' ', '\t', ',');
//	i = 0;
//	while (tab[i])
//	{
//		ft_putstr(tab[i]);
//		ft_putchar('\n');
//		i++;
//	}
//	ft_putchar('\n');
//	ft_putchar('\n');
//	add_args_champ(list);
}

//je verifie si il s agit d un label
int			get_two_points(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ':' && str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

//pas grand chose a chercher la vue qu on a juste le label
void		is_a_label(t_champ *list)
{
	while (list->next)
		list = list->next;
	list->op_code = 0;
	list->is_label = 1;
	list->params = NULL;
	list->nb_params = 0;
	list->size_param1 = 0;
	list->size_param2 = 0;
	list->size_param3 = 0;
	list->has_ocp = 0;
	list->ocp = '\0';
	list->size_octets = 0;
}

int		next_get_the_op_code(char *str)
{
	if (ft_strequ(str, "fork"))
		return (12);
	if (ft_strequ(str, "lld"))
		return (13);
	if (ft_strequ(str, "lldi"))
		return (14);
	if (ft_strequ(str, "lfork"))
		return (15);
	if (ft_strequ(str, "aff"))
		return (16);
	return ('0');
}

//on recupere un int avec l op_code
int		get_the_op_code(char *str)
{
	if (ft_strequ(str, "live"))
		return (1);
	if (ft_strequ(str, "ld"))
		return (2);
	if (ft_strequ(str, "st"))
		return (3);
	if (ft_strequ(str, "add"))
		return (4);
	if (ft_strequ(str, "sub"))
		return (5);
	if (ft_strequ(str, "and"))
		return (6);
	if (ft_strequ(str, "or"))
		return (7);
	if (ft_strequ(str, "xor"))
		return (8);
	if (ft_strequ(str, "zjmp"))
		return (9);
	if (ft_strequ(str, "ldi"))
		return (10);
	if (ft_strequ(str, "sti"))
		return (11);
	return (next_get_the_op_code(str));
}

//la il va falloir chercher un max d infos pour remplir la structure, les params et tout
//next step: recuperer les params 
//+ ocp
//et ensuite size_octets
//ce qui serait bien c est de me retrouver au bon endroit dans la ligne pour pouvoir recuperer les arguments et verifier que ce qu on trouve est plausible
void		is_a_line_of_life(t_champ *list)
{
	int		i;
	int		op;

	i = 0;
	while (list->next)
		list = list->next;
	list->op_code = get_the_op_code(list->name);
	list->is_label = 0;
	op = list->op_code;
	while (list->line[i] == ' ' || list->line[i] == '\t')
		i++;
	if (op == 1 || op == 9 || op == 12 || op == 14)
		i = i + 4;
	else if (op == 2 || op == 5)
}

//je rajoute le nom dans la liste + label et on lance la recherche des autres infos
void		add_name_list(t_champ *list)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (list->line[i] == ' ' || list->line[i] == '\t')
		i++;
	j = i;
	while (list->line[j] != ' ' && list->line[j] != '\t' && list->line[j] != ',')
		j++;
	str = ft_strnew(j - i + 1);
	str = ft_strncpy(str, &list->line[i], (j - i));
	list->name = ft_strdup(str);
	if (get_two_points(list->name))
		is_a_label(list);
	else
		is_a_line_of_life(list);
	if (str)
		free(str);
}

void		add_infos_list(t_champ **begin)
{
	t_champ	*list;

	list = *begin;
	while (list->next)
		list = list->next;
	add_name_list(list);
	while (list->prev)
		list = list->prev;
	add_number_args(list);
}

t_champ		*ft_lstnew_line(char *line)
{
	t_champ *list;

	if (!(list = (t_champ *)ft_memalloc(sizeof(t_champ))))
		ciao_bye_bye(1);
	list->next = NULL;
	list->line = line;
	return (list);
}

void		ft_lstadd_lines(t_champ **begin, char *line, int i)
{
	t_champ	*list;
	t_champ *tmp;

	if (*begin == NULL)
		*begin = ft_lstnew_line(line);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = ft_lstnew_line(line);
		tmp = list;
		list = list->next;
		list->prev = tmp;
		list->position = i;
	}
	add_infos_list(begin);
}
