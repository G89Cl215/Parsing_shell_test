/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:18:50 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 14:53:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include <stddef.h>
# include "d_list.h"

# define MAX_KEY_SIZE		8
# define MAX_LINE			4096
# define DOWN				0
# define UP					1

typedef struct		s_cursor
{
	char			cmd_line[MAX_LINE];
	size_t			line_len;
	size_t			display_cursor;
	size_t			char_cursor;
	char			in_history;
	t_dlist			*history;
	char			clipboard[MAX_LINE];
}					t_cursor;

void	ft_position_cursor(t_cursor *cursor);

#endif
