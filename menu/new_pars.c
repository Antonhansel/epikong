/*
** new_pars.c for verifs in /home/apollo/rendu/testpull/GAME
** 
** Made by ribeaud antonin
** Login   <ribeau_a@epitech.net>
** 
** Started on  Sun Mar  9 14:25:02 2014 ribeaud antonin
** Last update Sun Mar  9 20:00:45 2014 ribeaud antonin
*/

#include  "graphics.h"

void		check_map(char *map)
{
  static size_t	maxsize = 0;
  static int	line = 0;
  static int	i = 0;

  if (line == 0)
    {
      line++;
      maxsize = strlen(map);
      check_w(map, line);
    }
  else
    {
      i += check_entry(map);
      if (i > 1)
	error(line, "Wrong entry number");
      if (strlen(map) != maxsize)
	error(line, "Wrong line size");
      check_chars(map, line);
      line++;
    }
}

void		check_num(char c)
{
  if (c >= 48 && c <= 57)
    c = 1;
  else
    error(1, "Wrong file format");
}

void		check_filename(char *path)
{
  int		i;

  i = 0;
  if (strstr(path, ".map") != NULL)
    {
      while (path[i] != '\0')
	i++;
      while (path[i] != '.')
	i--;
      i--;
      check_num(path[i]);
      check_num(path[i--]);
    }
  else
    error(1, "Wrong filename format");
}

int		check_pFile(FILE *pFile)
{
  if (pFile == NULL)
    error(1, "Error on pFile");
  return (0);
}

int		Load_map(char *path0)
{
  size_t	toto;
  FILE		*pFile;
  int		n;
  char		*buffer;
  char		**map;

  check_filename(path0);
  pFile = fopen(path0, "r");
  n = check_pFile(pFile);
  buffer = NULL;
  toto = 4096;
  map = xmalloc(sizeof(char *));
  while (getline(&buffer, &toto, pFile) != -1)
    {
      map = realloc(map, sizeof(char *) * (n + 2));
      map[n + 1] = NULL;
      map[n] = strdup(buffer);
      map[n][strlen(map[n]) - 1] = 0;
      check_map(map[n]);
      map[n][strlen(map[n]) - 1] = 0;
      n++;
      buffer = NULL;
    }
  check_w(map[n - 1], n);
  return (0);
}
