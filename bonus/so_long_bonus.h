/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:01:08 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:25:32 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include "../include/libft/libft.h"
# include "../include/ft_printf/ft_printf.h"
# include "../include/get_next_line/get_next_line.h"

/*	verification_carte.c
 *	*carte: la carte passer en argument.
 *	count: un compteur.
 *	len: le nombre de caractère d'une chaine de caractère.
 *	fd: file descriptor.
 *	c: le nombre de 'C'. (collectible)
 *	e: le nombre de 'E'. (sortie)
 *	p: le nombre de 'P', (personnage)
 *	y: le nombre de chaine de caractère.						*/
typedef struct s_valid
{
	char	*carte;
	int		count;
	int		len;
	int		fd;
	int		c;
	int		e;
	int		p;
}	t_valid;

/*		Structure utilisé pour tout ce qui concerne la carte	*/
typedef struct s_carte
{
	char	pos[100][100];
	int		collectible;
	int		mouvement;
	int		largeur;
	int		hauteur;
	int		pos_x;
	int		pos_y;
	int		quit_x;
	int		quit_y;
}	t_carte;

/*		Structure utilisé pour tout ce qui concerne les images
 *		et le mlx/win	*/
typedef struct s_vars
{
	t_carte	*carte;
	void	*mlx;
	void	*win;
	void	*sprite;
	int		largeur;
	int		hauteur;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

enum {
	ON_DESTROY = 17
};

/*		DEPLACEMENT_DU_PERSONNAGE.C										*/
void	deplacement_du_personnage(t_vars *vars, int keycode);
void	emplacements_des_objets(t_vars vars, t_carte carte);
int		keyboard(int keycode, t_vars *vars);
int		bouton_pour_fermer_la_fenetre(void);
void	victoire(t_vars *vars);

/*		DEPLACEMENT_DU_PERSONNAGE_SUITE.C								*/
void	press_a(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte);
void	press_s(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte);
void	press_d(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte);
void	press_w(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte);
void	ouvert(t_vars vars, int largeur, int hauteur);

/*		IMAGES_BONUS.C													*/
void	objets(t_vars vars, int largeur, int hauteur);
void	sortie(t_vars vars, int largeur, int hauteur);
void	perso(t_vars vars, int largeur, int hauteur);
void	vide(t_vars vars, int largeur, int hauteur);
void	mur(t_vars vars, int largeur, int hauteur);

/*		IMAGES_SUITE_BONUS.C											*/
void	ennemie(t_vars vars, int largeur, int hauteur);
void	perdu(void);

/*		VERIFICATION_DE_LA_CARTE.C										*/
int		verification_carte(char *carte);
int		verification_suite(char *carte, int fd, size_t len);
int		e_p(char *carte, int *count, int *e, int *p);
int		c(char *carte, int *count, int *c);

/*		INITIALISATION_DE_LA_CARTE.C									*/
void	carte_initialisation(char *fichier, t_carte *carte);
void	carte_initialisation_second(int fd, t_carte *carte);
void	carte_initialisation_trois(t_carte *carte, int y, char *str);

/*		UTILS.C															*/
char	*prochaine_ligne(char *fichier, int fd);
int		quit(int fd, char *fichier);
int		carte_ber(char *carte);

#endif
