/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 15:21:28 2010 Florian Chanioux
*/
#include	<stdio.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
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

#define		TEAM	"GRAPHIC\n"

void		connect_to_serv(t_game *game, char **av)
{
  struct sockaddr_in	sin;

  game->serv.socket = socket(AF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(av[2]));
  sin.sin_addr.s_addr = inet_addr(av[1]);
  if (connect(game->serv.socket, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      perror("Can't connect");
      exit(EXIT_FAILURE);
    }
  write(game->serv.socket, TEAM, strlen(TEAM));
  printf("Connect at %s\n", av[1]);
  FD_ZERO(&game->serv.fd_read);
  FD_ZERO(&game->serv.fd_write);
  FD_SET(0, &game->serv.fd_read);
  FD_SET(0, &game->serv.fd_write);
}