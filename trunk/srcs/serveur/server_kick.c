/*
** server_kick for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 15:39:16 2010 francois1 ancel
** Last update Fri Apr 16 09:31:21 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_packet.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "server_action.h"
#include "server_fct.h"
#include "server_kick.h"
#include "server_eat.h"
#include "server_plaction.h"
#include "server_debug.h"
#include "time_fct.h"
#include "server_insert_player.h"

int		find_kick_fct(t_packet *in, int *player_id)
{
  if ((in->type == 1) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int		create_kick(t_svr_vector *vec, int player_id, int time)
{
  t_packet	*pak;
  t_vector	*action;

  action = vec->action;
  pak = malloc(sizeof(*pak));
  if (pak)
    {
      pak->player_id = player_id;
      pak->type = 1;
      gettimeofday(&(pak->end), NULL);
      pak->end.tv_sec += time;
      pak->ac = 0;
      pak->ac_rep = 0;
      action->insert_sort(action, pak, sort_duration);
      printf("=>  kick create  <=\n");
      return (EXIT_SUCCESS);
    }
  fprintf(stderr, "kick create fail\n");
  return (EXIT_FAILURE);
}

int		server_kick(t_svr_vector *vec, int player_id, t_game *game)
{
  t_vector	*client;
  int		pos;
  t_select	*slt_par;

  slt_par = vec->slt;
  client = vec->client;
  if (player_id > 0)
    {
      pos = client->find_pos(client, &player_id, player_id_find);
      if (pos >= 0)
	{
	  sock_write(player_id, "You have been kicked\n");
	  printf("player %i ass kicked\n", player_id);
	  rm_player(game, player_id);
	  client->erase(client, pos, free_client);
	  delete_kick(vec, player_id);
	  delete_eat(vec, player_id);
	  delete_plaction(vec, player_id);
	  FD_CLR(player_id, &(slt_par->fd_read));
	  return (EXIT_SUCCESS);
	}
      fprintf(stderr, "player %i unknow\n", player_id);
    }
  else
    {
      delete_kick(vec, player_id);
      delete_eat(vec, player_id);
      rm_player(game, player_id);
      printf("l'oeuf a moisie\n");
      return (EXIT_SUCCESS);
    }
  delete_kick(vec, player_id);
  return (EXIT_FAILURE);
}

void		delete_kick(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_kick_fct)) >= 0)
    {
      fprintf(stderr, "=>>> delete kick at %i\n", pos);
      action->erase(action, pos, free);
    }
}