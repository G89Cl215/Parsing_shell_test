/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:35:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/22 16:11:01 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>

#include <stdio.h>
#include "parsing.h"
#include "dispatcher.h"
#include "libft.h"
#include "d_list.h"

t_cap		g_termcap[] =
{
	{ENTER_CODE, &ft_enter},
/*
	{ESC_CODE, &ft_enter},*/
	{META_B_CODE, &ft_to_prev_word},
	{META_F_CODE, &ft_to_next_word},
	{META_D_CODE, &ft_del_next_word},
	{UP_CODE, &ft_up_cursor},
	{CTRL_P_CODE, &ft_up_cursor},
	{DOWN_CODE, &ft_down_cursor},
	{RIGHT_CODE, &ft_right_cursor},
	{CTRL_F_CODE, &ft_right_cursor},
	{LEFT_CODE, &ft_left_cursor},
	{CTRL_B_CODE, &ft_left_cursor},
	{BACKSPACE_CODE, &ft_backspace},
	{CTRL_H_CODE, &ft_backspace},
/*	{TAB_CODE, &ft_autocomplete},
	{CTRL_Z_CODE, &ft_sig_stop_program},
	{CTRL_C_CODE, &ft_sig_int_program},
	{CTRL_\_CODE, &ft_sig_quit_program},
*/	{CTRL_A_CODE, &ft_start_of_line},
	{CTRL_E_CODE, &ft_end_of_line},
	{CTRL_D_CODE, &ft_end_of_stream},
	{CTRL_K_CODE, &ft_clear_from_cursor},
	{CTRL_L_CODE, &ft_clear_screen_key},
/*	{CTRL_R_CODE, &ft_search_history},*/
	{CTRL_U_CODE, &ft_clear_cmd},
/*	{CTRL_W_CODE, &ft_clear_last_word},
	{CTRL_U_CODE, &ft_clear_cmd},
	{DEL_CODE, &ft_delete_key},
	{HOME_CODE, &ft_home_key},
	{END_CODE, &ft_end_key},*/
	{0, NULL}
};

int		ft_enter(t_cursor *cursor)
{
	ft_dlistadd_start(&(cursor->history),
			ft_new_dnod(cursor->cmd_line, PAST_CMD));
	ft_putstr("\n\r");
	ft_putendl(cursor->cmd_line);
	ft_init_cursor(cursor);
	ft_clean_history(&(cursor->history));
	ft_update_line(cursor, NULL);
	return (ENTER_CODE);
}

int		ft_termcap(char buff[MAX_KEY_SIZE], t_cursor *cursor)
{
	union u_convert		conv;
//	union u_convert		term;
	size_t				i;

	i = 0;
	ft_memcpy(conv.recieved, buff, MAX_KEY_SIZE);
//	print_bytes(buff, MAX_KEY_SIZE);
//	printf("%li\n\r", conv.code);
	while ((g_termcap[i].key_code))
	{
		if (g_termcap[i].key_code == conv.code)
			return (g_termcap[i].ft_(cursor));
		i++;
	}
	return (0);
}
