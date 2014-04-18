/*
** game_map.c for game_map in /home/roussi_h/rendu/T2Rush1/GAME
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 19:01:15 2014 Roussille Hector
** Last update Sun Mar  9 23:33:54 2014 ribeaud antonin
*/

#include <errno.h>
#include "game_data.h"

void		get_enter(t_data *data)
{
  unsigned int	x;
  unsigned int	y;

  x = 0;
  y = 0;
  while (GRAPHICS.map[y])
    {
      while (GRAPHICS.map[y][x])
	{
	  if (GRAPHICS.map[y][x] == 'i')
	    {
	      CHARAC.pos.x = x * 64;
	      CHARAC.pos.y = y * 64;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
}

int		get_tmp(t_data *data)
{
  int		sizex;
  int		sizey;

  sizex = 0;
  sizey = 0;
  while (GRAPHICS.map[sizey][sizex])
    sizex++;
  while (GRAPHICS.map[sizey])
    sizey++;
  data->mapx = sizex * 64;
  data->mapy = sizey * 64;
  get_enter(data);
  return (0);
}

void		*xmalloc(size_t size)
{
  void		*test;

  test = malloc(sizeof(size));
  if (test != NULL)
    return (test);
  else
    {
      printf("Malloc failed\n");
      exit(EXIT_FAILURE);
    }
}

int		check_pFile(FILE *pFile)
{
  if (pFile == NULL)
    error(1, "Error on pFile");
  return (0);
}

int		Load_Map(t_data *data, char *path0)
{
  size_t	toto;
  FILE *	pFile;
  int		n;
  char		*buffer;

  check_path(path0);
  pFile = fopen(path0, "r");
  n = check_pFile(pFile);
  buffer = NULL;
  toto = 4096;
  GRAPHICS.map = xmalloc(sizeof(char *));
  while (getline(&buffer, &toto, pFile) != -1)
    {
      if ((GRAPHICS.map = realloc(GRAPHICS.map,
	     sizeof(char *) * (n + 2))) == NULL)
	error(1, "Error on malloc");
      GRAPHICS.map[n + 1] = NULL;
      GRAPHICS.map[n] = strdup(buffer);
      GRAPHICS.map[n][strlen(GRAPHICS.map[n]) - 1] = 0;
      n++;
      buffer = NULL;
    }
  n = 0;
  return (get_tmp(data));
}
