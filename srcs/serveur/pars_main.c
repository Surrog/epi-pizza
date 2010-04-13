/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Tue Apr 13 13:22:26 2010 Florian Chanioux
*/

#include		<string.h>
#include		<unistd.h>
#include		<stdlib.h>

#include		"my_list.h"
#include		"define.h"
#include		"pars_option.h"
#include		"t_struct.h"

void			free_opt(t_opt *opt)
{
  int			i;

  i = 0;
  while (i < 6)
    free(opt[i++].option);
  free(opt);
}

void			puterr(char *str, int quit)
{
  if (write(2, str, strlen(str)) == -1 || quit == 1)
    exit(EXIT_FAILURE);
}

t_opt			*parser(int ac, char **av)
{
  t_opt			*opt;
  t_team		*team;
  int			i;
  
  i = 0;
  if ((team = malloc(sizeof(*team))) == NULL)
    puterr("Unable to malloc", 1);
  team->next = 0;
  if ((opt = malloc(7 * sizeof(*opt))) == NULL)
    puterr("Unable to malloc", 1);
  init_opt(opt, team);
  parse_option(opt, ac, av);
  return (opt);
}

void			fill_server(t_opt *opt, t_server *server)
{
  server->port = opt[0].value;
  server->height = opt[1].value;
  server->width = opt[2].value;
  server->teamname = opt[3].team;
  server->nb_client = opt[4].value;
  server->delay = opt[5].value;
}

void			check(int ac, char **av, t_server *server)
{
  t_opt			*opt;
  t_team		*team;
  
  opt = parser(ac, av);
  fill_server(opt, server);
  team = server->teamname;
  if (server->width == 0 || server->height == 0)
    {
      puterr("\n\033[1mWidth/Height must be superior to 0\033[m\n\n", 0);
      put_usage(" -y/-x");
    }
  display_values(server, team);
  free_opt(opt);
}