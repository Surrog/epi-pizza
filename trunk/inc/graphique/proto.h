/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 13:25:14 2010 Florian Chanioux
*/

#ifndef		__PROTO_H__
# define	__PROTO_H__

/* init */
void		init_game(t_game *game);
void		init_3dsmodel(t_game *game);
void		init_camera(t_game *game);
void		init_texture(t_game *game);
void		init_video(t_game *game);
void		initGL(t_game *game);
void		printAttributes();

/*circle*/
/* t_circle	*new_circ(int num); */
/* void		init_circ(t_game *game); */
/* char		*circle_get(t_serv *serv); */
/* void		circle_read(t_serv *serv); */

/* load */
SDL_Surface	*load_window();
SDL_Surface	*img_load(char *path);
GLuint		loadtexture(const char * filename);
/*GLuint		loadtexture(const char * filename,int useMipMap);*/

/* game func interation keybord/mouse */
int		interaction(t_game *game);
int		exit_func();

/* keyboad */
int		key_func(t_game *game);

/*mouse func*/
int		mouse_move(t_game *game);
int		mouse_up(t_game *game);
int		mouse_down(t_game *game);

void		picking_mouse(t_game *game, int x, int y);

/* camera */
void		reshape();
void		camera(t_game *game);

/* Draw */

void		DrawStr(const char *str);

void		timing();



void		mainloop(t_game *game);

void		draw_interface(t_game *game);

void		draw_gl(t_game *game, GLenum mode);
void		draw_map(t_game *game, GLenum mode);
void		draw_ressource(t_game *game, GLenum mode);


void            floor_picking(int x, int y);

void		draw_mob(t_game *game, GLenum mode);

void		clic_mob(t_game *game);
void		clic_map(t_game *game);

void		clic_render();

/* Draw (Call by CallList)*/

void		draw_mesh(obj_type *mesh);
void		floor_render(int x, int y, GLuint select);
void		around(int h, int w, GLuint texture);
void		interface_down(GLuint texture);
void		interface_up(GLuint texture);
void		side(int x, GLuint select);

/* CALLLIST */

void		make_calllistes_picking(t_game *game);
void		make_calllistes_trantorien(t_game *game);
void		make_calllistes_terrain(t_game *game);
void		make_calllistes_interface(t_game *game);

#endif