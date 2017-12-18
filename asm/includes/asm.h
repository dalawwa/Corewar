/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:30 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/18 17:41:53 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
 * **
 * */

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
 * **
 * */

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct		s_champ
{
	char			*label;
	int				position;
	struct s_champ	*next;
}					t_champ;

int	position;
int	size_line;

int		main(int ac, char **av);
void	global_variables_size(void);
int		launch_parsing(char *str);
int             label_or_not(char *line);
int             char_label(char c);
void	start_struct_champ(t_champ *champ);
t_champ		*get_champ_data(char **file, int fd);
int		check_name_comment(int fd, header_t *op);
int		check_no_printable_char(char *str);
int		value_parent(char *str, int x, int j, header_t *op);
int		check_valid_name(char *str);
void	ciao_bye_bye(int i);
t_champ	*ft_lstadd_lines(t_champ *begin, char *line, int i);
char	**ft_strsplit_three(const char *s, char c, char d, char e);
int		get_the_op_code(char *str);
void	add_number_args(t_champ *list);
int		check_args_valid(char **str, int op);
int		check_args_valid_with_label(char *str, int op, t_champ *list);
int		check_is_indirect(int i, char **str);
int		check_is_direct(int i, char **str, int opc);
int		check_is_reg(int i, char **str);
int		label_is_real(char *line, t_champ *champ);
int		ciao_bye(int i, char *str);
int		ciao_bye_name(int i, header_t *top);
int		ciao_bye_bye_fr(int i, t_champ *champ);
int		launch_creation_cor(char *file, t_champ *champ, header_t *op, char *str);

#endif
