#include "ft_printf.h"

int		ft_printf(char *form, ...)
{
	va_list		ap;
	t_tool		*tool;
	int			(*tab[128])(t_tool *tool, va_list ap);
	int			r;

	if (!(tool = malloc(sizeof(t_tool))))
		return(0);
	init_tool(tool, form);
	//printf("tool->width = %i/n", tool->width);
	init_tab(tab);
	va_start(ap, form);
	while (form[tool->pos])
	{
		if (form[tool->pos] == '%')
			tag(tab, tool, ap);
		else if (tool->buff_i < BUFFER_SIZE)
			tool->buff[tool->buff_i++] = form[tool->pos++];
		else
			put_buff(tool);
	}
	put_buff(tool);
	r = tool->r;
	free(tool);
	return(r);
}