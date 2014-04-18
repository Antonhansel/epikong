/*
** spaceship.c for spaceship in /home/apollo/rendu/T2Rush1/menu
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 12:11:34 2014 ribeaud antonin
** Last update Sun Mar  9 13:36:36 2014 ribeaud antonin
*/

#include "graphics.h"

void		move_spaceship2(t_graph *graph)
{
  if (graph->spacepos1 > HEIGHT + 300)
    graph->spacepos1 = -300;
  graph->spacepos1 -= 5 * graph->spacefactor;
  if (graph->spacepos2 > HEIGHT + 300)
    graph->spacepos2 = -300;
  graph->spacepos2 -= 2 * graph->spacefactor;
  if (graph->spacepos3 > HEIGHT + 300)
    graph->spacepos3 = -300;
  graph->spacepos3 -= 7 * graph->spacefactor;
  if (graph->spacepos4 > HEIGHT + 300)
    graph->spacepos4 = -300;
  graph->spacepos4 -= 10 * graph->spacefactor;
}

void		move_spaceship(t_graph *graph)
{
  if (graph->charac_num < 11)
    graph->charac_num++;
  else
    graph->charac_num = 0;
  if (graph->charac_num == 7)
    graph->charac_num++;
  if (graph->spacepos1 < - 300)
    graph->spacepos1 = HEIGHT + 300;
  graph->spacepos1 -= 5 * graph->spacefactor;
  if (graph->spacepos2 < - 300)
    graph->spacepos2 = HEIGHT + 300;
  graph->spacepos2 -= 2 * graph->spacefactor;
  if (graph->spacepos3 < - 300)
    graph->spacepos3 = HEIGHT + 300;
  graph->spacepos3 -= 7 * graph->spacefactor;
  if (graph->spacepos4 < - 300)
    graph->spacepos4 = HEIGHT + 300;
  graph->spacepos4 -= 10 * graph->spacefactor;
  move_spaceship2(graph);
}
