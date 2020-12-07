#include "ft_printf.h"

void	put_preci(t_tool *tool, int size)
{
	int		number;
	int		i;

	number = tool->preci - size;
	i = 0;
	if (number > 0)
	{
		while (i++ < number)
			to_buff(tool, '0');
	}
}

int		how_long(int num)
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

int	int_reversed(int num)
{
	int tab[10];
	int	i;
	int	y;
	
	i = 0;
	y = 0;
	if (num < 0)
		num = -num;
	else if (num == 0)
		return(0);
	tab[0] = 0;
	while (num)
	{
		tab[i++] = num % 10;
		num = num / 10;
	}
	while (y < i)
		num = num * 10 + tab[y++];
	return(num);
}

void	int_to_buff(t_tool *tool, int num, int size)
{

	if (tool->plus && num >= 0)
		to_buff(tool, '+');
	else if (num < 0)
		to_buff(tool, '-');
	put_preci(tool, size);
	num = int_reversed(num);
	while(size)
	{
		to_buff(tool, num % 10 + '0');
		num = num / 10;
		size--;
	}
}

void	manage_int(t_tool *tool, va_list ap)
{
	long int		num;
	char	space;
	int		size;
	int		added;

	space = ' ';
	if (tool->zero && !tool->minus && !tool->if_preci)
		space = '0';
	num = va_arg(ap, int);
	size = how_long(num);
	added = 0;
	if (num < 0 || tool->plus || tool->space)
		added++;
	tool->width = tool->width - (width_int(tool->preci, size) + added);
	if (added < 0)
		added = 0;
	if (tool->space && !tool->plus && added++)
		to_buff(tool, ' ');
	if (!tool->minus)
		put_width(tool, tool->width, space);
	int_to_buff(tool, num, size);
	if (tool->minus)
		put_width(tool, tool->width, space);
	tool->secu = 0;		
}
