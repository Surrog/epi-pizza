/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Mon Apr 26 11:01:37 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "serveur/define.h"
#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "serveur/t_struct.h"
#include "serveur/t_packet.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server.h"
#include "serveur/server_map.h"
#include "serveur/server_stt.h"
#include "serveur/pars_main.h"

static void	init_log(void)
{
  FILE		*stream;

  stream = fopen("vector_debug.log", "w+");
  if (!stream)
    perror("vector log init fail");
  else
    fclose(stream);
  stream = fopen("packet.log", "w+");
  if (!stream)
    perror("packet log init fail");
  else
    fclose(stream);
  stream = fopen("client.log", "w+");
  if (!stream)
    perror("client log init fail");
  else
    fclose(stream);
  stream = fopen("cbuf.log", "w+");
  if (!stream)
    perror("cbuf log init fail");
  else
    fclose(stream);
}

t_game		*init_game(int ac, char **av)
{
  static t_game		game;

  check(ac, av, &(game.server));
  init_map(&game);
  game.player = my_l_init();
  game.eggs = my_l_init();
  game.state = -1;
  init_log();
  return (&game);
}

int		main(int ac, char **av)
{
  t_game	*game;
  t_map		*cas;

  game = init_game(ac, av);
  if (game->server.debug)
  {
    test_aff_map(game);
    test_map(game);
    cas = &(game->map[25][25]);
    pathfinding(cas);
    test_pathfinding_map(game);
    reset_pathfinding(game);
    test_pathfinding_map(game);
  }
  if (svr_start(game) == EXIT_FAILURE)
    perror("svr start error");
  free_map(game);
  return (EXIT_SUCCESS);
}
