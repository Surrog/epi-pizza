/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:37 2010 Florian Chanioux
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
#include	"graphique/struct.h"
#include	"graphique/proto.h"

/*include for select*/
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

void		init_buff(char *buff, int size)
{
  int		i;

  i = 0;
  while (i < size)
    buff[i++] = 0;
}

void		my_recv(t_game *game)
{
  char		buff[1024];

  init_buff(buff, 1024);
  read(game->serv.socket, buff, 1024);
  write(1, buff, 1024);
}

void		search_msg(t_game *game)
{
  FD_ZERO(&(game->serv.fd_read));
  FD_SET(0, &(game->serv.fd_read));
  if (select(game->serv.socket + 1, &game->serv.fd_read,
	     &game->serv.fd_write, NULL, NULL))
    {
      if (FD_ISSET(0, &game->serv.fd_read))
	my_recv(game);
    }
}

void		timedelay()
{
  static int	delay = 1000/ FPS;
  static int	thenTicks = -1;
  static int	nowTicks;

  nowTicks = SDL_GetTicks();
  delay += (1000 / FPS - (nowTicks - thenTicks));
  thenTicks = nowTicks;
  if (delay < 0)
    delay = 1000 / FPS;
  SDL_Delay(delay);
}



void		mainloop(t_game *game)
{
  int		exit;

  exit = 1;
  SDL_EnableKeyRepeat(100, 20);
  while (exit)
  {
/*    search_msg(game);*/
      exit = interaction(game);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      camera(game);
      draw_interface(game);
      draw_gl(game, GL_RENDER);

      glFlush();
      SDL_GL_SwapBuffers();
/*    timedelay();*/
  }
}

