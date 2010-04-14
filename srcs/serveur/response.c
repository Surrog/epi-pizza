/*
** response for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 13 12:24:14 2010 francois1 ancel
** Last update Tue Apr 13 12:24:14 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

#include "define.h"
#include "my_list.h"
#include "t_packet.h"
#include "t_struct.h"
#include "t_game_stc.h"

int	fill_response_auth(t_rep *rep, int player_id, int num_client, t_game *game)
{
  rep->id_player = player_id;
  rep->mess = malloc(34 * sizeof(*rep->mess));
  if (rep->mess)
    {
      snprintf(rep->mess, 34, "%i\n%i %i\n", num_client, 
	       game->server.width, game->server.height);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}