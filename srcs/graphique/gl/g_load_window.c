/*
** load_window.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 20 23:13:15 2010 Florian Chanioux
** Last update Mon Apr 26 10:12:13 2010 pierre1 boutbel
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "graphique/define.h"
#include "graphique/xsdl.h"

SDL_Surface	*load_window()
{
  SDL_Surface	*screen;
  Uint32	flags;

  flags = SDL_OPENGL;
  if (FULLSCREEN)
    flags |= SDL_FULLSCREEN;
  xSDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  screen = xSDL_SetVideoMode(WIN_W, WIN_H,
			    WIN_COLOR, flags);
  SDL_WM_SetCaption("Zappy", NULL);
  return (screen);
}
