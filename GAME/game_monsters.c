/*
** game_monsters.c for test in /home/roussi_h/T2Rush1/etape_2/GAME
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sun Mar  9 21:57:52 2014 Roussille Hector
** Last update Sun Mar  9 23:07:47 2014 ribeaud antonin
*/

#include "game_data.h"

void		add_monster(t_data *data, int x, int y)
{
  t_Elem	*tmp;
  t_Elem	*tmp2;

  tmp = malloc(sizeof(t_Elem));
  if (tmp == NULL)
    error(1, "error while mallocing");
  tmp->image = SPRITES.bomb1->image;
  tmp->x = x * 64;
  tmp->y = y * 64;
  tmp->timer = SDL_GetTicks();
  tmp->next = NULL;
  tmp->direction = -1;
  tmp2 = data->monsters;
  while (tmp2 && tmp2->next)
    tmp2 = tmp2->next;
  if (tmp2 == NULL)
    data->monsters = tmp;
  else
    tmp2->next = tmp;
}

void		make_monsters(t_data *data)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (GRAPHICS.map[y])
    {
      while (GRAPHICS.map[y][x])
	{
	  if (GRAPHICS.map[y][x] == 'm')
	    add_monster(data, x, y);
	  x++;
	}
      y++;
      x = 0;
    }
}

void		check_move(t_data *data, t_Elem *tmp)
{
  if ((GRAPHICS.map[(tmp->y + 64)/ 64][(tmp->x + (64 *
			  (tmp->direction))) / 64] != 'w'
       && GRAPHICS.map[(tmp->y + 64)/ 64][(tmp->x + (64 *
			  (tmp->direction))) / 64] != 's')
      || GRAPHICS.map[(tmp->y + 32)/ 64][(tmp->x + (64 *
			  (tmp->direction))) / 64] == 'w')
    {
      if (tmp->direction == 1)
	tmp->direction = -1;
      else
	tmp->direction = 1;
    }
}

void		move_monsters(t_data *data)
{
  t_Elem	*tmp;

  tmp = data->monsters;
  while (tmp)
    {
      if (SDL_GetTicks() - tmp->timer >= 150)
	{
	  check_move(data, tmp);
	  tmp->x += (tmp->direction * 64);
	  tmp->timer = SDL_GetTicks();
	}
      tmp = tmp->next;
    }
}

void		blit_monsters(t_data *data)
{
  t_Elem	*tmp;
  SDL_Rect	pos;

  tmp = data->monsters;
  while (tmp)
    {
      pos.x = tmp->x - data->xscroll;
      pos.y = tmp->y - data->yscroll;
      SDL_BlitSurface(SPRITES.bomb1->image, NULL, GRAPHICS.screen, &pos);
      tmp = tmp->next;
    }
  move_monsters(data);
}
