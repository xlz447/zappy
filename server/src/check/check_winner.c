/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:43:28 by sding             #+#    #+#             */
/*   Updated: 2018/09/15 22:43:30 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

int		check_winner(void)
{
	int		i;
	int		check;
	int		fd;

	check = 0;
	fd = 1;
	i = -1;
	bzero(g_env.buffer, 4096);
	strcpy(g_env.buffer, YELLOW"\n\n[[[[YOUR TEAM HAS WON THE GAME ]]]]\n\n"RESET);
	while (++i < g_env.nb_team)
	{
		if (g_teams[i].reach_max_level == 6)
		{
			printf(YELLOW"\n\n[ WINNER IS TEAM < %s >]\n\n"RESET, g_teams[i].team_name);
			while (fd < MAX_FD && g_players[fd].alive)
			{
				if (g_players[fd].team_id == i)
				send_data(fd, g_env.buffer, MSG_SIZE);
			}
			check = 1;
		}
	}
	return (check == 1 ? 1 : 0);
}
