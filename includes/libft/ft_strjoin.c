/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:51:23 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 12:05:53 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (*s1)
	{
		*(newstr)++ = *(s1)++;
	}
	while (*s2)
	{
		*(newstr)++ = *(s2)++;
	}
	*newstr = '\0';
	return (newstr - (s1_len + s2_len));
}
