#include "ft_printf.h"

void	init_tool(t_tool *tool, char *form)
{
	tool->form = form;
	tool->pos = 0;
	tool->buff_i = 0;
	tool->r = 0;
	tool->preci = 0;
	tool->width = 0;
}

void	init_tab(int (*tab[128])(t_tool *tool, va_list ap))
{
	int i;

	i = 0;
	while (i <= 128)
		tab[i++] = skip;
	//tab['+'] = plus;
	//tab['-'] = minus;
	//tab['0'] = zero;
	//tab['*'] = asterisk;
	//tab['%'] = pourcent;
	//tab['.'] = preci;
	//i = '1';
	//while (i <= '9')
		//tab[i++] = width;
	//tab['s'] = print_str;
	//tab['d'] = print_int;
	//tab['i'] = print_int;
	//tab['c'] = print_char;
	//tab['p'] = print_po;
	//tab['x'] = print_hexmin;
	//tab['X'] = print_hexmaj;
}

void	put_buff(t_tool *tool)
{
	if (tool->buff_i > 0)
	{
		write(1, tool->buff, tool->buff_i);
		tool->r = tool->r + tool->buff_i;
		tool->buff_i = 0;
	}
}

int		skip(t_tool *tool, va_list ap)
{
	return(0);
}

void	tag(int (*tab[128])(t_tool *tool, va_list ap), t_tool *tool, va_list ap)
{
	int	i;

	i = 1;
	//printf("pre pos = %i", tool->pos);
	tool->pos++;
	//printf("post pos = %i", tool->pos);
	while(i == 1)
		i = tab[tool->form[tool->pos]](tool, ap);
}