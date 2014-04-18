/*
** new_pars3.c for new_pars in /home/apollo/rendu/T2Rush1/etape_1
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 18:52:35 2014 ribeaud antonin
** Last update Sun Mar  9 18:56:49 2014 ribeaud antonin
*/

#include "graphics.h"

int	check_entry(char *map)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (map[i] != '\0')
    {
      if (map[i] == 'i')
	count++;
      i++;
    }
  return (count);
}
