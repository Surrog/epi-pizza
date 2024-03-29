/*
** hatch.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Apr 12 19:29:06 2010 Florian Chanioux
** Last update Sat Apr 24 05:49:08 2010 Florian Chanioux
*/


#ifndef		__GAME_CMD_H__
# define	__GAME_CMD_H__

/*concatene_msg_view.c*/
char		*add_player(t_vision *cur_case, char *msg);
char		*add_ressource(t_vision *cur_case, char *msg);
char		*explore_case(t_vision *cur_case, char *msg);
char		*concatene_msg(t_vision *list);

/*expulse.c*/
void		do_expulse(t_packet *packet, t_player *player);
void		try_expulse(t_packet *packet, t_player *player);

/*hatch.c*/
int		find_egg(int *ref, t_eggs *egg);
void		do_fork(t_game *game, t_player *player);
void		try_fork(t_packet *packet, t_player *player, t_game *game);


/*incant.h*/
void		try_incant(t_packet *packet, t_player *player);

/*invent.h*/
void		try_drop_obj(t_packet *packet, t_player *player);
void		try_take_obj(t_packet *packet, t_player *player);
void		try_invent(t_packet *packet, t_player *player);

/*move.h*/
void		try_turn_left(t_packet *packet, t_player *player);
void		try_turn_right(t_packet *packet, t_player *player);
void		try_move(t_packet *packet, t_player *player);

/*view.h*/
void		try_view(t_packet *packet, t_player *player);

/*connect_nbr.h*/
void		find_connect_nbr(t_packet *packet, t_player *player,
				 t_game *game);

/*broadcast*/
void		broadcast(t_packet *packet, t_player *player);
void		expulse(t_packet *packet, t_player *player);
void		incant(t_packet *packet, t_player *player);
void		multi(t_packet *packet, t_player *player);
void		connect(t_packet *packet, t_player *player);

#endif		/*__GAME_CMD_H__*/

