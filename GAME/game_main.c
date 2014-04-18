/*
** game_main.c for game_main in /home/roussi_h/rendu/T2Rush1
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 18:26:26 2014 Roussille Hector
** Last update Sun Mar  9 22:12:14 2014 Roussille Hector
*/

#include "game_data.h"

int		main(int argc, char **argv)
{
  t_data	data;

  argc = argc;
  if (Init_data(&data))
    return (1);
  if (Load_Map(&data, argv[0]))
    return (1);
  make_monsters(&data);
  if (Launch_Game(&data))
    return (1);
  return (0);
}
