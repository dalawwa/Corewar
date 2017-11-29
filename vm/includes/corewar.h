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
	int		has_v;  // init a 0
	int		v; // init a -1
	int		has_s;  // init a 0
	int		s; // init a -1
	int		*fds;
	int		fds_nb;

}				t_opt;

typedef struct	s_proc
{
	int				process_num;
	unsigned char	reg[REG_NUMBER + 1][2]; // les registres du process --> reg[0] --> char ** car reg1 = num player 0xffff
	int				pc;
	int				carry;
	struct s_play	*player; // potentiellemt useless --> Si pour inittialized le reg1
	struct s_exe	*exe_op;
	int				op_success; // retour de la fct appele par l'exe (vias la BDD)
	int				nb_live; // nb live init 0
	struct s_proc	*next;
	struct s_proc	*prev;
}				t_proc;

typedef struct	s_play
{
	int		play_num; // Numero du joueur
	int		size; // size du player
	unsigned char	play_live_num[2]; // numero du joueur dans reg1 et pour le live
	int		idx_start; // index de chargement sur la mem
	char	*name;
	char	*comment;
	int		body_len; // longueur du char* body --> car ne finis pas par un '\0'
	unsigned char	*body; // le code du champion a charger dans la MEM
	int		last_live; // init a 0 --> si OP = live  play_live_num --> last_live = 1 et les last_live des uatres players = 0 Mettre plutot dans Arena ???
}				t_play;

typedef struct	s_arg
{
	unsigned char	*value; // la valeur de lóctet correspondant a l'ARG dan le .cor
	int		d_value; // l'equivqlent decimal du char* value
	char	type; // le type d'arg (deduis de l'OCP) 'd'= direct í'= indirect ...
	int		size; // la size de l'arg -> deduis de l'ocp
	unsigned char	*data; // la data contunu dans qui sert a executer la fct (data a l'adresse ou valeur du direct)
	int		d_data; // l'equivqlent du char* data
}				t_arg;

typedef struct	s_exe
{
	unsigned char	opcode;
	unsigned char	ocp;
//	int				nb_args;
	t_arg			*arg1;
	t_arg			*arg2;
	t_arg			*arg3;
	int				to_wait;
	t_proc			*process; // process qui read l'exe
	struct s_bdd	*bdd_op; // la struct d'op BDD corespondant a cet exe
	struct s_ocp	*ocp_op;
}				t_exe;

typedef struct	s_proc_base
{
	int		nb_proc;
	t_proc	*first; // first elem of list PROC
	t_proc	*last; // the last one
}				t_proc_base;

typedef struct	s_arena
{
	int				nb_players;
	t_play			**players; // tableau de struct t_play de nb_cor len
	unsigned char	mem[MEM_SIZE];
	struct s_bdd	**bdd;
	t_proc_base		*list_proc;
	t_opt			*opts;
	int				*fds;
	int				ctd; // cycle to die
	int				current_cycle; // cycle en cours
	int				max_check;
	int				c_delta;
}				t_arena;

typedef struct	s_ocp
{
	unsigned char		ocp;
//	int		nb_args;
	int		size_adv; // Taille Total de la ligne en char
	char	type_arg1;
	int		size_arg1;
	char	type_arg2;
	int		size_arg2;
	char	type_arg3;
	int		size_arg3;
	int		(*fct)(t_arena*, t_exe*);
}				t_ocp;

typedef struct	s_bdd
{
	char	*name;
	unsigned char	opcode;
	int		has_ocp;
	int		nb_ocp;
	t_ocp	**ocp;
	int		nb_args;
	int		nb_cycle;
	char	*meaning;
}				t_bdd;

/* CREATE ARENA */
int				get_nb_cors(int ac, char **av, int **tab);
t_opt			*check_opts(int ac, char **av);
int				create_players(t_arena *arena);
int			create_arena(int ac, char **av, t_arena **arena);
int				*get_fds(t_arena **arena, int ac, char **av);
int				is_cor(char *s);
void			close_cors(int *fds, t_arena *arena);
int				create_mem(t_arena *arena);
int				create_bdd(t_arena *arena);
int				set_bdd_ocp(t_arena *arena);
int				set_ocp_and_size(t_bdd **bdd);
int				setup_players(t_arena *arena);
int				initialized_start_process(t_arena *arena);

int				perror_int(char *s, int ret);
void			*perror_ptr(char *s, void *ret);
char			*addstr(char *s);

/* Initialized Process */
int		create_new_process(t_arena *arena, t_play *player, t_proc *parent);
int		create_new_exe(t_arena *arena, t_proc *process, t_proc *parent);

/* OP & Outils pour les OP */
//unsigned char	*find_reg_ptr(int arg_value, t_exe *exe);
//int		op_ld(t_arena *arena, t_exe *exe);

/* GO MATCH */
void	go_match(t_arena *arena);
void	kill_process(t_proc *to_kill, t_proc_base *list_proc);
int		start_match(t_arena *arena);

void			print_usage(void);

/* FREE MEMORY */
void	free_arena(t_arena **arena);
void	free_fds(int **fds);
void	free_opts(t_opt **opts);
void	free_players(t_play **players, int nb_players);
void	free_bdd(t_bdd **bdd);
void	free_exe(t_exe *exe, t_proc *process);

/* FONCTIONS DEBUG */
void	print_tab_cors(int *tab);
void	print_players(t_arena *arena);
void	print_arena(t_arena *arena);
void	print_mem(t_arena *arena);
void	print_bdd(t_arena *arena);
void	print_all_process(t_arena *arena);
void	print_regs(t_proc *process);
void	print_opts(t_arena *arena);

/* ADD TO LIB ? */
char			*ft_stradd_c_end(char *s, char c);
int				ft_power(int nb, int pow);
int				a_hexa_to_i(unsigned char *s, int len);
unsigned char	*ft_unsi_strdup(unsigned char *s, int len);

#endif
