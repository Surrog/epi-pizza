/*
** concatene_msg_view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:18:55 2010 pierre1 boutbel
** Last update Mon Apr 19 18:52:25 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

char		*add_player(t_vision *cur_case, char *msg)
{
  t_list	*cur_player;
  int		flag;
  int		i;

  i = -1;
  flag = 0;
  while (++i != RESS_NUM)
    if (cur_case->cas->cas.ress[i] != 0)
      flag = 1;
  cur_player = cur_case->cas->cas.player;
  while (cur_player->data != NULL)
    {
      msg = xrealloc(msg, strlen(msg) + strlen(MSG_JOUEUR));
      if (flag == 1)
	snprintf(msg, strlen(msg) + strlen(MSG_JOUEUR) + 3, "%s%s ", msg, 
		 MSG_JOUEUR);
      else
	snprintf(msg, strlen(msg) + strlen(MSG_JOUEUR) + 3, "%s%s", msg, 
		 MSG_JOUEUR);	
      cur_player = cur_player->next;
    }
  return (msg);
}

static int	find_last_ress(t_case cas)
{
  int		i;
  
  printf("Calcul de ressource\n");

  i = RESS_NUM - 1;

  /*  printf("On a i = %i et : %i \n", i, cas.ress[i]); 
   */

  while (cas.ress[i] == 0 && i != -1)
    {

      /*      printf("Ress : %i - val %i\n", i, cas.ress[i]);
       */

      i--;
    }
  if (cas.ress[RESS_NUM - 1] != 0 || i == -1)
    return (RESS_NUM - 1);
  else 
    return (i);
}

char		*add_ressource(t_vision *cur_case, char *msg)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
  int		num_ress;
  int		nb_ress;


  int		i = -1;

  puts("");

  /*
  printf("Last ress : %i\n", find_last_ress(cur_case->cas->cas));
  while (++i != RESS_NUM)
    printf("%i %s : %i\n", i, msg_ress[i], cur_case->cas->cas.ress[i]);
  */

  num_ress = -1;
  while (++num_ress != RESS_NUM)
    {
      

     nb_ress = cur_case->cas->cas.ress[num_ress] + 1;
      while (--nb_ress >= 2)
	{
	  msg = xrealloc(msg, strlen(msg) + strlen(msg_ress[num_ress]) + 2);
	  snprintf(msg, strlen(msg) + 14, "%s%s ", msg, msg_ress[num_ress]);
	}
      msg = xrealloc(msg, strlen(msg) + strlen(msg_ress[num_ress]) + 2);


      if (nb_ress != 0)
	{
	  if (num_ress == find_last_ress(cur_case->cas->cas))
	    snprintf(msg, strlen(msg) + 14, "%s%s", msg, msg_ress[num_ress]);
	  else
	    snprintf(msg, strlen(msg) + 14, "%s%s ", msg, msg_ress[num_ress]);
	}	
    }

  puts("");

  return (msg);
}

char		*explore_case(t_vision *cur_case, char *msg)
{  
  int		i;

  if (cur_case->cas->cas.player != NULL)
    msg = add_player(cur_case, msg);
  msg = add_ressource(cur_case, msg);


  printf("next : %p\n", cur_case->next);

  
  if (cur_case->next == NULL)
    {
      puts("**********************************");
      msg = xrealloc(msg, strlen(msg) + 1);
      msg = strcat(msg, ",");
    }

  if (cur_case->next != NULL)
    {
      i = -1;      
      while (++i != RESS_NUM)
	if (cur_case->next->cas->cas.ress[i] != 0)
	  break;

      printf("i : %i, next->player %p\n", i, cur_case->next->cas->cas.player);

      if (i == RESS_NUM)
	{
	  puts("444444444444444444444444444444444444");
	  msg = xrealloc(msg, strlen(msg) + 1);
	  msg = strcat(msg, ",");
	}
      else
	{
	  puts("2322222222222222222222222222222");
	  msg = xrealloc(msg, strlen(msg) + 2);
	    msg = strcat(msg, ", ");
	}
    }
  return (msg);
}

char		*concatene_msg(t_vision *list)
{
  char		*msg;
  t_vision	*cur;
  int		len;

  cur = list;
  msg = xmalloc(2 * sizeof(char));
  msg[0] = '{';
  msg[1] = '\0';
  while (cur != NULL)
    {
      msg = explore_case(cur, msg);
      cur = cur->next;
    }
  msg = xrealloc(msg, strlen(msg) + 3);
  len = strlen(msg);
  msg[len - 1] = '}';
  msg[len] = '\n';
  msg[len + 1] = '\0';
  return (msg);
}
