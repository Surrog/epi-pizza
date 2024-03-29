/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 10:20:04 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>
#include	<time.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glut.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

int		rand_pos_case()
{
  static long	seed;

  srandom(time(NULL) + seed);
  seed = random();
  return ((int)(random() % 24 + 4));
}

void		create_map(t_game *game)
{
  int		y;
  int		x;
  int		temp;

  game->map.t_case = xmalloc(game->map.h * sizeof(*(game->map.t_case)));
  y = -1;
  while (++y < game->map.h)
    {
      game->map.t_case[y] = xmalloc(game->map.w * sizeof(t_case));
      x = -1;
      while (++x < game->map.w)
	{
	  game->map.t_case[y][x].player = 0;
	  temp = -1;
	  while (++temp < 7)
	    {
	      game->map.t_case[y][x].obj[temp][0] = rand_pos_case();
	      game->map.t_case[y][x].obj[temp][1] = rand_pos_case();
	      game->map.t_case[y][x].obj[temp][2] = 0;
	    }
	}
    }
}

void		init_game(t_game *game)
{
  game->screen = load_window();
  game->map.t_case = 0;
  game->mouse.clicked = 0;
  game->team = NULL;
  game->player = NULL;
  game->egg = NULL;
  game->map.rot = 0;
  game->map.z = 200;
  game->info.crazy = MOD_OK;
  game->info.pos.x = 0;
  game->info.pos.y = 0;
  game->map.select_c = -200;
  game->map.select_c_o = -200;
  game->map.select_p = -200;
  game->map.select_p_o = -200;
  SDL_ShowCursor(1);
}
