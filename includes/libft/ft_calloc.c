/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:04:55 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 12:01:46 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*space;
	size_t			total;

	total = nmemb * size;
	if (nmemb > 0 && size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	space = malloc(total);
	if (!space)
		return (NULL);
	ft_memset(space, 0, total);
	return (space);
}
