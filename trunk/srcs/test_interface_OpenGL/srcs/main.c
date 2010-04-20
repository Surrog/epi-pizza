/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Tue Apr 20 23:44:31 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include "SDL_ttf.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "3dsloader.h"
#include "define.h"
#include "struct.h"
#include "proto.h"

int		main(int argc, char *argv[])
{
  t_game	game;

  argc = argc;
  argv = argv;
  init_video(&game);
  init_game(&game);
  printAttributes();
  init_texture(&game);
  initGL(&game);
  mainloop(&game);
  puts("end of program");
  SDL_Quit();
  return (EXIT_SUCCESS);
}
