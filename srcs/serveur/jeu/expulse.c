/*
**  Header
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdio.h>
#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

void		do_expulse(t_packet *packet, t_player *player)
{
  char		*msg;
  t_player	*pl;
  t_list	*cur_player;
  int		i;

  packet->response = xmalloc((my_l_size(player->pos->cas.player) + 1) *
			     sizeof(packet->response));
  packet->response[0].mess = OK;
  cur_player = player->pos->cas.player;
  msg = xmalloc(LEN_EXP * sizeof(char));
  msg = EXPULSE_VIC;
  i = 0;
  while (cur_player != NULL)
    {
      msg[POS_EXP_K] = (player->dir + 1) % 4 + '0';
      packet->response[i].mess = msg;
      pl = (t_player*)cur_player;
      packet->response[i++].id_player = pl->player_id;
      cur_player = cur_player->next;
      }
}

void		try_expulse(t_packet *packet, t_player *player)
{
  if (my_l_size(player->pos->cas.player) == 1)
    {
      packet->response->mess = KO;
      packet->response->id_player = packet->player_id;
    }
  else
    do_expulse(packet, player);
}