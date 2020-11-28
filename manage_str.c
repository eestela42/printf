#include "ft_printf.h"

void	put_spaces(t_tool *tool, int spaces)
{
	int	i;

	i = 0;
	while (i++ < spaces)
	{
		tool->buff[tool->buff_i++] = ' ';
		if (tool->buff_i == BUFFER_SIZE)
			put_buff(tool);
	}
}

void	manage_str(t_tool *tool, va_list ap)
{
	char	*str;
	int		size;
	int		spaces;
	int		i;

	str = va_arg(ap, char *);
	spaces = 0;
	size = 0;
	while (str[++size]);
	if (tool->if_preci && tool->preci < size)
		size = tool->preci;
	if (tool->if_width && tool->width > size)
		spaces = tool->width - size;
	//printf("\naaaaaaaaaasize = %i\n", size);
	i = 0;
	if (!tool->minus)
		put_spaces(tool, spaces);
	while (i < size)
	{
		tool->buff[tool->buff_i++] = str[i++];
		if (tool->buff_i == BUFFER_SIZE)
			put_buff(tool);
	}
	if (tool->minus)
		put_spaces(tool, spaces);
	tool->secu = 0;
}

void	manage_char(t_tool *tool, va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	if (!tool->minus)
		put_spaces(tool, tool->width - 1);
	tool->buff[tool->buff_i++] = c;
	if (tool->buff_i == BUFFER_SIZE)
		put_buff(tool);
	if (tool->minus)
		put_spaces(tool, tool->width - 1);
	tool->secu = 0;
}
