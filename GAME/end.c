/*
** end.c for end in /home/apollo/rendu/T2Rush1/etape_2/GAME
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 21:13:03 2014 ribeaud antonin
** Last update Sun Mar  9 21:18:03 2014 ribeaud antonin
*/

#include "game_data.h"

void	endgame()
{
  SDL_Quit();
  execl("./epikong", "", NULL);
}
