/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:51:39 by jvalkama          #+#    #+#             */
/*   Updated: 2025/05/04 12:02:55 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	i = 0;
	j = len - 1;
	while (ft_strchr(set, s1[i]) && i < len)
		i++;
	while (ft_strchr(set, s1[j]) && i < j)
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
