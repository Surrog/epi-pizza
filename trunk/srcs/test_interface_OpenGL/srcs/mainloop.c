/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Fri Apr 16 20:33:35 2010 Florian Chanioux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include	"define.h"
#include	"struct.h"
#include	"proto.h"

void mainloop(t_game *game)
{
  int exit;

  exit = 1;
  SDL_EnableKeyRepeat(100, 20);
  while (exit)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    exit = interaction(game);
    camera(game);
    make_calllistes();
    draw_map(game);
    draw_mob();
    SDL_GL_SwapBuffers();
  }
}

