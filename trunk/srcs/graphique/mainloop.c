/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Wed Apr 21 15:18:55 2010 Florian Chanioux
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
  char		*msg;

  circle_read(&game->serv);
  printf("\033[31mbuff content :\033[00m\n");
  printf("%s", game->serv.current->buff);
  printf("\033[31mend content\033[00m\n");
  do
    {
      msg = circle_get(&game->serv);
      if (msg)
	{
	  printf("\033[31mmessage extract :\033[00m\n%s\n",msg);
	  free(msg);
	}
    }while (msg);
}

void		search_msg(t_game *game)
{
  int		ready;

  FD_ZERO(&game->serv.fd_read);
  FD_ZERO(&game->serv.fd_write);
  FD_SET(game->serv.socket, &game->serv.fd_read);
  FD_SET(game->serv.socket, &game->serv.fd_write);
  ready = select(game->serv.socket + 1, &game->serv.fd_read,
		 &game->serv.fd_write, NULL, NULL);
  if (ready > 0)
    {
      if (FD_ISSET(game->serv.socket, &game->serv.fd_read))
	my_recv(game);
    }
  if (ready < 0)
    {
      printf("serveur has gone away...\n");
      exit(EXIT_FAILURE);
    }
}

void		mainloop(t_game *game)
{
  int		exit;

  exit = 1;
  SDL_EnableKeyRepeat(100, 20);
  while (exit)
  {
    exit = interaction(game);
    search_msg(game);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera();
    draw_gl(game, GL_RENDER);
    glFlush();
    SDL_GL_SwapBuffers();
  }
}

