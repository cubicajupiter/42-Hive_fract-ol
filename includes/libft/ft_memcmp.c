/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:29:16 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 11:43:58 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*temp_s1;
	char		*temp_s2;

	temp_s1 = (char *) s1;
	temp_s2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return ((unsigned char) temp_s1[i] - (unsigned char) temp_s2[i]);
		i++;
	}
	return (0);
}
