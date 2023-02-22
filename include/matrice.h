/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:25:25 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/22 01:05:56 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

# include <stdbool.h>

typedef	struct	s_matrice
{
	float   mat[4][4];
	float	tri_d[3][3];
	float	two_d[2][2];
}t_matrice;

/*---bullshish*/
void		tab_init(float tab[4][4]);
void		tab_init_1(float tab[4][4]);
// print
void		matrice_show(t_matrice show);

// matrice init
t_matrice	matrice_init(float a[4][4]);
// equality
bool		matrice_equal(t_matrice a, t_matrice b);
// multiplication
t_matrice	matrices_multiplication(t_matrice a, t_matrice b);
t_tuple		matrice_tuple_multiplication(t_matrice mat, t_tuple tup);
// identity
t_matrice	matrice_identity(void);
// transpose
t_matrice	matrice_transpose(t_matrice mat);
// inverting

#endif // MATRICE_H