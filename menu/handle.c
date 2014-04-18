/*
** handle.c for handle in /home/apollo/rendu
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 14:07:02 2014 ribeaud antonin
** Last update Sun Mar  9 16:10:50 2014 ribeaud antonin
*/

#include "graphics.h"

void		handleReturn(t_graph *graph)
{
  graph->quit = 1;
}

int		handleEvent(t_graph *graph)
{
  if (EVENT[SDLK_UP] || EVENT[SDLK_DOWN])
    menu_key(graph);
  if (EVENT[SDLK_RETURN])
    handleReturn(graph);
  if (EVENT[SDLK_ESCAPE])
    menu_quit(graph);
  if (graph->events.quit)
    menu_quit(graph);
  return (0);
}

void		currentNext(t_graph *graph)
{
  update_joystick(graph);
  put_image(graph);
}
