/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:10 2010 francois1 ancel
** Last update Sat Apr 10 18:46:07 2010 pierre1 boutbel
*/

#ifndef DEFINE_INCLUDED
# define DEFINE_INCLUDED

# define INCANT_NUM	7

# define RESS_NUM	7
# define MAX_RESS	(8)

# define MAP_SIZ	8

# define M_CARD		(8)

enum {DIR_N, DIR_E, DIR_S, DIR_O};
enum {M_E, M_NE, M_N, M_NO, M_O, M_SO, M_S, M_SE};

# define MSG_JOUEUR	"joueur"
# define MSG_RESS	"linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"

# define OK		"OK"
# define KO		"KO"
# define ELEV_OK	"elevation en cours"
# define ELEV_DONE	"niveau actuel : K"
# define LEN_ELEV	17
# define POS_ELEV_K	16	
# define EXPULSE_VIC	"deplacement K\n"
# define LEN_EXP	14
# define POS_EXP_K	12

#endif