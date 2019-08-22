/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:38:41 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 13:48:32 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cursor.h"

# define PROMPT				"ici le prompt: "
# define EXIT_SIG 2
# define ENTER_SIG 3

int			ft_termcap(char *buff, t_cursor *cursor);
void		ft_init_cursor(t_cursor *cursor);
void		ft_cursor_reset(size_t ref);
void		ft_position_cursor(t_cursor *cursor);
void		ft_clear_line(t_cursor *cursor);
int			ft_pc(int c);
void		ft_display_prompt(void);
void		ft_update_line(t_cursor *cursor, char *buff);
void		raw_term_mode(void);
void		def_term_mode(void);
size_t		ft_get_term_length(void);
size_t		ft_get_term_hight(void);
void		ft_reajust_cursor_wrap(t_cursor *cursor, int flag);
void		ft_clean_history(t_dlist **history);
void		ft_load_history(t_cursor *cursor);

void	print_bytes(void *ptr, int size);

#endif

