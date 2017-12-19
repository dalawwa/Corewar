/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:17 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/19 14:31:21 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//On verifie que le fichier est compatible, ".s"
int		check_valid_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
		return (0);
	return (1);
}

//recuperer le char* entre parentheses, c est a dire le nom et le comment et le mettre dans la structure head
int		value_parent(char *str, int x, int j, header_t *op)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
			{
				i++;
				j++;
			}
			if (x == 1)
			{
				if (j > 128)
					return (2);
				i--;
				while (j--)
				{
					op->prog_name[j] = str[i];
					i--;
				}
			}
			if (x == 2)
			{
				if (j > 2048)
					return (3);
				i--;
				while (j--)
				{
					op->comment[j] = str[i];
					i--;
				}
			}
			return (1);
		}
		i++;
	}
	return (0);
}

//on va chech qu il s agit bien d une ligne sans autre caractere que des espaces et tabs
int		check_no_printable_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ';' || str[i] == '#')
			return (1);
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//check que l on retrouve bien .name et .comment au debut du fichier, il peut y avoir des lignes vides avant/apres/entre name et comment et il n y a pas un ordre precis
//verifier de ne pas avoir de ligne a la suite et qui va demarrer par "."
//accepter les commentaires lors de la recherche de ces infos 
int		check_name_comment(int fd, header_t *op)
{
	char	*line;
	int		i;
	int		x;
	int		y;
	int		ret;

	x = 0;
	y = 0;
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(".name", line, 5))
		{
			ret = value_parent(line, 1, 0, op);
			x = 1;
			if (ret == 2)
				return (3);
		}
		else if (ft_strnequ(".comment", line, 8))
		{
			ret = value_parent(line, 2, 0, op);
			y = 1;
			if (ret == 3)
				return (4);
		}
		else if (check_no_printable_char(line) == 0)
			return (0);
		if (x == 1 && y == 1)
			return (1);
		i++;
	}
	return (0);
}

//lancement du parsing, on va d abord chercher a recuperer le nom + comment
////dans un second temps on va recuperer toutes les instructions
//une fois que l on a recupere les datas du champion, il va falloir faire leur analyse
//il manque des messages d erreurs personnalise
int	launch_parsing(char *str)
{
	int		fd;
	int		i;
	char		*file;
	t_champ		*champ;
	header_t	op;

	file = NULL;
	champ = NULL;
	if (check_valid_name(str) == 0)
		return (ciao_bye(1, str));
	if ((fd = open(str, O_RDONLY)) == -1)
		return (ciao_bye(1, str));
	i = check_name_comment(fd, &op);
	if (i != 1)
		return (ciao_bye_name(i, &op));
	champ = get_champ_data(&file, fd);
	if (label_is_real(file, champ) == 0)
		return (ciao_bye_bye_fr(1, champ));
	if (launch_creation_cor(file, champ, &op, str) == 0)
		ciao_bye_bye(1);
	if (file)
		free(file);
	return (0);
}
