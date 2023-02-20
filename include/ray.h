/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:25:36 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/19 05:00:26 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>

# include "tuple.h"
# include "types.h"
# include "canvas.h"
# include "matrice.h"

#define EPSILON 0.00001
typedef struct s_vars
{
    void    *mlx;
    void    *win;
}t_vars;

    // utils
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
#endif // RAY_H