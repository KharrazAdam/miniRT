/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_initialzer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:11:21 by akharraz          #+#    #+#             */
/*   Updated: 2023/02/20 03:46:47 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void    tuple_print(t_tuple sum)
{
	printf("x -> %f, y -> %f, z -> %f, w -> %f\n", sum.x, sum.y, sum.z, sum.w);
}

t_tuple	tuple_initializer(float x, float y, float z, float w)
{
	t_tuple	ret;
    int i;

    while (i < 4)
    {
        i++;
    }
	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = w;

    return ret;
}
