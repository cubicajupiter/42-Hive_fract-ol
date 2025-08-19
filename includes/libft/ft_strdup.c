/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:18:56 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 11:38:06 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*copy;

	i = 0;
	len = ft_strlen(s);
	copy = (char *) malloc(len + 1);
	if (!copy)
		return (NULL);
	while (*s != '\0')
	{
		copy[i] = *(s)++;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
