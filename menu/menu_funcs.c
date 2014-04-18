/*
** menu_funcs.c for menu_funcs in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 14:00:17 2014 ribeaud antonin
** Last update Sun Mar  9 23:05:37 2014 ribeaud antonin
*/

#include "graphics.h"

int		menu_quit(t_graph *graph)
{
  graph->quit = 1;
  return (1);
}

int		menu_key(t_graph *graph)
{
  if (EVENT[SDLK_DOWN] && graph->poscurs != 5)
    {
      EVENT[SDLK_DOWN] = 0;
      return (apply_menu(graph, 1));
    }
  if (EVENT[SDLK_UP] && graph->poscurs != 0)
    {
      EVENT[SDLK_UP] = 0;
      return (apply_menu(graph, -1));
    }
   return (0);
}

int		apply_menu(t_graph *graph, int i)
{
  if (i == 1)
    {
      if (graph->poscurs + i <= 5)
	graph->poscurs += i;
    }
  else
    {
      if (graph->poscurs - i >= 0)
	graph->poscurs += i;
    }
  make_menu(graph);
  return (1);
}

void		fail_init()
{
  printf("Error while loading the SDL");
  exit (1);
}
