/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cursor_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:23:35 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 14:45:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cursor.h"
#include "word_tools.h"

int		ft_start_of_line(t_cursor *cursor)
{
	cursor->char_cursor = 0;
	cursor->display_cursor = 0;
	ft_cursor_reset(cursor->display_cursor);
	ft_position_cursor(cursor);
	return (1);
}

int		ft_end_of_line(t_cursor *cursor)
{
	cursor->char_cursor = cursor->line_len;
	cursor->display_cursor = ft_display_len(cursor->cmd_line);
	ft_cursor_reset(cursor->display_cursor);
	ft_position_cursor(cursor);
	return (1);
}

int		ft_to_prev_word(t_cursor *cursor)
{
	cursor->char_cursor -= ft_prev_word_start(cursor->cmd_line,
													cursor->char_cursor);
	cursor->display_cursor = ft_cursor_conv_char_to_display(cursor->cmd_line,
													cursor->char_cursor);
	ft_cursor_reset(cursor->display_cursor);
	ft_position_cursor(cursor);
	return (1);
}

int		ft_to_next_word(t_cursor *cursor)
{
	cursor->char_cursor += ft_next_word_start(cursor->cmd_line,
													cursor->char_cursor);
	cursor->display_cursor = ft_cursor_conv_char_to_display(cursor->cmd_line,
													cursor->char_cursor);
	ft_cursor_reset(cursor->display_cursor);
	ft_position_cursor(cursor);
	return (1);
}
