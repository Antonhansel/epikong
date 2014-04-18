##
## Makefile for makefile in /home/apollo/rendu/rush-epikong
## 
## Made by ribeaud antonin
## Login   <ribeau_a@epitech.net>
## 
## Started on  Sat Mar  8 10:12:42 2014 ribeaud antonin
## Last update Sun Mar  9 22:13:20 2014 Roussille Hector
##

NAME		=	epikong

NAME_GAME	=	game

SRCS_GAME	=	GAME/blit_map.c \
			GAME/fill_elem.c \
			GAME/game_Init.c \
			GAME/game_launch.c \
			GAME/game_main.c \
			GAME/game_map.c \
			GAME/blit_map2.c \
			GAME/game_map2.c \
			GAME/game_move.c \
			GAME/end.c \
			GAME/game_monsters.c \

SRCS		=	menu/main.c \
			menu/init_graphics.c \
			menu/core_funcs.c \
			menu/menu_funcs.c \
			menu/menu_funcs2.c \
			menu/spaceship.c \
			menu/joystick.c \
			menu/handle.c \
			menu/new_pars2.c \
			menu/new_pars3.c \
			menu/new_pars.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_GAME	=	$(SRCS_GAME:.c=.o)

CFLAGS		+=	-lSDL -lSDL_mixer -g -lSDL_image -lSDL_ttf -W -Wall -Wextra -Werror

all		:	$(NAME) $(NAME_GAME)

$(NAME_GAME)	:	$(OBJS_GAME)
			gcc $(OBJS_GAME) $(CFLAGS) -o $(NAME_GAME)

$(NAME)		:	$(OBJS)
			gcc $(OBJS) $(CFLAGS) -o $(NAME)

clean		:
			rm -f $(OBJS) $(OBJS_GAME)

fclean		:	clean
			rm -f $(NAME) $(NAME_GAME)

re		:	fclean all

.PHONY		:	all clean fclean re
