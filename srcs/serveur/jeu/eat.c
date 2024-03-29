/*
** eat.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:18:39 2010 pierre1 boutbel
** Last update Sat Apr 24 05:49:08 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdlib.h>

#include	"my_list.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_game_stc.h"
#include	"xfunc.h"
#include	"serveur/server_insert_player.h"

static int	find_player(int *ref, t_player *data)
{
  if (*ref == data->player_id)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int		try_eat(t_game *game, int id_player)
{
  t_player	*player;
  
  player = (t_player *)my_l_find(game->player, &id_player, find_player);
  if (player->ress[0] > 0)
    player->ress[0]--;
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

