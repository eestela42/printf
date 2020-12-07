#include "ft_printf.h"

void	unsignedint_reversed(unsigned int num, char *tab, char* hexa)
{
	int	i;
	int	y;
	
	i = 0;
	while (i < 12)
		hexa[i++] = 'x';
	y = 0;
	while (num)
	{
		hexa[i--] = tab[num % 16];
		num = num / 16;
	}
}

int		how_long_unsignedint(unsigned int num)
{
	int	size;

	size = 0;
	while (num)
	{
		num = num / 10;
		size++;
	}
	return(size);
}

void	put_hex(t_tool *tool, char *hexa, int size)
{
	int	i;

	i = 0;
	while (i++ < tool->preci - size)
		to_buff(tool, '0');
	i = 0;
	while (hexa[i++] == 'x');
	i--;
	if (tool->form[tool->pos] == 'p')
	{
		to_buff(tool, '0');
		to_buff(tool, 'x');
	}
	while (i < 13)
		to_buff(tool, hexa[i++]);
}

int		how_long_hexa(char *hexa)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (hexa[i++] == 'x');
	return(14 - i);
}

void	manage_hex(t_tool *tool, va_list ap)
{
	char				*tab;
	unsigned int		num;
	int					size;
	char				space;
	char				*hexa;

	if (tool->form[tool->pos] == 'X')
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	num = va_arg(ap, unsigned int);
	if (!(hexa = malloc(sizeof(char) * 13)))
	{
		tool->secu = -1;
		return ;
	}
	unsignedint_reversed(num, tab, hexa);
	ft_printf("\nhexa = %s\n", hexa);
	size = how_long_hexa(hexa);
	space = ' ';
	if (tool->zero && !tool->preci)
		space = '0';
	tool->width = tool->width - (width_int(tool->preci, size));
	if (!tool->minus)
		put_width(tool, tool->width, space);
	put_hex(tool, hexa, size);
	if (tool->minus)
		put_width(tool, tool->width, space);
	tool->secu = 0;
}
