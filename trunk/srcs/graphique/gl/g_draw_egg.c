/*
** draw_mob.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 17:10:54 2010 Florian Chanioux
** Last update Mon Apr 26 09:57:33 2010 pierre1 boutbel
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

static void	draw_eggs_onmap(t_egg *player, int ref, GLenum mode)
{
  glPushMatrix();
  glTranslated(player->pos.x * CASE_W, player->pos.y * CASE_H, 0);
  glPushMatrix();
  glTranslated((CASE_H / 2), (CASE_W / 2) , 0);

  /*ID Negative... voir si ca marche ? */
  if (mode == GL_SELECT)
    glPushName(player->id - ref);
  glCallList(EGG);

  if (mode == GL_SELECT)
    glPopName();
  glPopMatrix();
  glPopMatrix();
}

void		draw_eggs(t_game *game, GLenum mode)
{
  int		ref;
  t_egg		*temp;

  ref = game->map.h * game->map.w;
  temp = game->egg;
  while (temp)
    {
      printf("Nous avons l'oeuf %i sur %i %i\n", temp->id, temp->pos.x, 
	     temp->pos.y);
      draw_eggs_onmap(temp, ref, mode);
      /*clic_mob(game, temp, ref);*/
      temp = temp->next;
    }
  /*clic_map(game);*/
}
