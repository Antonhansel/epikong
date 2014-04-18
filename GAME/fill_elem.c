/*
** fill_elem.c for fill_elem.c in /home/roussi_h/rendu/T2Rush1
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 18:46:59 2014 Roussille Hector
** Last update Sat Mar  8 20:14:14 2014 Roussille Hector
*/

#include "game_data.h"

int	fill_elem(t_Elem **to_fill, char *path)
{
  *to_fill = malloc(sizeof(t_Elem));
  if (*to_fill == NULL)
    return (1);
  (*to_fill)->next = NULL;
  (*to_fill)->image = IMG_Load(path);
  if ((*to_fill)->image == NULL)
    {
      printf("wrong path");
      exit(0);
    }
  return (0);
}
