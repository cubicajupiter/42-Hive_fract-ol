/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:29:10 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 11:20:47 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (*s == cc)
		return ((char *) s);
	return (NULL);
}
