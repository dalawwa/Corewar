#include "corewar.h"

int		intlen(int n)
{
	int res;

	res = 1;
	while (n /= 10)
		res++;
	return (res);
}

void	put_n_char(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}
