/*
** t_packet for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Apr 11 14:39:48 2010 francois1 ancel
** Last update Sat Apr 17 11:32:06 2010 pierre1 boutbel
*/

#ifndef			T_PACKET_INCLUDED
# define		T_PACKET_INCLUDED

typedef struct
{
  int			id_player;
  char			*mess;
}			t_rep;

typedef struct
{
  void			*player;
  int			player_id;
  int			type;
  int			ac;
  char			*av[2];
  int			duration;
  struct timeval	end;
  int			ac_rep;
  char			*graph_rep;
  t_rep			*response;
}			t_packet;

typedef struct
{
  char			*inst;
  void			(*ptr_func)();
  int			delay;
}			t_inst;

#endif			/* !T_PACKET_INCLUDED */
