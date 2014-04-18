/*
** game_Init.c for game in /home/apollo/rendu
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 23:09:19 2014 ribeaud antonin
** Last update Sun Mar  9 23:19:35 2014 ribeaud antonin
*/

#include <string.h>
#include "game_data.h"

int	Init_music(t_data *data)
{
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 0, 4096))
    return (-1);
  data->intro_m = Mix_LoadMUS("music/intro.mp3");
  if (data->intro_m == NULL)
    return (-1);
  Mix_PlayMusic(data->intro_m, -1);
  return (0);
}

int	Init_graphic(t_data *data)
{
  if (SDL_Init(SDL_INIT_VIDEO))
    return (1);
  GRAPHICS.screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE
				     | SDL_FULLSCREEN);
  if (GRAPHICS.screen == NULL)
    return (1);
  GRAPHICS.background = IMG_Load("img/space.bmp");
  if (GRAPHICS.background == NULL)
    return (1);
  return (0);
}

int	Init_charac(t_data *data)
{
  CHARAC.lives = 3;
  CHARAC.ammos = 0;
  return (0);
}

int	Init_sprite(t_data *data)
{
  fill_elem(&(SPRITES.charac_left), "img/hero5/walk_1L.png");
  fill_elem(&(SPRITES.charac_right), "img/hero5/walk_1.png");
  fill_elem(&(SPRITES.charac_climb), "img/hero5/climb_1.png");
  fill_elem(&(SPRITES.charac_jump), "img/hero5/jump_1.png");
  fill_elem(&(SPRITES.ground1), "img/background/wall1.png");
  fill_elem(&(SPRITES.ground2), "img/background/wall2.png");
  fill_elem(&(SPRITES.ground3), "img/background/wall3.png");
  fill_elem(&(SPRITES.ground4), "img/background/wall4.png");
  fill_elem(&(SPRITES.ground5), "img/background/wall5.png");
  fill_elem(&(SPRITES.ground6), "img/background/box.png");
  fill_elem(&(SPRITES.ground7), "img/background/ladder.png");
  fill_elem(&(SPRITES.bomb1), "img/M/obj_bomb1_003.png");
  CHARAC.current = SPRITES.charac_left->image;
  return (0);
}

int	Init_data(t_data *data)
{
  memset(data, 0, sizeof(t_data));
  printf("Loading SDL... ");
  if (Init_graphic(data))
    return (1);
  printf("done !\n");
  printf("Loading ressources... ");
  if (Init_sprite(data))
    return (1);
  printf("done !\n");
  printf("Initializing data... ");
  if (Init_charac(data))
    return (1);
  if (Init_music(data))
    return (1);
  printf("done !\n");
  atexit(endgame);
  return (0);
}
