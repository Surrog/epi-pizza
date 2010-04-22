/*
**  Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdarg.h>

#include	"define.h"
#include	"my_list.h"
#include	"t_struct.h"
#include	"xfunc.h"

char		*ppo(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 41) * sizeof(char));
  snprintf(msg + strlen(msg), 41, "ppo %i %i %i %i\n", player->player_id,
	   player->pos->x, player->pos->y, player->dir + 1);
  return (msg);
}

char		*plv(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 19) * sizeof(char));
  snprintf(msg + strlen(msg), 19, "plv %i %i\n", player->player_id,
	   player->level);
  return (msg);
}

char		*pin(char *msg, t_player *player)
{
  int		i;

  i = -1;
  msg = xrealloc(msg, (strlen(msg) + 116) * sizeof(char));
  snprintf(msg + strlen(msg), 4, "plv %i %i %i", player->player_id,
	   player->pos->x, player->pos->y);
  while (++i != RESS_NUM)
    snprintf(msg + strlen(msg), 11, " %i", player->ress[i]);
  snprintf(msg + strlen(msg), 2, "\n");
  return (msg);
}