/*
** main.c for main in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 10:11:53 2014 ribeaud antonin
** Last update Wed Mar 12 21:19:53 2014 ribeaud antonin
*/

#include <errno.h>
#include <string.h>
#include "graphics.h"

int		getEvent(t_graph *graph)
{
  if (SDL_PollEvent(&graph->event))
    {
      if (graph->event.type == SDL_KEYDOWN)
	EVENT[graph->event.key.keysym.sym] = 1;
      if (graph->event.type == SDL_KEYUP)
	EVENT[graph->event.key.keysym.sym] = 0;
      if (graph->event.type == SDL_QUIT)
	graph->events.quit = 1;
    }
  return (handleEvent(graph));
}

void		start_game(t_graph *graph, char *path)
{
  graph->quit = 0;
  if (Load_map(path) == 0)
    {
      execl("./game", path, NULL);
      printf("EXECVE en envoyant le path: %s \n", path);
      printf("ERROR : %s\n", strerror(errno));
    }
  else
    {
      printf("Error while parsing map: %s \n", path);
      exit (1);
    }
}

void		put_image(t_graph *graph)
{
  getEvent(graph);
  move_spaceship(graph);
  apply_surface(0, 0, graph->background, graph->screen);
  apply_surface((WIDTH / 4), graph->spacepos1,
		graph->spaceship1, graph->screen);
  apply_surface((WIDTH / 2) + 100, graph->spacepos2,
		graph->spaceship2, graph->screen);
  apply_surface((WIDTH / 2) + 300, graph->spacepos3,
		graph->spaceship3, graph->screen);
  apply_surface((WIDTH / 2) - 100, graph->spacepos4,
		graph->spaceship4, graph->screen);
  apply_surface((WIDTH/2) - 10, (HEIGHT/2) + 300,
		graph->exitmess, graph->screen);
  make_menu(graph);
  apply_surface((WIDTH/2) - 120, graph->pos + (100 * (graph->poscurs)
	       + 80), graph->character[graph->charac_num], graph->screen);
  my_flip(graph);
}

int		main(int argc, char **argv, char **env)
{
  t_graph	graph;
  
  argv[argc - 1] = argv[argc - 1];
  memset(&graph, 0, sizeof(t_graph));
  graph.env = env;
  if (init_SDL(&graph) == -1)
    fail_init();
  make_menu(&graph);
  my_flip(&graph);
  while (graph.quit == 0)
    {
      graph.current = SDL_GetTicks();
      if (graph.current > graph.next)
	currentNext(&graph);
      else
	SDL_Delay(20);
      graph.next = graph.current + 20;
    }
  quit_SDL(&graph);
  return (0);
}
