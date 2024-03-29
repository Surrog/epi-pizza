/*
** camera.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:30:49 2010 Florian Chanioux
** Last update Sat Apr 24 09:42:39 2010 Florian Chanioux
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

void		init_camera(t_game *game)
{
  game->video.cam[0] = 0;
  game->video.cam[1] = 0;
  game->video.cam[2] = 0;
  game->video.cam[3] = CAM_Z;
}

void		reshape()
{
  glViewport(0, 0, WIN_W, WIN_H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOC, (GLfloat)(WIN_W / WIN_H), WIN_NEAR, WIN_FAR);
  glMatrixMode(GL_MODELVIEW);
}

void		camera(t_game *game)
{
  int x;
  int y;
  int z;
  int px;
  int py;
  int pz;

  px = game->video.cam[0];
  py =  game->video.cam[1];
  pz = game->video.cam[2];
  x = px;
  y = py - game->video.cam[3];
  z = game->video.cam[3];
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, px, py, pz, 0, 0, 1);
}
