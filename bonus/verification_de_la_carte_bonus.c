/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carte_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:46:55 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/15 14:50:42 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*	valid.count: un compteur.
 *	valid.len: le nombre de caractère sur la ligne.
 *	valid.fd: file descriptor.
 *	valid.y: le nombre de chaine de caractère.
 *	valid.e: le nombre de 'E'. (sortie)
 *	valid.p: le nombre de 'P'. (personnage)
 *	valid.c: le nombre de 'C'. (collectible)					*/
t_valid	init_valid(void)
{
	t_valid	valid;

	valid.count = 0;
	valid.fd = 0;
	valid.e = 0;
	valid.p = 0;
	valid.c = 0;
	return (valid);
}

/*	Vérification que la carte est bien '.ber'.
 *	Vérification que 'fd' existe bien.
 *	Vérification qu'il n'y ai que des '1' sur la première ligne.
 *	Vérification suite...								*/
int	verification_carte(char *carte)
{
	t_valid	valid;

	valid = init_valid();
	valid.carte = ft_strtrim(carte, " ");
	if (carte_ber(carte) == 0)
		return (quit(valid.fd, valid.carte));
	valid.fd = open(valid.carte, O_RDONLY);
	if (valid.fd == -1)
		return (quit(valid.fd, valid.carte));
	free(valid.carte);
	if (true)
	{
		valid.carte = prochaine_ligne(NULL, valid.fd);
		while (valid.carte[valid.count])
			if (valid.carte[valid.count++] != '1')
				return (quit(valid.fd, valid.carte));
		valid.len = ft_strlen(valid.carte);
		if (valid.len > 100)
			return (quit(valid.fd, valid.carte));
		if (verification_suite(valid.carte, valid.fd, valid.len) == 0)
			return (0);
		return (1);
	}
	close(valid.fd);
	return (1);
}

/*	Vérification du premier et dernier caractère pour qu'il soit
 *	obligatoirement un '1'.
 *	Vérification du nombre de 'E' et de 'P'.
 *	Vérification du nombre de 'C'.
 *	Vérification des conditions min/max pour 'E' 'P' 'C'			*/
int	verification_suite(char *carte, int fd, size_t len)
{
	t_valid	valid;

	valid = init_valid();
	while (carte != NULL)
	{
		if (carte[0] != '1' || carte[len - 1] != '1')
			return (quit(fd, carte));
		valid.count = 0;
		while (carte[valid.count])
			if (e_p(carte, &valid.count, &valid.e, &valid.p) == 0)
				return (quit(fd, carte));
		valid.count = 0;
		while (carte[valid.count])
			if (c(carte, &valid.count, &valid.c) == 0)
				return (quit(fd, carte));
		carte = prochaine_ligne(carte, fd);
	}
	if (valid.e != 1 || valid.p != 1 || valid.c < 1)
		return (quit(fd, carte));
	return (1);
}

/*	Additionne le nombre de 'E' et le nombre de 'P'.				*/
int	e_p(char *carte, int *count, int *e, int *p)
{
	if (carte[*count] == '0' || carte[*count] == '1'
		|| carte[*count] == 'C' || carte[*count] == 'E'
		|| carte[*count] == 'P' || carte[*count] == 'X')
	{
		if (carte[*count] == 'E')
			(*e)++;
		else if (carte[*count] == 'P')
			(*p)++;
		(*count)++;
		return (true);
	}
	else
		return (false);
}

/*	Additionne le nombre de 'C'. (collectible)					*/
int	c(char *carte, int *count, int *c)
{
	if (carte[*count] == '0' || carte[*count] == '1'
		|| carte[*count] == 'C' || carte[*count] == 'E'
		|| carte[*count] == 'P' || carte[*count] == 'X')
	{
		if (carte[*count] == 'C')
			(*c)++;
		(*count)++;
		return (true);
	}
	else
		return (false);
}
