/*
** init_graphics.c for init_graphics in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 11:05:36 2014 ribeaud antonin
** Last update Thu Mar 20 17:16:26 2014 ribeaud antonin
*/

#include "graphics.h"

int		intro_music(t_graph *graph)
{
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 0, 4096))
    return (-1);
  graph->intro_m = Mix_LoadMUS("music/intro.mp3");
  if (graph->intro_m == NULL)
    return (-1);
  Mix_PlayMusic(graph->intro_m, -1);
  return (0);
}

void		init_font(t_graph *graph)
{
  graph->Selected.r = 255;
  graph->Selected.g = 0;
  graph->Selected.b = 0;
  graph->Standard.r = 255;
  graph->Standard.g = 255;
  graph->Standard.b = 255;
  graph->font = TTF_OpenFont("fonts/font1.ttf", 80);
}

void		init_spaceship(t_graph *graph)
{
  graph->spaceship1 = load_image("img/spaceship/space1.png");
  graph->spaceship2 = load_image("img/spaceship/space3.png");
  graph->spaceship3 = load_image("img/spaceship/space6.png");
  graph->spaceship4 = load_image("img/spaceship/space10.png");
  graph->spacepos1 = HEIGHT + 300;
  graph->spacepos2 = HEIGHT + 300;
  graph->spacepos3 = HEIGHT + 300;
  graph->spacepos4 = HEIGHT + 300;
}

int		init_SDL(t_graph *graph)
{
  graph->pos = (HEIGHT / 2) - (HEIGHT / 4);
  graph->poscurs = 0;
  set_null(graph);
  SDL_WM_SetCaption(NAME, NULL);
  graph->charac_num = 0;
  if (TTF_Init() == -1)
    return (-1);
  init_font(graph);
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  graph->screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP,
				   SDL_SWSURFACE | SDL_FULLSCREEN);
  if (graph->screen == NULL)
    return (-1);
  graph->quit = 0;
  set_character(graph);
  init_spaceship(graph);
  graph->background = load_image("img/space.bmp");
  graph->spacefactor = 1;
  init_joystick(graph);
  intro_music(graph);
  return (0);
}
