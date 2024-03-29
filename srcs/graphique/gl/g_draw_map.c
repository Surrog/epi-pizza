/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:38 2010 Florian Chanioux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		picking_map(t_game *game)
{
  int           x;
  int           y;
  int           i;

  i = -1;
  y = -1;
  while (++y < game->map.h)
  {
    x = -1;
    while (++x < game->map.w)
    {
      ++i;
      glPushName(i);
      floor_picking(x, y);
      glPopName();
    }
  }
}

void		draw_map(GLenum mode)
{
  if (mode == GL_RENDER)
    glCallList(TERRAIN);
  else
    glCallList(TERRAIN + 1);
}
