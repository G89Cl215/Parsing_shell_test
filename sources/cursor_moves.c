/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:51:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 16:04:14 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "word_tools.h"

int		ft_left_cursor(t_cursor *cursor)
{
	if (cursor->char_cursor > 0)
	{
		ft_reajust_cursor_wrap(cursor, UP);
		(cursor->char_cursor)--;
		(cursor->display_cursor)--;
		while ((cursor->cmd_line[cursor->char_cursor] & bit_8)
		&& !(cursor->cmd_line[cursor->char_cursor] & bit_7))
			(cursor->char_cursor)--;
		ft_cursor_reset(cursor->display_cursor);
		ft_position_cursor(cursor);
	}
	return (1);
}

int		ft_right_cursor(t_cursor *cursor)
{
	if (cursor->char_cursor < cursor->line_len)
	{
		ft_reajust_cursor_wrap(cursor, DOWN);
		(cursor->char_cursor)++;
		(cursor->display_cursor)++;
		while ((cursor->cmd_line[cursor->char_cursor] & bit_8)
		&& !(cursor->cmd_line[cursor->char_cursor] & bit_7))
			(cursor->char_cursor)++;
		ft_cursor_reset(cursor->display_cursor);
		ft_position_cursor(cursor);
	}
	return (1);
}
