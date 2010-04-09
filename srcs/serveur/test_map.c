/*
** test_map.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 15:22:12 2010 Florian Chanioux
** Last update Fri Apr  9 15:35:40 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"


void		test_aff_map(t_game *game)
{
  int		x;
  int		y;

  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.width)
      printf("%p ", (void *)&(game->map[y][x]));
    printf("\n");
  }
}

void		test_map(t_game *game)
{
  int		i;
  int		x;
  int		y;
  t_map		*cas;

  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.width)
    {
      i = -1;
      printf("y: %i, x: %i case: %p\n", y, x, (void *)&(game->map[y][x]));
      cas = &(game->map[y][x]);
      while (++i < M_CARD)
        printf("card : %i = %p\n", i, (void *)cas->card[i]);
      printf("\n");
    }
  }
}

