/*
** menu_funcs2.c for menu_funcs2.c in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 14:33:50 2014 ribeaud antonin
** Last update Thu Mar 20 17:16:29 2014 ribeaud antonin
*/

#include "graphics.h"

void		set_mapsonmenu2(t_graph *graph)
{
  if (graph->poscurs == 3)
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 4", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 4", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 400, graph->maps, graph->screen);
  if (graph->poscurs == 4)
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 5", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 5", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 500, graph->maps, graph->screen);
  if (graph->poscurs == 5)
    graph->maps = TTF_RenderText_Solid(graph->font, "EXIT", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "EXIT", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 600, graph->maps, graph->screen);
}

void		set_mapsonmenu(t_graph *graph)
{
  if (graph->poscurs == 0)
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 1", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 1", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 100, graph->maps, graph->screen);
  if (graph->poscurs == 1)
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 2", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 2", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 200, graph->maps, graph->screen);
    if (graph->poscurs == 2)
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 3", graph->Selected);
  else
    graph->maps = TTF_RenderText_Solid(graph->font, "MAP 3", graph->Standard);
  apply_surface((WIDTH/2) - 10, graph->pos + 300, graph->maps, graph->screen);
  set_mapsonmenu2(graph);
}

void		set_character(t_graph *graph)
{
  graph->character[0] = load_image("img/old/oldhero5/run (1).png");
  graph->character[1] = load_image("img/old/oldhero5/run (2).png");
  graph->character[2] = load_image("img/old/oldhero5/run (3).png");
  graph->character[3] = load_image("img/old/oldhero5/run (4).png");
  graph->character[4] = load_image("img/old/oldhero5/run (5).png");
  graph->character[5] = load_image("img/old/oldhero5/run (6).png");
  graph->character[6] = load_image("img/old/oldhero5/run (7).png");
  graph->character[6] = load_image("img/old/oldhero5/run (8).png");
  graph->character[8] = load_image("img/old/oldhero5/run (9).png");
  graph->character[9] = load_image("img/old/oldhero5/run (10).png");
  graph->character[10] = load_image("img/old/oldhero5/run (11).png");
  graph->character[11] = load_image("img/old/oldhero5/run (12).png");
}

void		make_menu(t_graph *graph)
{
  set_mapsonmenu(graph);
}
