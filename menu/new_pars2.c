/*
** new_pars2.c for new_pars2.c in /home/apollo/rendu/T2Rush1/menu
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 15:49:06 2014 ribeaud antonin
** Last update Sun Mar  9 21:29:47 2014 ribeaud antonin
*/

#include  "graphics.h"

void		error(int line, char *str)
{
  printf("Error on line %i %s\n", line++, str);
  exit(1);
}

void		check_w(char *map, int line)
{
  int		i;

  i = 0;
  while (map[i] != '\0')
    {
      if (map[i] != 'w')
	error(line, "First line must be made of W");
      i++;
    }
}

void		check_chars(char *map, int line)
{
  size_t       	i;

  i = 0;
  while (map[i] != '\0')
    {
      if (i == 0)
	{
	  if (map[i] != 'w')
	    error(line, "Line must start with a W");
	}
      else if (map[i] != 'w' && map[i] != '.' && map[i] != ' ' &&
	  map[i] != 'm' && map[i] != 's' && map[i] != 'o'
	  && map[i] != 'i' && map[i] != 'k' && map[i] != 'm')
	error(line, "Wrong map format");
      i++;
    }
  if (map[i - 1] != 'w')
    error(line, "Line must end with a W");
}

void		check_path(char *path0)
{
  if (path0 == NULL)
    error(1, "Error on opening path");
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
