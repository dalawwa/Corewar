#include "corewar.h"

int		hexa_to_i(unsigned char c)
{
	if (c < '9')
		return (c - '0');
	else if (c == 'a')
		return (10);
	else if (c == 'b')
		return (11);
	else if (c == 'c')
		return (12);
	else if (c == 'd')
		return (13);
	else if (c == 'e')
		return (14);
	else
		return (15);
}


int		a_hexa_to_i(unsigned char *s, int len)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	len--;
	ft_putendl("a_hexa_to_i --> s = ");
	while (i < len + 1)
	{
		ft_printf("%.2x ", s[i]);
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (len >= 0)
	{
		result += hexa_to_i(s[len]) * ft_power(16, i);
		len--;
		i++;
	}
	return (result);
}
