#include "corewar.h"

int		intlen(int n)
{
	int res;

	res = 0;
	while (n /= 10)
		res++;
	return (res + 1);
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
