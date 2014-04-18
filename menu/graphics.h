/*
** graphics.h for graphics in /home/apollo/rendu/rush-epikong
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sat Mar  8 10:13:45 2014 ribeaud antonin
** Last update Wed Mar 12 16:28:50 2014 ribeaud antonin
*/

#ifndef _GRAPHICS_H_
# define _GRAPHICS_H_

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "SDL/SDL.h"
# include "SDL/SDL_mixer.h"
# include "SDL/SDL_ttf.h"
# include "SDL/SDL_image.h"
# include "/usr/include/linux/joystick.h"

#define	WIDTH	1920
#define HEIGHT	1080
#define BPP	32
#define NAME	"SpaceKong"

#define EVENT	graph->events.events

typedef struct	s_events
{
  char		events[SDLK_LAST];
  int		quit;
}		t_events;

typedef struct	s_graph
{
  char		**map;
  SDL_Surface	*background;
  SDL_Surface	*screen;
  SDL_Surface	*character[12];
  SDL_Surface	*maps;
  SDL_Surface	*spaceship1;
  SDL_Surface	*spaceship2;
  SDL_Surface	*spaceship3;
  SDL_Surface	*spaceship4;
  SDL_Surface	*exitmess;
  Mix_Music	*intro_m;
  Mix_Chunk	*button;
  int		quit;
  SDL_Event	event;
  SDL_Rect	clip[2];
  TTF_Font	*font;
  SDL_Color	Selected;
  SDL_Color	Standard;
  int		poscurs;
  Uint8		*keystates;
  int		ingame;
  t_events	events;
  Uint32	current;
  Uint32	next;
  int		pos;
  int		charac_num;
  int		spacepos1;
  int		spacepos2;
  int		spacepos3;
  int		spacepos4;
  int		spacefactor;
  int		fd;
  char		**env;
}		t_graph;

int		start_graph(t_graph *graph);
int		intro_music(t_graph *graph);
int		init_SDL(t_graph *graph);
void		quit_SDL(t_graph *graph);
void		set_null(t_graph *graph);
SDL_Surface	*load_image(char *filename);
void		apply_surface(int, int, SDL_Surface *, SDL_Surface *);
void		my_flip(t_graph *graph);
int		getEvent(t_graph *graph);
void		make_menu(t_graph *graph);
int		menu_up(t_graph *graph);
int		menu_down(t_graph *graph);
int		menu_quit(t_graph *graph);
int		menu_key(t_graph *graph);
int		apply_menu(t_graph *graph, int i);
void		start_game(t_graph *graph, char *argv);
void		set_mapsonmenu(t_graph *graph);
void		set_character(t_graph *graph);
void		update_joystick(t_graph *graph);
void		init_joystick();
void		move_spaceship(t_graph *graph);
void		fail_init();
void		handleReturn(t_graph *graph);
int		handleEvent(t_graph *graph);
void		currentNext(t_graph *graph);
void		put_image(t_graph *graph);
int		Load_map(char *path);
void		check_filename(char *path);
void		check_num(char c);
void		check_map(char *map);
void		error(int line, char *str);
void		check_w(char *map, int line);
void		check_chars(char *map, int line);
void		check_path(char *path0);
void		*xmalloc(size_t size);
int		check_entry(char *map);
void		init_joystick(t_graph *graph);

#endif /* !GRAPHICS_H_ */
