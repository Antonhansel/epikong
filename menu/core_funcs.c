/*
** core_funcs.c for core_funcs in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 11:19:43 2014 ribeaud antonin
** Last update Sun Mar  9 23:05:35 2014 ribeaud antonin
*/

#include "graphics.h"

void		apply_surface(int x, int y, SDL_Surface *src, SDL_Surface *dest)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dest, &offset);
}

SDL_Surface	*load_image(char *filename)
{
  SDL_Surface	*loadedImage;
  SDL_Surface	*optimizedImage;
  Uint32	colorkey;

  loadedImage = IMG_Load(filename);
  if (loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat(loadedImage);
      if (optimizedImage != NULL)
	{
	  if (strstr(filename, "img/spaceship/") != NULL)
	    colorkey = SDL_MapRGB(optimizedImage->format, 0, 0, 0);
	  else
	    colorkey = SDL_MapRGB(optimizedImage->format, 255, 255, 255);
	  SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
	}
      SDL_FreeSurface(loadedImage);
    }
  else
    {
      printf("Error while loading image %s\n", filename);
      exit (1);
    }
  return (optimizedImage);
}

void		quit_SDL(t_graph *graph)
{
  SDL_FreeSurface(graph->background);
  SDL_FreeSurface(graph->screen);
  SDL_FreeSurface(graph->exitmess);
  SDL_FreeSurface(graph->maps);
  Mix_FreeMusic(graph->intro_m);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
  if (graph->poscurs == 0)
    start_game(graph, "map/00.map");
  if (graph->poscurs == 1)
    start_game(graph, "map/01.map");
  if (graph->poscurs == 2)
    start_game(graph, "map/02.map");
  if (graph->poscurs == 3)
    start_game(graph, "map/03.map");
  if (graph->poscurs == 4)
    start_game(graph, "map/04.map");
}

void		set_null(t_graph *graph)
{
  int		i;

  i = 0;
  graph->background = NULL;
  graph->screen	= NULL;
  graph->map = NULL;
  graph->exitmess = NULL;
  graph->font = NULL;
  while (i <= 11)
    {
      graph->character[i] = NULL;
      i++;
    }
}

void		my_flip(t_graph *graph)
{
  if (SDL_Flip(graph->screen) == -1)
    {
      printf("Error on flipping screen.\n");
      exit(1);
    }
}
