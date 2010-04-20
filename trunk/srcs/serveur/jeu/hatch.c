/*
** hatch.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Apr 12 19:29:06 2010 Florian Chanioux
** Last update Tue Apr 20 17:06:19 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

static int	find_egg(int *ref, t_eggs *egg)
{
  if (*ref == egg->id)
    return (1);
  return (0);
}

void		do_hatch(t_game *game, int id_egg)
{
  t_player	*player;
  t_eggs	*egg;
  t_player	*pl;
  int		i;

  egg = my_l_find(game->eggs, &id_egg, find_egg);
  srand(time(NULL));
  player = xmalloc(sizeof(player));
  player->player_id = egg->id;
  player->team = egg->team;
  player->level = 1;
  player->dir = random() % 4;
  player->pos = egg->pos;
  i = -1;
  while (--i != RESS_NUM)
    player->ress[i] = 0;
  game->player = my_l_insert(game->player, player);
  pl = (t_player *)game->player->data;
  pl->pos->cas.player = my_l_insert(pl->pos->cas.player, player);
  game->eggs = my_l_rm(game->eggs, &id_egg, find_egg);
}

void		try_fork(t_packet *packet, t_player *player, t_game *game)
{
  static int	id = 0;
  t_eggs	*new_egg;

  if (--id < -64000)
    id = -1;
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(LEN_OK * sizeof(char));
  snprintf(packet->response->mess, LEN_OK, "%s\n", OK);
  packet->response->id_player = player->player_id;
  packet->ac_rep = 1;
  packet->type = id;
  new_egg = xmalloc(sizeof(t_eggs));
  new_egg->team = player->team;
  new_egg->pos = player->pos;
  new_egg->id = id;
  game->eggs = my_l_insert(game->eggs, new_egg);
}
