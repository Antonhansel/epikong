/*
** game.launch.c for launch in /home/roussi_h/rendu/T2Rush1/GAME
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 20:00:56 2014 Roussille Hector
** Last update Sun Mar  9 22:53:32 2014 ribeaud antonin
*/

#include "game_data.h"

void	getEvents(t_data *data)
{
  if (SDL_PollEvent(&(data->event_data.event)))
    {
      if (data->event_data.event.type == SDL_KEYUP)
	data->event_data.events[data->event_data.event.key.keysym.sym] = 0;
      else if (data->event_data.event.type == SDL_KEYDOWN)
	data->event_data.events[data->event_data.event.key.keysym.sym] = 1;
    }
}

void	handleEvents(t_data *data)
{
  if (data->event_data.events[SDLK_RETURN])
    exit(0);
  if (data->event_data.events[SDLK_ESCAPE])
    exit(0);
  if (data->event_data.events[SDLK_UP])
    {
      CHARAC.current = SPRITES.charac_climb->image;
      move(data, 0, -64);
    }
  if (data->event_data.events[SDLK_DOWN])
    {
      CHARAC.current = SPRITES.charac_climb->image;
      move(data, 0, 64);
    }
  handleEvents2(data);
}

void	handleEvents2(t_data *data)
{
  if (data->event_data.events[SDLK_LEFT])
    {
      CHARAC.current = SPRITES.charac_left->image;
      move(data, 1, -64);
    }
  if (data->event_data.events[SDLK_RIGHT])
    {
      CHARAC.current = SPRITES.charac_right->image;
      move(data, 1, 64);
    }
  if (data->event_data.events[SDLK_SPACE])
    {
      CHARAC.current = SPRITES.charac_jump->image;
      move(data, -1, -128);
    }
   if (CHARAC.pos.x < 0)
    CHARAC.pos.x = 0;
  if (CHARAC.pos.y < 0)
    CHARAC.pos.y = 0;
  if (CHARAC.pos.x >= data->mapx)
    CHARAC.pos.x = data->mapx - SPRITES.charac_left->image->w;
  if (CHARAC.pos.y >= data->mapy)
    CHARAC.pos.y = data->mapy - SPRITES.charac_left->image->h;
}

void	clip_scroll(t_data *data)
{
  data->xscroll = CHARAC.pos.x + 32 - (GRAPHICS.screen->w / 2);
  data->yscroll = CHARAC.pos.y + 32 - (GRAPHICS.screen->h / 2) ;
  if (data->xscroll < 0)
    data->xscroll = 0;
  if (data->yscroll < 0)
    data->yscroll = 0;
  if (data->xscroll > data->mapx - GRAPHICS.screen->w)
    data->xscroll = data->mapx - GRAPHICS.screen->w;
  if (data->yscroll > data->mapy - GRAPHICS.screen->h)
    data->yscroll = data->mapy - GRAPHICS.screen->h;
}

int		Launch_Game(t_data *data)
{
  Uint32	now;
  Uint32	next;
  SDL_Rect	perso;

  while (1)
    {
      perso.x = CHARAC.pos.x;
      perso.y = CHARAC.pos.y;
      clip_scroll(data);
      getEvents(data);
      gravity(data);
      now = SDL_GetTicks();
      check_exit(data);
      if (now >= next)
	{
	  Blit_Map(data);
	  blit_monsters(data);
	  Blit_Charac(data, perso);
	  handleEvents(data);
	}
      else
	SDL_Delay(20);
      next = now + 20;
      SDL_Flip(GRAPHICS.screen);
    }
}
