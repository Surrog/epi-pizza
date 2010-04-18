/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	"../includes/define.h"
#include	"../includes/struct.h"
#include	"../includes/proto.h"

void		blit_writing(t_game *game, SDL_Rect *pos, char *str)
{
  SDL_Color	color = {255, 255, 255, 0};
  SDL_Surface	*text;

  text = TTF_RenderText_Blended(game->font, str, color);
  if (SDL_BlitSurface(text, NULL, game->screen, pos) == -1)
    {
      fprintf(stderr, "Not able to Blit surface!\n");
      exit(EXIT_FAILURE);
    }
  SDL_FreeSurface(text);
}

void		display_case(t_game *game, int x, int y)
{
  SDL_Rect	pos;
  char		test[50];
  unsigned int	co;

  pos.x = (MAP_CW / 2) * CASE_W - y * CASE_W / 2 - CASE_W / 2;
  pos.y = (MAP_CH * CASE_H) - (y * CASE_H / 2) - CASE_H;
  pos.x += x * CASE_W / 2;
  pos.y -= x * CASE_H /2;
  sprintf(test, "%d,%d",
	  (((int)game->info.pos.y / CASE_H) + y ) % (game->info.size_h + 1),
	  (((int)game->info.pos.x / CASE_W) + x) % (game->info.size_w + 1));
  co = SDL_MapRGB(game->screen->format, 255, 0, 0);
  SDL_SetColorKey(game->map.fond, SDL_RLEACCEL | SDL_SRCCOLORKEY, co);
  if ((((int)game->info.pos.y / CASE_H) + y ) % (game->info.size_h + 1) ||
      (((int)game->info.pos.x / CASE_W) + x) % (game->info.size_w + 1))
    SDL_BlitSurface(game->map.fond, NULL, game->screen, &pos); 
  else
    {
      SDL_SetColorKey(game->map.ori, SDL_RLEACCEL | SDL_SRCCOLORKEY, co);
      SDL_BlitSurface(game->map.ori, NULL, game->screen, &pos); 
    }
  pos.x += CASE_W / 4;
  pos.y += CASE_H / 3;
  blit_writing(game, &pos, test);
}

void		display_map(t_game *game)
{
  int		y;
  int		x;
  int		x_max;
  int		y_max;

  y = 0;
  y_max = MAP_CH;
  x_max = MAP_CW;
  while (y < y_max)
    {
      x= 0;
      while (x < x_max)
	{
	  display_case(game, x, y);
	  x++;
	}
      y++;
    }
}