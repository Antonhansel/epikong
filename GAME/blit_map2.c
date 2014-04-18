/*
** blit_map2.c for blit_map in /home/apollo/rendu/T2Rush1/etape_1/GAME
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 17:58:07 2014 ribeaud antonin
** Last update Sun Mar  9 22:40:50 2014 Roussille Hector
*/

#include "game_data.h"

void		Blit_map3(t_data *data, int i, int j, SDL_Rect Rect_dest)
{
  SDL_Surface	*tile;

  if (GRAPHICS.map[i][j] == 's')
    {
      tile = SPRITES.ground7->image;
      SDL_BlitSurface(tile, NULL , GRAPHICS.screen, &Rect_dest);
    }
  else if (GRAPHICS.map[i][j] == 'w')
    {
      tile = SPRITES.ground4->image;
      SDL_BlitSurface(tile, NULL , GRAPHICS.screen, &Rect_dest);
    }
}

void		Blit_map2(t_data *data, int i, int j)
{
  SDL_Surface	*tile;
  SDL_Rect	Rect_dest;

  Rect_dest.x = j * 64 - data->xscroll;
  Rect_dest.y = i * 64 - data->yscroll;
  if (i < 0 || j < 0 || i >= data->mapy / 64 || j >= data->mapx / 64)
    {
    }
  else
    {
      if (GRAPHICS.map[i][j] == 'o')
	{
	  tile = SPRITES.ground2->image;
	  SDL_BlitSurface(tile, NULL , GRAPHICS.screen, &Rect_dest);
	}
      Blit_map3(data, i, j, Rect_dest);
    }
}
