/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:21:44 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 13:35:53 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = (char *) dest;
	temp_src = (char *) src;
	if (temp_dest > temp_src)
	{
		while (n > 0)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	else
	{
		while ((size_t)(temp_dest - (char *)dest) < n)
			*temp_dest++ = *temp_src++;
	}
	return (dest);
}
