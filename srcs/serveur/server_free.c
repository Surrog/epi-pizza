/*
** server_free.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 13 12:00:53 2010 Florian Chanioux
** Last update Fri Apr 16 13:49:02 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"

void		free_playerlist(t_player *player)
{
  free(player);
}

void		free_map(t_game *game)
{
  int		y;
  int		x;
  t_map		*mcase;

  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.height)
    {
      mcase = &(game->map[y][x]);
      my_l_free(mcase->cas.player, free_playerlist);
    }
    free(game->map[y]);
  }
  free(game->map);
}
