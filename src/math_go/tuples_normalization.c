/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_normalization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:18:41 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/10 21:48:04 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_tuple	nrml(t_tuple tup)
{
	t_tuple	normal;
	float	mag;

	mag = magnitude(tup);
	normal.x = tup.x / mag;
	normal.y = tup.y / mag;
	normal.z = tup.z / mag;
	normal.w = tup.w / mag;
	return (normal);
}