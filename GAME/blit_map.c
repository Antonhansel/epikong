/*
** blit_map.c for blit_map in /home/roussi_h/rendu/T2Rush1/GAME
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 20:07:36 2014 Roussille Hector
** Last update Sun Mar  9 22:59:41 2014 ribeaud antonin
*/

#include "game_data.h"

void	Blit_Charac(t_data *data, SDL_Rect pos)
{
  pos.x -= data->xscroll;
  pos.y -= data->yscroll;
  SDL_BlitSurface(CHARAC.current, NULL, GRAPHICS.screen, &pos);
}

void	Blit_Map(t_data *data)
{
  int	i;
  int	j;
  int	minx;
  int	maxx;
  int	miny;
  int	maxy;

  minx = (data->xscroll /  64) -1;
  miny = (data->yscroll /  64) -1;
  maxx = ((data->xscroll + GRAPHICS.screen->w) / 64);
  maxy = ((data->yscroll + GRAPHICS.screen->h) / 64);
  j = minx;
  i = miny;
  SDL_BlitSurface(GRAPHICS.background, NULL, GRAPHICS.screen, NULL);
  while (i <= maxy)
    {
      while (j <= maxx)
	{
	  Blit_map2(data, i, j);
	  j++;
	}
      i++;
      j = minx;
    }
}
