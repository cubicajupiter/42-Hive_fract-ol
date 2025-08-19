/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:42 by jvalkama          #+#    #+#             */
/*   Updated: 2025/08/19 13:10:10 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newitem)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = newitem;
	}
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = newitem;
	}
}
