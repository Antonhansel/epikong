/*
** game_data.h for game_data in /home/roussi_h/rendu/T2Rush1
** 
** Made by Roussille Hector
** Login   <roussi_h@epitech.net>
** 
** Started on  Sat Mar  8 18:27:34 2014 Roussille Hector
** Last update Sun Mar  9 23:17:02 2014 ribeaud antonin
*/

#ifndef _GAME_DATA_H_
# define _GAME_DATA_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_mixer.h>
# include <unistd.h>

#define  GRAPHICS data->graphic_data
#define  SPRITES  data->sprite_data
#define  CHARAC   data->charac_data
#define  EVENTS	  data->events_data

typedef struct	s_Elem
{
  SDL_Surface	*image;
  struct s_Elem *next;
  int		x;
  int		y;
  int		direction;
  Uint32	timer;
}		t_Elem;

typedef struct	s_SDL
{
  SDL_Surface	*screen;
  SDL_Surface	*background;
  char		**map;
}		t_SDL;

typedef struct	s_Sprite
{
  t_Elem	*charac_left;
  t_Elem	*charac_right;
  t_Elem	*charac_climb;
  t_Elem	*charac_jump;

  t_Elem	*bomb1;
  t_Elem	*bomb2;
  t_Elem	*bomb3;
  t_Elem	*bomb4;

  t_Elem	*ground1;
  t_Elem	*ground2;
  t_Elem	*ground3;
  t_Elem	*ground4;
  t_Elem	*ground5;
  t_Elem	*ground6;
  t_Elem	*ground7;

}		t_Sprite;

typedef struct	s_Character
{
  SDL_Surface * current;
  SDL_Rect	pos;
  int		lives;
  int		gravity;
  int		ammos;
}		t_Character;

typedef struct	s_Event
{
  SDL_Event     event;
  char		events[SDLK_LAST];
  int		quit;
}		t_Event;

typedef struct	s_data
{
  t_SDL		graphic_data;
  t_Sprite	sprite_data;
  t_Character	charac_data;
  t_Event	event_data;
  int		xscroll;
  int		yscroll;
  int		mapx;
  int		mapy;
  Mix_Music	*intro_m;
  t_Elem	*monsters;
}		t_data;

int		Init_music(t_data *data);
int		Init_data(t_data *data);
int		Init_graphic(t_data *data);
int		Init_sprite(t_data *data);
int		Init_charac(t_data *data);
int		Load_Map(t_data *data, char *path0);
int		fill_elem(t_Elem **to_fill, char *path);
void		move(t_data *data, int x, int movement);
void		getEvents(t_data *data);
void		handleEvents(t_data *data);
int		Launch_Game(t_data *data);
void		Blit_Charac(t_data *data, SDL_Rect pos);
void		gravity(t_data *data);
void		handleEvents2(t_data *data);
void		Blit_Charac(t_data *data, SDL_Rect pos);
void		Blit_map3(t_data *data, int i, int j, SDL_Rect Rect_dest);
void		Blit_map2(t_data *data, int i, int j);
void		*xmalloc(size_t size);
int		check_pFile(FILE *pFile);
void		check_path(char *path0);
int		check_xm1(t_data *data, int movement);
void		check_movement(t_data *data, int movement);
void		endgame();
void		Blit_Map(t_data *data);
void		error(int line, char *str);
void		get_enter(t_data *data);
void		check_exit(t_data *data);
void		check_move(t_data *data, t_Elem *tmp);
void		move_monsters(t_data *data);
void		blit_monsters(t_data *data);
void		make_monsters(t_data *data);
void		add_monster(t_data *data, int x, int y);

#endif /* !_GAME_DATA_H_ */
