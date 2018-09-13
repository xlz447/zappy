/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_take.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:25:54 by sding             #+#    #+#             */
/*   Updated: 2018/08/17 18:25:55 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** take an object
*/

#include "../../include/server.h"

void	eat_food_for_living(int fd)
{
	g_players[fd].inventory[0]--;
	update_live(fd, 1);
}

int     cmd_take(int fd, char *msg)
{
    int res_i;

	printf(CYAN"\n[Exec TAKE]\n"RESET);
    printf(BLUE"Player [%d] -> [%s %s]"RESET, fd, "take", msg);
    g_players[fd].request_nb--;
    if ((res_i = check_resource(msg)) == 7) // i think this can be handle in parse
	{
		// if (send_msg(fd, RED"KO\n"RESET, "Send [take]") == EXIT_FAILURE)
		// 	return (EXIT_FAILURE);


		send_data(fd, RED"TAKE KO"RESET, MSG_SIZE);

	}
    if (g_env.map[g_players[fd].y][g_players[fd].x][res_i] == 0)
	{
		// if (send_msg(fd, RED"KO\n"RESET, "Send [take]") == EXIT_FAILURE)
		// 	return (EXIT_FAILURE);

		send_data(fd, RED"TAKE KO"RESET, MSG_SIZE);

	}
    else
    {
        g_env.map[g_players[fd].y][g_players[fd].x][res_i]--;
        g_players[fd].inventory[res_i]++;
		if (res_i == 0)
			eat_food_for_living(fd);
    }
	printf("players %d, finish take -> %s\n", fd, msg);
	printf(CYAN"\n[TAKE SUCCESS]\n"RESET);

	// if (send_msg(fd, RED"OK\n"RESET, "Send [take]") == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);

	send_data(fd, RED"TAKE OK"RESET, MSG_SIZE);

    // update graphic client regarding player position
    return (EXIT_SUCCESS);
}

int     check_resource(char *msg)
{
	if (strcmp("food", msg) == 0)
		return (0);
	else if (strcmp("linemate", msg) == 0)
		return (1);
	else if (strcmp("deraumere", msg) == 0)
		return (2);
	else if (strcmp("sibur", msg) == 0)
		return (3);
	else if (strcmp("mendiane", msg) == 0)
		return (4);
	else if (strcmp("phiras", msg) == 0)
		return (5);
	else if (strcmp("thystame", msg) == 0)
		return (6);
	else
	{
		printf("check_resource, msg_buf for put and take: |%s|\n", msg);
		return (7);
	}
}