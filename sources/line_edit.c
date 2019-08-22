/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:42:18 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 16:39:12 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "word_tools.h"

int		ft_del_next_word(t_cursor *cursor)
{
	size_t		word_end;
	size_t		word_len;

	word_end = cursor->char_cursor;
	word_len = ft_next_word_end(cursor->cmd_line, word_end);
	word_end += word_len;
	ft_memmove(cursor->cmd_line + cursor->char_cursor,
			cursor->cmd_line + word_end,
			ft_strlen(cursor->cmd_line + word_end) + 1);
	cursor->display_cursor = ft_cursor_conv_char_to_display(cursor->cmd_line, cursor->char_cursor);
	cursor->line_len -= word_len;
	ft_update_line(cursor, NULL);
	return (1);
}

int		ft_backspace(t_cursor *cursor)
{
	size_t		new_cursor;

	if ((cursor->line_len) && (cursor->char_cursor))
	{
		(cursor->display_cursor)--;
		new_cursor = cursor->char_cursor - 1;
		while ((new_cursor) && (cursor->cmd_line[new_cursor] & bit_8)
		&& !(cursor->cmd_line[new_cursor] & bit_7))
			new_cursor--;
		cursor->line_len -= (cursor->char_cursor - new_cursor);
		ft_memmove(cursor->cmd_line + new_cursor,
				cursor->cmd_line + cursor->char_cursor,
				ft_strlen(cursor->cmd_line + cursor->char_cursor) + 1);
		ft_update_line(cursor, NULL);
		cursor->char_cursor = new_cursor;
	}
	return (1);
}
