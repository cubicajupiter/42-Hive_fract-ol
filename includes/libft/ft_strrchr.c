/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:55:04 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 12:20:30 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	cc;
	int		i;

	i = 0;
	ptr = 0;
	cc = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			ptr = (char *) s + i;
		i++;
	}
	if (cc == '\0')
		return ((char *) s + i);
	return (ptr);
}
