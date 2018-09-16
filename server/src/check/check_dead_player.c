/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:44:13 by sding             #+#    #+#             */
/*   Updated: 2018/09/15 22:44:14 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	check_dead_player(void)
{
	int				i;
	struct timeval	curr_time;

	i = -1;
	bzero(g_env.buffer, 4096);
	strcpy(g_env.buffer, DARKYELLOW"\n[ Your player is dead ]\n"RESET);
	gettimeofday(&curr_time, NULL);
	while (++i < MAX_FD)
	{
		if (g_players[i].fd && !g_players[i].dead)
		{
			if (check_event_time(&curr_time, &(g_players[i].live)))
			{
				g_players[i].dead = 1;
				g_players[i].alive = 0;
				send_data(i, g_env.buffer, MSG_SIZE);
			}
		}
	}
}