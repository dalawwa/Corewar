/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:30 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/08 10:09:11 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include "../../vm/includes/corewar.h"
# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"

/*
typedef struct		s_champ_data
{
	int				nb_struct;
	t_champ			*first;
	t_champ			*last;
}					t_champ_data;

typedef struct		s_label
{
	t_champ			*label_declare;
	t_champ			*label_find;
	t_label			*next;
	int				size_between;
}					t_label;
*/
typedef struct		s_champ
{
	char			*line; //on recupere la ligne du champion
	char			*name; // on recupere l ordre
	int				op_code;
	int				is_label;
	int				position;
	char			**params;
	int				nb_params;
	int				size_param1;
	int				size_param2;
	int				size_param3;
	int				has_ocp;
	char			ocp;
	int				size_octets;
//	struct s_label	*label; //a voir 
//	int				octet_cumul; //a voir
	struct s_champ	*next;
	struct s_champ	*prev;
}					t_champ;

int		main(int ac, char **av);
int		launch_parsing(char *str);
void	get_champ_data(t_champ *champ, int fd);
void	start_struct_champ(t_champ *champ);
void	get_champ_data(t_champ *champ, int fd);
void	check_name_comment(int fd, t_header *op);
int		check_no_printable_char(char *str);
void	value_parent(char *str, int x, int j, t_header *op);
void	check_valid_name(char *str);
void	ciao_bye_bye(int i);
void	ft_lstadd_lines(t_champ **begin, char *line, int i);
char	**ft_strsplit_three(const char *s, char c, char d, char e);
int		get_the_op_code(char *str);
void	add_number_args(t_champ *list);
int		check_args_valid(char *str, int op, t_champ *list);

#endif
