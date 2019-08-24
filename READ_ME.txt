# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    READ_ME.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 11:39:40 by tgouedar          #+#    #+#              #
#    Updated: 2019/08/24 18:45:00 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

enter				send command line into interpretor							OK/need more integration
escape				
del					
home				
end					
backspace			remove char left of cursor									OK
tab					autocomplete												
right & left		move cursor once in the direction							OK
up & down			cycle through history										OK
meta_a				enter + up													
meta_b				move cursor to start of previous word						OK
meta_c				capitalize next char and move to end of word				
meta_d				delete next word (from cursor position)						OK
meta_e
meta_f				move cursor to start of next word							OK
meta_g
meta_h				run-help opens man for ponted word
meta_i
meta_j
meta_k
meta_l				move cursor to end of next word								OK
meta_m
meta_n
meta_o
meta_p				restore previous history entry
meta_q				store command line in a temporary history and reset line ; enter will restore stored line on first in first out principle
meta_r
meta_s
meta_t
meta_u
meta_v
meta_w
meta_x
meta_y
meta_z
meta_backspace
ctrl_a				move cursor to start of line								OK
ctrl_b				move cursor back one char									OK
ctrl_c				interupt current processus, killing it						
ctrl_d				end current shell session									OK/need more integration
ctrl_e				move cursor to end of line									OK
ctrl_f				move cursor forward one char								OK
ctrl_g				reset command on a new line, ignoring old, but still displaying it
																				
ctrl_h				remove char left of cursor ( = backspace)					OK
ctrl_i				
ctrl_j				
ctrl_k				cut line from cursor to end, saving it in clipboard			OK
ctrl_l				clear screen and display current command line in top		OK
ctrl_m
ctrl_n
ctrl_o				while in history search, execute found entry
ctrl_p				cycle to previous history entry								OK
ctrl_q				enable on screen output from program (ctrl+s)				
ctrl_r				start search in history entries matching a typed sequence	
ctrl_s				prevent on screen output from program						
ctrl_t				swap char with previous char and move right one				
ctrl_u				cut command line, saving it in clipborad					OK
ctrl_v				escape sequence for any termcap key ; verbatim display		
ctrl_w				cut previous word, saving it in clipboard					OK
ctrl_x				
ctrl_y				yank/paste clipboard										OK
ctrl_z				stop current processus, putting it to sleep					

						ISSUES I MIGHT UNCOUNTER

ft_update_line with cmd_line containing '\n' : the cursor might not be reset well
			each key typed might scroll to much
