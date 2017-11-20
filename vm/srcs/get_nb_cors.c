#include "corewar.h"

int		is_cor(char *s)
{
	int	len;
	
	len = (int)ft_strlen(s);
	if (len < 4)
		return (0);
	if (s[len - 1] == 'r' && s[len - 2] == 'o' && s[len - 3] == 'c' && s[len - 4] == '.')
		return (1);
	return (0);
}

int		nb_cors(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (i < ac)
	{
		if (is_cor(av[i]) == 1)
			nb++;
		i++;
	}
	ft_printf("nb_cor = %d\n", nb);
	return (nb);
}

int get_nb_cors(int ac, char **av, int **tab)
{
	int i;
	int j;
	int len;
	char **cor;
	char *line;
	int ret;

	i = 1;
	j = 0;
	ret = 1;
	len = nb_cors(ac, av);
	cor = (char **)malloc(sizeof(char*) * (len + 1));
	if (cor == NULL)
		return (-1);
	cor[len] = NULL;
	if (!(*tab = (int *)malloc(sizeof(int) * len)))
		return (-1);
	while (i < ac)
	{
		if (is_cor(av[i]))
		{
			ft_printf("ARG to handle = _%s_\n", av[i]);
			if (((*tab)[j] = open(av[i], O_RDONLY)) == -1)
			{
				ft_printf("Error : Failed to Open : fd = %d\n", tab[j]);
				free(cor);
				free(tab);
				cor = NULL;
				return (-1);
			}
			ft_printf("my fucking fd is %d\n", (*tab)[j]);
			while (j < len)
			{
				lseek((*tab)[j], 4, SEEK_SET);
				while (ret)
				{
					line = ft_strnew(BUFF_SIZE);
					ret = read((*tab)[j], line, BUFF_SIZE);
					ft_printf("READ --> line = _%s_\n", line);
					cor[j] = ft_strjoin_leakless(cor[j], line);
					ft_printf("After segf\n");
				}
				j++;
			}
		}
		i++;
	}
	return (len);
}
