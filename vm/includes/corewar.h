#ifndef COREWAR_H
# define COREWAR_H
# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"
# include <fcntl.h>

//typedef int		(*t_fct)(struct s_vm*, struct s_exe*);
// op.h
//
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
 * **
 * */

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8


# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

// FIN DE op.h

typedef struct	s_opt
{
	int		has_d;  // init a 0
	int		d; // init a -1

}				t_opt;

typedef struct	s_proc
{
	int				process_no;
	int				reg[17]; // les registres du process --> reg[0] est unitilable
	int				pc;
	int				carry;
	struct s_play	*player; // potentiellemt useless
	struct s_exe	*exe_op;
	int				op_success; // retour de la fct appele par l'exe (vias la BDD)
	struct s_proc	*next;
	struct s_proc	*prev;
}				t_proc;

typedef struct	s_play
{
	int		play_num; // Numero du joueur
	char	*name;
	char	*comment;
	int		body_len; // longueur du char* body --> car ne finis pas par un '\0'
	unsigned char	*body; // le code du champion a charger dans la MEM
}				t_play;

typedef struct	s_arg
{
	char	*value; // la valeur de lóctet correspondant a l'ARG dan le .cor
	int		d_value; // l'equivqlent decimal du char
	char	type; // le type d'arg (deduis de l'OCP) 'd'= direct í'= indirect ...
	char	*data; // la data contunu dans qui sert a executer la fct (data a l'adresse ou valeur du direct)
}				t_arg;

typedef struct	s_exe
{
	char			opcode;
	char			ocp;
	t_arg			*arg1;
	t_arg			*arg2;
	t_arg			*arg3;
	int				to_wait;
	struct s_bdd	*bdd_op; // la struct d'op BDD corespondant a cet exe
}				t_exe;

typedef struct	s_arena
{
	int				nb_players;
	t_play			**players; // tableau de struct t_play de nb_cor len
	char			mem[MEM_SIZE];
	struct s_bdd	*bdd;
	t_proc			*first; // first elem of list PROC
	t_proc			*last; // the last one
	t_opt			*opts;
	int				*fds;
	int				ctd; // cycle to die
	int				current_cycle; // cycle en cours
	int				max_check;
	int				c_delta;
}				t_arena;

typedef struct	s_bdd
{
	char	*op_name;
	int		opcode;
	int		ocp;
	int		nb_args;
	int		type_arg1;
	int		nb_cycle;
	char	*meaning;
	int		has_ocp;
	int		size_glob;
	int		(*fct)(t_arena*, t_exe*);
}				t_bdd;

/* CREATE ARENA */
int				get_nb_cors(int ac, char **av, int **tab);
t_opt			*check_opts(int ac, char **av);
int				create_players(t_arena *arena);
t_arena			*create_arena(int ac, char **av);
int				*get_fds(t_arena *arena, int ac, char **av);
int				is_cor(char *s);
void			close_cors(int *fds);

/* GO MATCH */
void	go_match(t_arena *arena);

void			print_usage(void);

/* FREE MEMORY */
void	free_arena(t_arena **arena);
void	free_fds(int **fds);
void	free_opts(t_opt **opts);
void	free_players(t_play *players);
void	free_bdd(t_bdd *bdd);

/* FONCTIONS DEBUG */
void	print_tab_cors(int *tab);
void	print_players(t_arena *arena);
void	print_arena(t_arena *arena);

/* ADD TO LIB ? */
char			*ft_stradd_c_end(char *s, char c);

#endif
