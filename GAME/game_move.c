/*
** game_move.c for move in /home/roussi_h/T2Rush1/etape_2/etape_1/GAME
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sun Mar  9 17:53:15 2014 Roussille Hector
** Last update Sun Mar  9 23:14:26 2014 Roussille Hector
*/

#include "game_data.h"

int	check_xm1(t_data *data, int movement)
{
  if ((GRAPHICS.map[(CHARAC.pos.y) / 64 ][(CHARAC.pos.x)/ 64] == ' '
       || GRAPHICS.map[(CHARAC.pos.y) / 64 ]
       [CHARAC.pos.x / 64] == '.')
      && GRAPHICS.map[(CHARAC.pos.y + movement) / 64]
      [(CHARAC.pos.x) / 64] != 'w'
      && GRAPHICS.map[(CHARAC.pos.y + 64) / 64]
      [(CHARAC.pos.x) / 64] == 'w')
    return (1);
  return (0);
}

void	check_movement(t_data *data, int movement)
{
  if (movement > 0)
    {
      if (GRAPHICS.map[(CHARAC.pos.y + 64) / 64 ][CHARAC.pos.x / 64] == 's'
	  ||GRAPHICS.map[(CHARAC.pos.y + 64) / 64 ][CHARAC.pos.x / 64] == 'm'
	  ||GRAPHICS.map[(CHARAC.pos.y + 64) / 64 ][CHARAC.pos.x / 64] == ' '
	  ||GRAPHICS.map[(CHARAC.pos.y + 64) / 64 ][CHARAC.pos.x / 64] == '.')
	CHARAC.pos.y += movement;
    }
  else
    {
      if (GRAPHICS.map[(CHARAC.pos.y) / 64 ][CHARAC.pos.x / 64] == 's'
  && GRAPHICS.map[(CHARAC.pos.y + movement) / 64][CHARAC.pos.x / 64] != 'w')
	CHARAC.pos.y += movement;
    }
}

void	move(t_data *data, int x, int movement)
{
  if (x == -1)
    {
      if (data->event_data.events[SDLK_LEFT] ||
	  data->event_data.events[SDLK_RIGHT])
	movement /= 2;
      if (check_xm1(data, movement))
	  CHARAC.pos.y += movement;
    }
  if (x == 1)
    {
      if (GRAPHICS.map[CHARAC.pos.y / 64]
	  [(CHARAC.pos.x + movement) / 64] != 'w')
	CHARAC.pos.x += movement;
    }
  else
    check_movement(data, movement);
}

void	gravity(t_data *data)
{
  int	gravity;

  gravity = 0;
  if (GRAPHICS.map[(CHARAC.pos.y + 64) / 64][CHARAC.pos.x / 64] == ' '
      || GRAPHICS.map[(CHARAC.pos.y + 64) / 64][CHARAC.pos.x / 64] == '.')
    {
      if (CHARAC.gravity == 1)
	CHARAC.gravity = 2;
      else if (CHARAC.gravity)
	CHARAC.gravity *= CHARAC.gravity;
      else
	CHARAC.gravity = 1;
    }
  else
      CHARAC.gravity = 0;
  while (gravity < CHARAC.gravity)
    {
   	move(data, 0, 64);
	gravity++;
    }
}

void	check_exit(t_data *data)
{
  if (GRAPHICS.map[(CHARAC.pos.y + 32) / 64][(CHARAC.pos.x + 32) / 64] == 'o')
    exit(0);
}
