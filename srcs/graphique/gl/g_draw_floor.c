/*
** draw_floor.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Mon Apr 19 13:15:43 2010 Florian Chanioux
** Last update Mon Apr 26 09:57:04 2010 pierre1 boutbel
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

void		clic_render(int type)
{
  static int	i;
  static int	j;

  glPushMatrix();
  glTranslatef(CASE_H / 2, CASE_W / 2, 0);
  glPushMatrix();
  i %= 360;
  j %= 360;
  if (type == PSELECT)
    glRotated(j += 2, 0, 0, 1);
  else
    glRotated(i -= 2, 0, 0, 1);
  glCallList(type);
  glPopMatrix();
  glPopMatrix();
}

void		around(int h, int w, GLuint texture)
{
  side(h, texture);
  glPushMatrix();
  glTranslated(0, w * CASE_W, 0);
  side(h, texture);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0, 1);
  side(w, texture);
  glPushMatrix();
  glTranslated(0, -h * CASE_H, 0);
  side(w, texture);
  glPopMatrix();
  glPopMatrix();
}

void		floor_render(int h, int w, GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glNormal3f(0.0f, 0.0f, 1.0f);
  glTexCoord2f(0, 0);
  glVertex2d(0, 0);
  glTexCoord2f(0,w);
  glVertex2d(0, w * CASE_W);
  glTexCoord2f(h, w);
  glVertex2d(h * CASE_H, w * CASE_W);
  glTexCoord2f(h, 0);
  glVertex2d(h * CASE_H, 0);
  glEnd();
}

void		side(int x, GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(x, 0);
  glVertex3d(x * CASE_W, 0, 0);
  glTexCoord2d(x, 1);
  glVertex3d(x * CASE_W, 0, -20);
  glTexCoord2d(0, 1);
  glVertex3d(0, 0, -20);
  glEnd();
}
