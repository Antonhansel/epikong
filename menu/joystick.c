/*
** joystick.c for joystick in /home/apollo/rendu/T2Rush1/menu
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 12:47:08 2014 ribeaud antonin
** Last update Thu Mar 20 15:13:57 2014 ribeaud antonin
*/

#include "graphics.h"

void			init_joystick(t_graph *graph)
{
  int			fd;

  fd = open("/dev/input/js0", O_NONBLOCK);
  if (fd > 0)
    graph->fd = fd;
  else
    {
      printf("Unable to detect joystick\n");
      graph->fd = -1;
    }
}

void			update_joystick(t_graph *graph)
{
  struct js_event	e;

  if (graph->fd > 0)
    {
      while (read(graph->fd, &e, sizeof(struct js_event)) > 0)
	{
	  if (e.number == 1)
	    {
	      if (e.value > 500)
		{
		  graph->spacefactor = e.value % 20;
		  if (graph->spacefactor == 0)
		    graph->spacefactor = 1;
		}
	      if (e.value < -1000)
		{
		  graph->spacefactor = e.value % 20;
		  if ( graph->spacefactor == 0)
		    graph->spacefactor = 1;
		}
	    }
	}
    }
}
