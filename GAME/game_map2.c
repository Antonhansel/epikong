/*
** game_map2.c for game_map2 in /home/apollo/rendu/T2Rush1/etape_1
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 18:40:07 2014 ribeaud antonin
** Last update Sun Mar  9 21:29:25 2014 ribeaud antonin
*/

#include "game_data.h"

void		check_path(char *path0)
{
  if (path0 == NULL)
    error(1, "Error on opening path");
}

void		error(int line, char *str)
{
  printf("Error on line %i %s\n", line++, str);
  exit(1);
}
