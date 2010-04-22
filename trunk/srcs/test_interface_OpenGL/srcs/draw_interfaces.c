/*
** draw_interfaces.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Wed Apr 21 18:05:56 2010 Florian Chanioux
** Last update Thu Apr 22 16:52:31 2010 Florian Chanioux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
# include	<GL/freeglut_std.h>
#endif

#include	"3dsloader.h"
#include	"define.h"
#include	"struct.h"

static void	interface_up(GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(-0.4, 0.85, 0.5);
  glTexCoord2f(1, 0);
  glVertex3f(0.4, 0.85, 0.5);
  glTexCoord2f(1, 1);
  glVertex3f(0.4, 1, 0.5);
  glTexCoord2f(0, 1);
  glVertex3f(-0.4, 1, 0.5);
  glEnd();
}

static void	interface_down(GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(0.45, -0.45, 0.9);
  glTexCoord2f(0, 1);
  glVertex3f(1, -0.45, 0.9);
  glTexCoord2f(1, 1);
  glVertex3f(1, -1, 0.9);
  glTexCoord2f(1, 0);
  glVertex3f(0.45, -1, 0.9);
  glEnd();
}

void DrawStr(const char *str)
{
  GLint i;

  i = -1;
  if(!str)
    return ;
  while(str[++i])
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
}

void		draw_interface(t_game *game)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glEnable(GL_TEXTURE_2D);

  interface_up(game->texture->inter_u);

  interface_down(game->texture->inter_d);

  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);

}
