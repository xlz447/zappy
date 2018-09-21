/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:29:20 by sding             #+#    #+#             */
/*   Updated: 2018/09/03 14:29:21 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "server.h"

/*
** main.c
*/

void	game_loop(void);
void	free_malloc(void);
void	update_live(int fd, int food);

/*
** ********* [ util ] folder *************************
*/

/*
** ft_itoa.c
*/

char	*ft_itoa(int n);
char	*ft_strnew(size_t size);

/*
** ft_strjoin.c
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
** init_player.c
*/
void	s_init_new_player(int fd);
void	s_init_egg_player(int fd, int team_id, int egg_id);
void	s_clear_player(int fd);
/*
** print_info
*/
void	print_player_info(int fd);
void	print_team(void);
void	print_flags(void);

/*
** read_flags.c
*/
int		read_flags(int argc, char **argv, t_env *env);

/*
** set_value.c
*/
int		set_value(char **flag, int i, int m, t_env *env);

/*
** ******** [ resource ] folder *************************
** generate_resource.c
*/

void	generate_resource(void);
/*
** ******* [ check ] folder ******************************
** check_dead_player
*/
void	check_dead_player(void);

/*
** check_winner
*/
int		check_winner(void);

/*
** ******** [ event ] folder *****************************
*/

/*
** exec_event_queue.c
*/
void	exec_event(void);
void	cycle_exec_event_loop(void);

/*
** queue.c
*/
void	enqueue(int fd, char *msg);
void	print_queue(void);

/*
** ******** [ time ] folder *****************************
** time.c
*/
void	record_time(t_event *node, int delay_time);
void	set_block_time(t_event *node, int fd);
int		check_event_time(struct timeval *curr_time, struct timeval *exec_time);
void	calc_time_spead(void);

/*
** ******** [ cmd ] folder *********************************
*/

/*
** advance
*/
void	cmd_advance(int fd, char *msg);

/*
** broadcast
*/
void	cmd_broadcast(int fd, char *msg);
void	calc_four_pos(int pos[4][2], int y, int x);  //-----------> Gaetan: fking ugly, Kwame: wtf is this shit
int		get_closest_pos(int pos[4][2], int pos_y, int pos_x);
int		calc_direction(int pos[2], int y, int x, int direction);
void	send_braodcast_msg(int nb_dir, int fd, char *msg);
void	broadcast(int y, int x, int fd, char *msg);

/*
** connect_nbr
*/
void	cmd_connect_nbr(int fd, char *msg);

/*
** fork
*/
void	cmd_fork(int fd, char *msg);

/*
** hatch
*/
void	cmd_hatch(int fd, char *msg);

/*
** incantation
*/
void	cmd_incantation(int fd, char *msg);
void	level_up_and_unblock(int count, int fds[MAX_FD]);
int		cmd_incantation_check(t_event *node);
void	blocking(int count, int fds[MAX_FD], t_event *node);

/*
** incantation_util
*/
void	low_level_envolving_digest(int level, int fd);
void	high_level_envolving_digest(int level, int fd);
int		check_prerequest(int level, int i);
int		level_require(int level);

/*
** inventory
*/
void	cmd_inventory(int fd, char *msg);

/*
** kick
*/
void	cmd_kick(int fd, char *msg);
void	update_player_pos(int fd);

/*
** left
*/
void	cmd_left(int fd, char *msg);

/*
** put
*/
void	cmd_put(int fd, char *msg);

/*
** right
*/
void	cmd_right(int fd, char *msg);

/*
** see
*/
void	cmd_see(int fd, char *msg);

/*
** see_util
*/
int		update_y(int y);
int		update_x(int x);
void	print_cell_value(int y, int x, int fd);

/*
** take
*/
int		check_resource(char *msg);
void	cmd_take(int fd, char *msg);

/*
** ************* [ socket ] folder *********************************
**
** socket.c
*/
int		setup_socket(void);
void	s_select_cycles(fd_set *master, fd_set *read_fds, int *fdmax, int lfd);
void	s_select_recv(int fd, fd_set *master);
void	s_select_accept(int fd, fd_set *master, int *fdmax);
int		s_create_socket(char *port, int reuse);

/*
** send_recv
*/
int		send_data(int fd, char *msg, int ebytes);
char	*recv_data(int fd, int ebytes);

/*
** s_utils
*/
void	*get_in_addr(struct sockaddr *sa);
int		s_iter_sock(struct addrinfo *ai, struct protoent *proto, int reuse);
char	*get_n_x_y(int fd);
int		s_add_to_team(char *team_name, int fd);
struct timeval *set_timeout_alarm(void);

/*
** get_gfx_data.c
*/
char	*get_gfx_data(void);

#endif
