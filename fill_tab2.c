#include "ft_printf.h"

void	space(t_tool *tool, va_list ap)
{
	(void)ap;
    tool->space = 1;
}

void	preci(t_tool *tool, va_list ap)
{
	while(tool->form[++tool->pos] >= '0' && tool->form[tool->pos] <= '9')
	{
		tool->preci = tool->preci * 10 + tool->form[tool->pos] - '0';
		tool->if_preci = 1;
	}
	if (tool->if_preci && tool->form[tool->pos] == '*')
	{
		tool->secu = -1;
		return;
	}
	else if (tool->form[tool->pos] == '*')
		tool->preci = va_arg(ap, int);
	if (tool->preci > 0)
		tool->if_preci = 1;
}

void	width(t_tool *tool, va_list ap)
{
	(void)ap;

	if (tool->if_width)
	{
		tool->secu = -1;
		return;
	}
	while(tool->form[tool->pos] >= '0' && tool->form[tool->pos] <= '9')
		tool->width = tool->width * 10 + tool->form[tool->pos++] - '0';
	tool->if_width = 1;
	tool->pos--;
}